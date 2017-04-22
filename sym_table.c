// Name : Brenda So
// Date : 03/04/2017
// Goal : Make a symbol table that supports create, destroy, lookup and: insertion
// NOTE : what if i have a symbol that has a scope in itself? e.g. functions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sym_table.h"
struct scope_node* curr_scope; // the current scope is a global variable
extern int line_num;
int stack_offset;
int stat_count;
char* fname;
void inst_comm_directive(char* name, int size, int alignment);
// creates a symbol table, returns pointer to symbol table
void create_sym_table(char *name, int num){
    // create head node
    struct scope_node* header;
    char *sname, *c_fname;
    struct node* stmt_list;
    header = (struct scope_node*) malloc(sizeof(struct scope_node));
    header->prev_scope = curr_scope;
    header->sym_node = NULL;
    if (name != NULL){
        sname = (char *) malloc(strlen(name)*sizeof(char));
        strcpy(sname,name);
    }else{
        sname == NULL;
    }
    c_fname = (char *)malloc(strlen(fname)*sizeof(char));
    strcpy(c_fname, fname);
    header->line_num = line_num;
    if (num == 0){
        if (strcmp("global",name) == 0){
            header->scope_num = S_GLOBAL;
            header->line_num = 1;
        }else if (strcmp("block",name) == 0){
            header->scope_num = S_BLOCK;
        }else{
            header->scope_num = S_FUNCTION;
			// if it is a function, then reset the stack offset to 0
			stack_offset = 0;
        }
    }else{
        header->scope_num = S_STRUCTUNION;
    }
    header->name = sname;
    header->fname= c_fname;
    curr_scope = header;    // set current scope to header
}

// destroys a symbol table, returns 0 on success
void destroy_sym_table(){
    //recursively destroys all ast node
    struct sym_node* curr;
    struct scope_node* bedestroyed_scope;
    curr = curr_scope->sym_node;
    if (curr != NULL){
        while (curr->next != NULL){
            curr = curr->next;
            free(curr->prev);
        }
    }
    // destroy the scope node itself
    bedestroyed_scope = curr_scope;
    curr_scope = curr_scope->prev_scope;
    free(bedestroyed_scope);
}

// given a name and a namespace, look up for a symbol 
// returns node if it is found, else returns NULL
// the first and second argument specifies name and namespace respectively, 
struct sym_node* lookup(char* name, int namespace, int confine_to_current_scope){
    // search the current scope, go up the chain, 
    struct scope_node* search_scope;
    struct sym_node* search_sym, *existing_node;
    int nearest_scope = 0;
    search_scope = curr_scope;
    existing_node = NULL;
    // while we are not at the global scope yet!
    if (confine_to_current_scope == 1){
        
        if (namespace != N_TAGS){
            // if it is no a tag, then just confine to the current scope
            search_sym = search_scope->sym_node;
            while (search_sym != NULL){
                if (search_sym->sym_name != NULL){
                    if ((strcmp(search_sym->sym_name, name) == 0) && namespace == search_sym->nspace){
                        existing_node = search_sym;
                        return existing_node;
                    }
                }
                search_sym = search_sym->next;
            }
        }else{

            while (nearest_scope == 0 && search_scope != NULL){
                search_sym = search_scope->sym_node;
                while(search_sym != NULL){
                    if (search_sym->sym_name != NULL && (strcmp(search_sym->sym_name, name) == 0) && namespace == search_sym->nspace){
                        existing_node = search_sym;
                        return existing_node;
                    }
                    search_sym = search_sym->next;
                }
                if (search_scope->scope_num != S_STRUCTUNION){
                    nearest_scope = 1;
                }
                search_scope = search_scope->prev_scope;

            }
        }
    }else{

        while(search_scope != NULL){
            // go down the symbol table linked list
            search_sym = search_scope->sym_node;
            // go up the scope
            while (search_sym != NULL){
                if ((strcmp(search_sym->sym_name, name) == 0) && namespace == search_sym->nspace){
                    existing_node = search_sym;
                    return existing_node;
                }
                search_sym = search_sym->next;
            }
            search_scope = search_scope->prev_scope;
        }
    }
    return NULL;
}

// determine what the identifier is supposed to identify. This function can identify
// variables and functions
struct node* ident_var_type(struct node* ident_node, int* isExtern){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* n = ident_node->next;
    struct node* first_node = n;
    struct sym_node* next_node;
    int offset = 0;
    if (curr_scope->scope_num == S_STRUCTUNION){
        // if the current scope is within a struct and union, make it a member node
        new_node->ast_node.member_node.node = ident_node->ast_node.common_node;
        new_node->ast_node.member_node.offset = 0;
        new_node->ast_node.member_node.width = 0;
        new_node->ast_node.member_node.bit_offset = 0;
        new_node->flag = I_MEMBER_NODE;
       return new_node; 
    }

    while (n != NULL){
    if (n->flag == T_SCALAR_NODE){
        // if the next node is a variable node, change the node to a variable
        new_node->ast_node.var_node.node = ident_node->ast_node.common_node; 
        new_node->flag = I_VAR_NODE;
        if (n->ast_node.scalar_node.stg_class != 0){
            new_node->ast_node.var_node.stg = n->ast_node.scalar_node.stg_class;
			if (new_node->ast_node.var_node.stg == T_STATIC){
				/* */
			}if (new_node->ast_node.var_node.stg == T_EXTERN){
				*isExtern = 1;
			}else{
				*isExtern = 0;
			}
        }else{
            if (strcmp(curr_scope->name,"global") == 0){
                new_node->ast_node.var_node.stg = T_EXTERN;
            }else{
                new_node->ast_node.var_node.stg = T_AUTO;
            }
			*isExtern = 0;
        }
        new_node->next = first_node;
        break;
    }else if(n->flag == T_PTR_NODE){
        n = n->ast_node.ptr_node.ptr_to_node;
    }else if(n->flag == T_ARY_NODE){
        n = n->ast_node.ary_node.type;
    }else if (n->flag == I_STRUCT_TAG_NODE || n->flag == I_UNION_TAG_NODE){
        new_node->ast_node.var_node.node = ident_node->ast_node.common_node;
        new_node->flag = I_VAR_NODE;
        if (n->next != NULL){
            n = n->next;
            if (n->flag == T_SCALAR_NODE){
                new_node->ast_node.var_node.stg = n->ast_node.scalar_node.stg_class;
            }
        }else{
            if (strcmp(curr_scope->name,"global") == 0){
                new_node->ast_node.var_node.stg = T_EXTERN;
            }else{
                new_node->ast_node.var_node.stg = T_AUTO;
            }
        }
        break;
    }else if (n->flag == T_FN){
        // if the next node is a function node, make the new node a function node
        new_node->ast_node.fn_node.node = ident_node->ast_node.common_node;
        new_node->flag = I_FN_NODE;
        new_node->ast_node.fn_node.isDefined = 0;
        n = n->ast_node.type_fn_node.return_type;
        // go to the last scalar node to retrieve storage class and inline specs
        while (n->flag != T_SCALAR_NODE){
            n = n->next;
        }

        if (n->ast_node.scalar_node.stg_class != 0){
            new_node->ast_node.fn_node.stg = n->ast_node.scalar_node.stg_class;
            n->ast_node.scalar_node.stg_class = 0;
        }else{
            if (strcmp(curr_scope->name,"global") == 0){
                new_node->ast_node.var_node.stg = T_EXTERN;
            }else{
                new_node->ast_node.var_node.stg = T_AUTO;
            }
        }
        new_node->ast_node.fn_node.inline_spec = n->ast_node.scalar_node.inline_spec;
        n->ast_node.scalar_node.stg_class = 0;
        n->ast_node.scalar_node.inline_spec =0 ;
        new_node->next = first_node;
        break;
    }
    }
    //free(ident_node);
    return new_node;
}

//insert a symbol into the symbol table
// zero means insert / update successful
// -1 means error!
// the argument new_def is a boolean variable to determine whether if a variable with the same name and namespace already exist in the symbol table, to replace the definition (0) or to return an error (1)

struct node* insert_sym(char* name, int namespace, struct node* new_node, int new_def){
    // look up the symbol
    struct sym_node* existing_sym, *current_sym, *new_sym;
    struct scope_node* insert_scope;
    struct node* corrected_node;
	int s_offset, *isExtern;
    struct node* existing_node, *existing_node_arg, *new_node_arg;
    if (curr_scope == NULL){
        create_sym_table("global", 0);
    }
    if (new_node->flag == I_NODE){
        corrected_node = ident_var_type(new_node, isExtern);
		if (corrected_node->flag == I_VAR_NODE){
			corrected_node->ast_node.var_node.offset = stack_offset;
			s_offset = offset_inc(corrected_node);
			stack_offset += s_offset;
			// if it is a global variable
			if (*isExtern != 1 && curr_scope->scope_num == S_GLOBAL){
				inst_comm_directive(name, s_offset, s_offset);
			}
		}
    }else{
        corrected_node = new_node;
    }  
    
    struct node* ret_val;
    if (name != NULL){
        existing_sym = lookup(name, namespace, new_def);
    }else{
        existing_sym = NULL;
    }
    if (existing_sym != NULL){
        // if the symbol exist and new_def = 0, replace the definition and return 0
        if (new_def == 0){
            existing_sym-> ast_node = corrected_node;
            ret_val = existing_sym->ast_node;
        }else{
                if (namespace == N_TAGS){
                    // if the existing_sym is a nametag
                    if (existing_sym->ast_node->ast_node.struct_tag_node.isComplete == 0){
                        // if it is being referenced;
                        existing_sym->ast_node->ast_node.struct_tag_node.node = new_node->ast_node.common_node;
                        return existing_sym->ast_node;
                    }else{
                        // if it is already defined!
                        ret_val = NULL;
                    }
                }
                printf("%s in namespace %d already exist\n", name ,namespace);
                ret_val = NULL;
        }
        // if the symbol exist and new_def = 1, return an error, saying symbol already exist and you are redeclaring stuff
    }else{
        // if the symbol doesn't exist and new_def = 0, return an error, saying symbol doesn't exist
        if (new_def == 0){
            printf("doesn't exist\n");
            ret_val = NULL;
        }else{
            // make the new symbol table entry
            new_sym = (struct sym_node*) malloc(sizeof(struct sym_node));
            new_sym->sym_name  = name;
            new_sym->nspace = namespace;
            new_sym->ast_node = corrected_node;
            new_sym->next = NULL;
            insert_scope = curr_scope;
            if (namespace == N_TAGS){
                while (insert_scope->scope_num == S_STRUCTUNION){
                    insert_scope = insert_scope->prev_scope;
                }
            }
            if (namespace == N_LABELS){
                while (insert_scope->scope_num == S_BLOCK){
                    insert_scope = insert_scope->prev_scope;
                }
            }
            if (insert_scope->sym_node == NULL){
                // insert the first symbol entry into the linked list
                insert_scope->sym_node = new_sym;
                insert_scope->sym_node->prev = NULL;
            }else{
                current_sym = insert_scope -> sym_node;
                while (current_sym->next != NULL){
                    current_sym = current_sym -> next;
                }
                current_sym->next = new_sym;
                new_sym->prev = current_sym;
            }
            ret_val = new_sym->ast_node;
        }
    }
    if (namespace != N_MINIDEFS && namespace != N_TAGS){
        //print_debug_stmt(new_sym->ast_node);
    }
    return ret_val;
}

void enter_block(struct node* n, int num){
    if (n != NULL && n->flag == I_FN_NODE){
        create_sym_table(n->ast_node.fn_node.node.name, num);
    }else{
        create_sym_table("block", num);
    }
    return;
}

void leave_block(){
    destroy_sym_table();
}

struct node* insert_into_list(struct node* header, struct node* n){
    struct node* stmt = header;
    while (stmt->next != NULL){
        stmt = stmt->next;
    }
    stmt->next = n;
    return header;
}

void print_func_dump(int indent, struct node* n, struct node* ident){
    struct node* stmt = n;
    struct node* checker, *new_return;
    indent = 1;
    if (curr_scope->scope_num != S_FUNCTION){
        return;
    }
    checker = n->ast_node.list_node.head_list;
    while (checker->next != NULL){
        checker = checker->next;
    }
    if (checker->flag != ST_RETURN){
        new_return = ast_new_return(NULL);
        checker->next = new_return;
    }
    fprintf(stderr,"AST Dump for function %s\n", ident->ast_node.fn_node.node.name);
    print_stmt(stmt,indent);

}
// make the key_value map for switch statements
void make_switch_map(struct node* switch_body, struct node* stmt){
    struct node* n = stmt;
    struct node* switch_body_stmt = switch_body->ast_node.switch_node.label_maps;
    while (n != NULL){
        switch(n->flag){
            struct node* m;
            case ST_CASE:
                // make a key-value node
                m = (struct node*) malloc(sizeof(struct node));
                m->ast_node.switch_map.const_expr = n->ast_node.case_node.const_expr;
                m->ast_node.switch_map.case_stmt = n->ast_node.case_node.stmt;
                // add a map node
                m->flag = SWITCH_MAP;
                if (switch_body_stmt == NULL){
                    switch_body_stmt = m;
                    switch_body->ast_node.switch_node.label_maps = m;
                }else{
                    while (switch_body_stmt->next != NULL){
                        switch_body_stmt = switch_body_stmt->next;
                    }
                    switch_body_stmt->next = m;
                }
                make_switch_map(switch_body,n->ast_node.case_node.stmt);
                break;
            case ST_IF:
                make_switch_map(switch_body, n->ast_node.if_node.action);
                make_switch_map(switch_body, n->ast_node.if_node.else_action);
                break;
            case ST_WHILE:
                make_switch_map(switch_body, n->ast_node.while_node.action);
                break;
            case ST_FOR:
                make_switch_map(switch_body, n->ast_node.for_node.stmt);
                break;
            case ST_DO:
                make_switch_map(switch_body, n->ast_node.do_node.stmt);
                break;
            case ST_RETURN:
                make_switch_map(switch_body, n->ast_node.return_node.return_item);
                break;
            case ST_SWITCH:
                make_switch_map(switch_body, n->ast_node.switch_node.stmt);
                break;
            case ST_DEFAULT:
                m = (struct node*) malloc(sizeof(struct node));
                m->ast_node.switch_map.const_expr = n->ast_node.case_node.const_expr;
                m->ast_node.switch_map.case_stmt = n->ast_node.case_node.stmt;
                m->flag = SWITCH_MAP;
                // add a map node
                while (switch_body_stmt->next != NULL){
                    switch_body_stmt = switch_body_stmt->next;
                }
                switch_body_stmt->next = m;
                break;
            case LIST:
                make_switch_map(switch_body, n->ast_node.list_node.head_list);
                break;
            default:
                break;
        }
        if (n != NULL){
            n = n->next;
        }else{
            n = NULL;
        }
    }
    return;
    //recursively go down the statement tree
    //if we see a case label
    //add a struct node
}

void print_stmt(struct node* stmt, int indent){

    char * indentation;
    indentation = (char*) malloc(sizeof(char)*indent+1);
    for (int i = 0 ; i < indent-1; i++){
        indentation[i] = ' ';
    }
    indentation[indent-1] = '\0';
    while(stmt!= NULL){
        switch(stmt->flag){
            case LIST:
                fprintf(stderr,"%sLIST(\n", indentation);
                print_stmt(stmt->ast_node.list_node.head_list,indent+1);
                fprintf(stderr,"%s)\n", indentation);
                break;
            case ST_ASSIGN:
                fprintf(stderr,"%sASSIGNMENT\n",indentation);
                print_stmt(stmt->ast_node.assign_node.lval, indent + 1);
                print_stmt(stmt->ast_node.assign_node.rval, indent + 1);
                break;
            case ST_IF:
                fprintf(stderr,"%sIF\n",indentation);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.if_node.cond,indent + 1);
                fprintf(stderr,"%sBODY:\n",indentation);
                print_stmt(stmt->ast_node.if_node.action,indent + 1);
                fprintf(stderr,"%sELSE:\n",indentation);
                print_stmt(stmt->ast_node.if_node.else_action,indent + 1);
                break;
            case ST_DO:
                fprintf(stderr,"%sDO\n",indentation);
                fprintf(stderr,"%sBODY:\n",indentation);
                print_stmt(stmt->ast_node.do_node.stmt,indent + 1);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.do_node.cond,indent + 1);
                break;
            case ST_WHILE:
                fprintf(stderr,"%sWHILE\n",indentation);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.while_node.cond,indent + 1);
                fprintf(stderr,"%sBODY:\n",indentation);
                print_stmt(stmt->ast_node.while_node.action,indent + 1);
                break;
            case ST_FOR:
                fprintf(stderr,"%sFOR\n",indentation);
                fprintf(stderr,"%sINIT:\n",indentation);
                print_stmt(stmt->ast_node.for_node.init_clause,indent+1);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.for_node.end_cond,indent+1);
                fprintf(stderr,"%sINCR:\n",indentation);
                print_stmt(stmt->ast_node.for_node.action_clause,indent+1);
                fprintf(stderr,"%sBODY:\n",indentation);
                print_stmt(stmt->ast_node.for_node.stmt,indent+1);
                break;

            case ST_CONTINUE:
                fprintf(stderr,"%sCONTINUE\n", indentation);
                break;
            case ST_BREAK:
                fprintf(stderr,"%sBREAK\n",indentation);
                break;
            case ST_RETURN:
                fprintf(stderr,"%sRETURN:\n",indentation);
                print_stmt(stmt->ast_node.return_node.return_item,indent+1); 
                break;
            case ST_SWITCH:
                fprintf(stderr,"%sSWITCH:\n", indentation);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.switch_node.expr_node,indent+1);
                fprintf(stderr,"%sLABEL MAP:\n",indentation);
                print_stmt(stmt->ast_node.switch_node.label_maps,indent+1);
                fprintf(stderr,"%sBODY:\n",indentation);
                print_stmt(stmt->ast_node.switch_node.stmt,indent+1);
                break;
            case SWITCH_MAP:
                if (stmt->ast_node.switch_map.const_expr->flag == E_CONSTANT){
                    fprintf(stderr,"%sCASE %d\n", indentation, stmt->ast_node.switch_map.const_expr->ast_node.constant_node.value);
                }else{
                    fprintf(stderr,"%sCASE %c\n", indentation, stmt->ast_node.switch_map.const_expr->ast_node.constant_node.char_value);
                }
                break;
            case ST_CASE:
                fprintf(stderr,"%sCASE:\n",indentation);
                fprintf(stderr,"%sCOND:\n",indentation);
                print_stmt(stmt->ast_node.case_node.const_expr,indent+1);
                fprintf(stderr,"%sSTMT:\n",indentation);
                print_stmt(stmt->ast_node.case_node.stmt,indent+1);
                break;
            case ST_DEFAULT:
                fprintf(stderr,"%sDEFAULT:\n",indentation);
                fprintf(stderr,"%sSTMT:\n",indentation);
                print_stmt(stmt->ast_node.default_node.stmt,indent+1);
                break;
            case ST_GOTO:
                fprintf(stderr,"%sGOTO %s\n",indentation, stmt->ast_node.goto_node.stmt->ast_node.stmt_label_node.node.name); 
                break;
            case E_FN_CALL:
                fprintf(stderr,"%sFNCALL, %d arguments\n", indentation, stmt->ast_node.fn_call_node.num_args);
                print_stmt(stmt->ast_node.fn_call_node.caller, indent+1);
                fprintf(stderr,"%sARGS\n", indentation);
                print_stmt(stmt->ast_node.fn_call_node.arg, indent+1);
                break;

            case E_BINOP:
                fprintf(stderr,"%sBINARY OP ",indentation);
                switch(stmt->ast_node.binop_node.opcode){
                    case E_ADD: fprintf(stderr,"+\n"); break;
                    case E_MINUS: fprintf(stderr,"-\n"); break;
                    case E_MUL: fprintf(stderr,"*\n"); break;
                    case E_DIV: fprintf(stderr,"\\\n"); break;
                    case E_SHL: fprintf(stderr,"<<\n"); break;
                    case E_SHR: fprintf(stderr,">>\n"); break;
                    case E_MOD: fprintf(stderr,"mod \n"); break;
                    case E_LT: fprintf(stderr,"<\n"); break;
                    case E_GT: fprintf(stderr,">\n"); break;
                    case E_LTEQ: fprintf(stderr,"<=\n"); break;
                    case E_GTEQ: fprintf(stderr,">=\n"); break;
                    case E_EQEQ: fprintf(stderr,"==\n"); break;
                    case E_NOTEQ: fprintf(stderr,"!=\n"); break;
                    case E_LOGOR: fprintf(stderr,"||\n"); break;
                    case E_LOGAND: fprintf(stderr,"&&\n"); break;
                    case E_XOR: fprintf(stderr,"^\n"); break;
                    case E_AND: fprintf(stderr,"&\n"); break;
                    case E_OR: fprintf(stderr,"|\n"); break;
                }
                print_stmt(stmt->ast_node.binop_node.left, indent+1);
                print_stmt(stmt->ast_node.binop_node.right, indent+1);
                break;    
            case E_UNARY:
                fprintf(stderr,"%sUNARY OP ", indentation);
                switch(stmt->ast_node.unary_node.opcode){
                    case E_SIZEOF: fprintf(stderr,"SIZEOF\n"); break;
                    case E_UMINUS: fprintf(stderr,"-\n"); break;
                    case E_UPLUS: fprintf(stderr,"+\n"); break;
                    case E_LOGNOT: fprintf(stderr,"!\n"); break;
                    case E_BITNOT: fprintf(stderr,"~\n"); break;
                    case E_ADDRESS: fprintf(stderr,"ADDRESSOF\n"); break;
                    case E_POSTINC: fprintf(stderr, "POSTINC\n"); break;
                    case E_POSTDEC: fprintf(stderr,"POSTDEC\n"); break;
                }
                print_stmt(stmt->ast_node.unary_node.operand, indent+1);
                break;
            case E_DEREF:
                fprintf(stderr,"%sDEREF\n", indentation);
                print_stmt(stmt->ast_node.deref_node.dereferee, indent+1);
                break; 
            case E_DOT:
                fprintf(stderr,"%sSELECT, member %s\n", indentation, stmt->ast_node.indsel_node.selectee);
                print_stmt(stmt->ast_node.indsel_node.selector, indent+1);
                break;
            case E_INDSEL:
                fprintf(stderr,"%sINDIRECT SELECT, member %s\n", indentation, stmt->ast_node.indsel_node.selectee);
                print_stmt(stmt->ast_node.indsel_node.selector, indent+1);
                break;

            case I_VAR_NODE:
                fprintf(stderr,"%sstab_var name=%s def @%s:%d\n",indentation,
                        stmt->ast_node.var_node.node.name,stmt->ast_node.var_node.node.fname,
                        stmt->ast_node.var_node.node.line_num);
                break;

            case I_FN_NODE:
                fprintf(stderr,"%sstab_fn name=%s def @%s:%d\n", indentation,
                        stmt->ast_node.fn_node.node.name, stmt->ast_node.fn_node.node.fname,
                        stmt->ast_node.fn_node.node.line_num);
                break;
            case I_STMT_LABEL_NODE:
                fprintf(stderr,"%sLABEL:\n", indentation);
                fprintf(stderr,"%sNAME:%s\n", indentation, stmt->ast_node.stmt_label_node.node.name);
                fprintf(stderr,"%sSTMT:\n",indentation);
                print_stmt(stmt->ast_node.stmt_label_node.stmt,indent+1);
                break;
            case E_CONSTANT:
                // NOTE: Only support integers
                fprintf(stderr,"%sCONSTANT: (type=int) %d\n",indentation,
                        stmt->ast_node.constant_node.value);
                break;
            case E_CONST_CHAR:
                fprintf(stderr,"%sCONSTANT: (type=char) %c\n",indentation,
                        stmt->ast_node.constant_node.char_value);
                break;
			case E_LIST:
				print_stmt(stmt->ast_node.elist_node.ptr_to_arg, indent+1);
				break;
            default:

                break;
        }
        if (stmt != NULL){
            stmt = stmt->next;
        }else{
            stmt = NULL;
        }
    }
    free(indentation);
}

int offset_inc(struct node* n){
	if (n->flag == I_VAR_NODE){
		return offset_inc(n->next);
	}else if (n->flag == T_ARY_NODE){
		return n->ast_node.ary_node.ary_size * offset_inc(n->ast_node.ary_node.type);
	}else if(n->flag == T_PTR_NODE){
		return 4;
	}else if (n->flag == T_SCALAR_NODE){
		switch(n->ast_node.scalar_node.type){
			case T_SHORT: return SIZEOF_SHORT;
			case T_INT:   return SIZEOF_INT;
			case T_LONG:  return SIZEOF_LONG;
			case T_CHAR:  return SIZEOF_CHAR;
		}
	}
	return 0;
}

void print_debug_stmt(struct node* n){
    struct node* c, *rets, *args;
    struct sym_node* curr_sym_node;
    struct scope_node* scope_node; 
    c = n;
    char * s, *var_name, *scope_name;
    switch(curr_scope->scope_num){
        case S_GLOBAL:      scope_name="global";        break;
        case S_FUNCTION:    scope_name="function";      break;
        case S_BLOCK:       scope_name="block";         break;
        case S_PROTOTYPE:   scope_name="prototype";     break;
        case S_STRUCTUNION: scope_name="struct/union";  break;
        default:            scope_name="wrong";         break;
    }
    if (c->flag == I_VAR_NODE){
        switch(c->ast_node.var_node.stg){
            case T_EXTERN:      s = "extern";   break;
            case T_AUTO:        s = "auto";     break;
            case T_REGISTER:    s = "register"; break;
            case T_STATIC:      s = "static";   break;
            default: s = "wrong"; break;
        }
        fprintf(stderr,"%s is defined at %s:%d ",c->ast_node.var_node.node.name, 
                                                 c->ast_node.var_node.node.fname,
                                                 c->ast_node.var_node.node.line_num);
        fprintf(stderr,"[in %s scope starting at %s:%d] as a\n",scope_name,
                                                                curr_scope->fname,
                                                                curr_scope->line_num);
        fprintf(stderr,"variable with stgclass %s of type:\n", s);
        c = c->next;
        print_type(c);
    }else if (c->flag == I_FN_NODE){
        switch(c->ast_node.fn_node.stg){
            case T_EXTERN:  s = "extern";   break;
            case T_STATIC:  s = "static";   break;
            default:        s = "wrong";    break;
        }
        fprintf(stderr,"%s is defined at %s:%d ", c->ast_node.fn_node.node.name,
                                                  c->ast_node.fn_node.node.fname,
                                                  c->ast_node.fn_node.node.line_num);
        fprintf(stderr,"[in %s scope starting at %s:%d] as a \n", scope_name,
                                                                  curr_scope->fname,
                                                                  curr_scope->line_num);
        fprintf(stderr,"%s  function returning\n",s);
        rets = c->next->ast_node.type_fn_node.return_type;
        print_type(rets);
        
        args = c->next->ast_node.type_fn_node.arg;
        if (args == NULL){
            fprintf(stderr," and taking unknown arugments\n");
        }else{
            if (args->ast_node.arg_node.type == NULL){
                fprintf(stderr," and taking unknown arugments [named ");
                while (args->ast_node.arg_node.next_arg != NULL){
                    fprintf(stderr,"%s, ", args->ast_node.arg_node.ident->ast_node.common_node.name);
                    args = args->ast_node.arg_node.next_arg;
                }
                fprintf(stderr,"%s]", args->ast_node.arg_node.ident->ast_node.common_node.name);
            }else{
                fprintf(stderr," and taking the following arugments\n");
                while(args != NULL){
                    print_type(args->ast_node.arg_node.type);
                    args = args->ast_node.arg_node.next_arg;
                }
            }
        }
    }else if (c->flag == I_STRUCT_TAG_NODE || c->flag == I_UNION_TAG_NODE){
        switch(c->flag){
            case I_STRUCT_TAG_NODE: s="struct"; break;
            case I_UNION_TAG_NODE:  s="union";  break;
        }
        if (c->ast_node.struct_tag_node.node.name== NULL){
            var_name = "(anonymous)";
        }else{
            var_name = c->ast_node.struct_tag_node.node.name;
        }

        if (c->ast_node.member_node.node.name == NULL){
            scope_name = "(anonymous)";
        }else{
            scope_name = c->ast_node.member_node.node.name;
        }
        fprintf(stderr,"%s %s definition at %s:%d{\n", s, var_name,
                                                       c->ast_node.struct_tag_node.node.fname,
                                                       c->ast_node.struct_tag_node.node.line_num);
        curr_sym_node = c->ast_node.struct_tag_node.sym_table->sym_node;
        while (curr_sym_node != NULL){
            fprintf(stderr,"%s is defined at %s:%d",curr_sym_node->ast_node->ast_node.member_node.node.name,
                                                    curr_sym_node->ast_node->ast_node.member_node.node.fname,
                                                    curr_sym_node->ast_node->ast_node.member_node.node.line_num);
            fprintf(stderr," [in struct/union scope starting at %s:%d] as a\n", c->ast_node.struct_tag_node.node.fname,
                                                                              c->ast_node.struct_tag_node.node.line_num);
            fprintf(stderr,"field of %s %s off=%d bit_off=%d bit_wid=%d, type:\n",s, scope_name,
                                                                                curr_sym_node->ast_node->ast_node.member_node.offset,
                                                                                curr_sym_node->ast_node->ast_node.member_node.bit_offset, 
                                                                                curr_sym_node->ast_node->ast_node.member_node.width);
            print_type(curr_sym_node->ast_node->next);
            curr_sym_node = curr_sym_node->next;
        }
        fprintf(stderr,"} (size==%d)\n\n", c->ast_node.struct_tag_node.size); 
    }
    
}

void print_type(struct node* c){
    struct node* next_ptr = c;
    int len = 2;
    char* indentation = (char*) malloc(4096*sizeof(char));
    for (int i = 0 ; i < 4096; i++){
        indentation[i] = '\0';
    }
    indentation[0] = ' ';
    indentation[1] = ' ';
    while (next_ptr != NULL){
        if (next_ptr->flag == T_SCALAR_NODE){
            char * type, *qual;
            switch(next_ptr->ast_node.scalar_node.qualifier){
                case T_CONST:       qual = "const ";     break;
                case T_VOLATILE:    qual = "volatile ";  break;
                case T_RESTRICT:    qual = "restrict ";  break;
                default:            qual = "";          break;
            }
            switch(next_ptr->ast_node.scalar_node.type){
                case T_SHORT:               type = "short";                 break;
                case T_INT:                 type = "int";                   break;
                case T_LONG:                type = "long";                  break;
                case T_LONGLONG:            type = "long long";             break;
                case T_USHORT:              type = "unsigned short";        break;
                case T_UINT:                type = "unsigned int";          break;
                case T_ULONG:               type = "unsigned long";         break;
                case T_ULONGLONG:           type = "unsigned long long";    break;
                case T_CHAR:                type = "char";                  break;
                case T_SCHAR:               type = "signed char";           break;
                case T_UCHAR:               type = "unsigned char";         break;
                case T_BOOL:                type = "bool";                  break;
                case T_FLOAT:               type = "float";                 break;
                case T_DOUBLE:              type = "double";                break;
                case T_LONGDOUBLE:          type = "long double";           break;
                case T_FLOATCOMPLEX:        type = "float complex";         break;
                case T_DOUBLECOMPLEX:       type = "double complex";        break;
                case T_LONGDOUBLECOMPLEX:   type = "long double complex";   break;
                case T_VOID:                type = "void";                  break; 
                default:                    type = "";                      break;
            }
            fprintf(stderr,"%s%s%s\n", indentation, qual, type);
            break;
        }else if (next_ptr->flag == T_PTR_NODE){
            fprintf(stderr, "%spointer to\n", indentation);
            next_ptr = next_ptr->ast_node.ptr_node.ptr_to_node;
            
        }else if (next_ptr->flag == I_STRUCT_TAG_NODE){
            if (next_ptr->ast_node.struct_tag_node.node.name != NULL){
                fprintf(stderr, "%sstruct %s",indentation,next_ptr->ast_node.struct_tag_node.node.name);
                if (next_ptr->ast_node.struct_tag_node.isComplete == 1){
                    fprintf(stderr,"(defined at %s:%d)\n", next_ptr->ast_node.struct_tag_node.node.fname,
                                                           next_ptr->ast_node.struct_tag_node.node.line_num);
                }else{
                    fprintf(stderr,"(incomplete)\n");
                }   
            }else{
                fprintf(stderr,"%sstruct (anonymous) ", indentation);
                if (next_ptr->ast_node.struct_tag_node.isComplete == 1){
                    fprintf(stderr,"(defined at %s:%d)\n", next_ptr->ast_node.struct_tag_node.node.fname,
                                                           next_ptr->ast_node.struct_tag_node.node.line_num);
                }else{
                    fprintf(stderr,"(incomplete)\n");
                }  
            }
            break;
        }else if (next_ptr->flag == T_ARY_NODE){
            if (next_ptr->ast_node.ary_node.ary_size != 0){
                fprintf(stderr,"%s (%p) array of %d elements of type\n", indentation, next_ptr,next_ptr->ast_node.ary_node.ary_size);
            }else{
                fprintf(stderr,"%sarray of unknown elements of type\n", indentation);
            }
            next_ptr = next_ptr->ast_node.ary_node.type;
        }else if(next_ptr->flag == I_UNION_TAG_NODE){
            fprintf(stderr, "%sunion %s\n", indentation,next_ptr->ast_node.struct_tag_node.node.name);
            break;
        }
        indentation[len] = ' ';
        indentation[len+1] = ' ';
        len += 2;
    }
}
