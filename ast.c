#include "ast.h"

extern int line_num;
extern char* fname;
extern struct scope_node* curr_scope;
// insert a scalar type node
struct node* ast_new_scalar_type(int scalar_type){
    struct node * n = (struct node*) malloc(sizeof(struct node));
    if (scalar_type >= T_SHORT && scalar_type <= T_VOID){
        n->ast_node.scalar_node.type = scalar_type;
        n->ast_node.scalar_node.qualifier = 0;
        n->ast_node.scalar_node.stg_class = 0;
        n->ast_node.scalar_node.inline_spec = 0;
    }else if (scalar_type >= T_CONST && scalar_type <= T_RESTRICT){
        n->ast_node.scalar_node.qualifier = scalar_type;
        n->ast_node.scalar_node.type = 0;
        n->ast_node.scalar_node.stg_class = 0;
        n->ast_node.scalar_node.inline_spec = 0;
    }else if (scalar_type >= T_AUTO && scalar_type <= T_STATIC){
        n->ast_node.scalar_node.stg_class = scalar_type;
        n->ast_node.scalar_node.type = 0;
        n->ast_node.scalar_node.qualifier = 0;
        n->ast_node.scalar_node.inline_spec = 0;
    }else{
        n->ast_node.scalar_node.inline_spec = scalar_type;
        n->ast_node.scalar_node.type = 0;
        n->ast_node.scalar_node.qualifier =0;
        n->ast_node.scalar_node.stg_class = 0;
    }
    n->flag = T_SCALAR_NODE;
    return n;
}

// after a scalar type is declared for a declaration, if there are more qualifiers, storage class specs etc. it will be appended to the scalar node
struct node* ast_add_scalar_type(struct node* n, int scalar_type){
  
    if (scalar_type >= T_SHORT && scalar_type <= T_VOID){
        if (n->ast_node.scalar_node.type != 0){
            fprintf(stderr,"You already declared a type!\n");
        }else{
            n->ast_node.scalar_node.type = scalar_type;
        }
    }else if (scalar_type >= T_CONST && scalar_type <= T_RESTRICT){
        if (n->ast_node.scalar_node.qualifier != 0){
            fprintf(stderr,"You already declared a qualifier!\n");
        }else{
            n->ast_node.scalar_node.qualifier = scalar_type;
        }
    }else if (scalar_type >= T_AUTO && scalar_type <= T_STATIC){
        if (n->ast_node.scalar_node.stg_class != 0){
            fprintf(stderr, "You already declared a storage class!\n");
        }else{
            n->ast_node.scalar_node.stg_class = scalar_type;
        }
    }else{
        if (n->ast_node.scalar_node.inline_spec != 0){
            fprintf(stderr, "You already declared a storage class!\n");
        }else{
            n->ast_node.scalar_node.inline_spec = scalar_type;
        }

    }
    return n;
}

// insert a new identifier
struct node* ast_new_ident(char *name, int type){
    char * c_fname;
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->next = NULL;
    c_fname = (char*) malloc(4096*sizeof(char));
    strcpy(c_fname, fname);
    if (type == I_NODE){
        n->ast_node.common_node.name = name;
        n->ast_node.common_node.nspace = N_OTHERS;
        n->ast_node.common_node.line_num = line_num;
        n->flag = I_NODE;
        n->ast_node.common_node.fname = c_fname;
    }else if (type == I_STMT_LABEL_NODE){
        n->ast_node.stmt_label_node.node.name = name;
        n->ast_node.stmt_label_node.node.nspace = N_LABELS;
        n->flag = I_STMT_LABEL_NODE;
        n->ast_node.stmt_label_node.node.line_num = line_num;
    } 
    return n;
}

// add nodes after the identifier to add information about its type
// for functions, it would be appended as the return type
struct node* add_type_node(struct node* ident_node, struct node* type_node){
    struct node* last_node;
    last_node = ident_node;
    if (ident_node->next != NULL && ident_node->next->flag == T_FN){
        // if the type node is a function node, then set the type node as the return type
        // of function nodei
        ident_node->next->ast_node.type_fn_node.return_type = type_node;
    }else{
        // else it would be a variable node, in that case just link the identiier to the 
        // scalar node
        // if the type is not declared, default it to an integer
        if (type_node->flag == T_SCALAR_NODE){
            if (type_node->ast_node.scalar_node.type == 0){
                type_node->ast_node.scalar_node.type = T_INT;
            }
        }
        while (last_node != NULL){
            if (last_node->flag == T_PTR_NODE){
                if (last_node->ast_node.ptr_node.ptr_to_node != NULL){
                    last_node = last_node->ast_node.ptr_node.ptr_to_node;
                }else{
                    last_node->ast_node.ptr_node.ptr_to_node = type_node;
                    break;
                }
            }else if(last_node->flag == I_NODE){
                if (last_node->next != NULL){
                    last_node = last_node->next;   
                }else{
                    last_node->next = type_node;
                    break;
                }
            }else if (last_node->flag == T_ARY_NODE){
                if (last_node->ast_node.ary_node.type != NULL){
                    fprintf(stderr,"Recursing down ary node\n");
                    last_node = last_node->ast_node.ary_node.type;
                }else{
                    last_node->ast_node.ary_node.type = type_node;
                    break;
                }
            }else{
                break;
            }
        }
    }

    return ident_node;
}

// make a new function node;
struct node* ast_new_func(struct node* ident_node){
    // make a new function node
    struct node* fn_node = (struct node *) malloc(sizeof(struct node));
    ident_node->next = fn_node;
    fn_node->flag = T_FN;
    fn_node->ast_node.type_fn_node.arg = NULL;
    return ident_node;    
}

// make a new pointer node
struct node* ast_new_ptr(){
    struct node* ptr_node = (struct node*) malloc(sizeof(struct node));
    ptr_node->flag = T_PTR_NODE;
    return ptr_node;
}

// make an argument for function nodes
struct node* ast_func_make_arg(struct node* decl_specs, struct node* ident_node){
    struct node* arg_node = (struct node*) malloc(sizeof(struct node));
    arg_node->flag = T_ARG_NODE;
    arg_node->ast_node.arg_node.ident = ident_node;
    arg_node->ast_node.arg_node.type = decl_specs;
    arg_node->ast_node.arg_node.next_arg = NULL;
    return arg_node;
}

// add an argument to the argument list
struct node* ast_func_add_arg(struct node* first_arg, struct node* current_arg){
    struct node* curr_node = first_arg;
    while (curr_node->ast_node.arg_node.next_arg != NULL){
        curr_node = curr_node->ast_node.arg_node.next_arg;
    }
    curr_node->ast_node.arg_node.next_arg = current_arg;
    return curr_node;
}

struct node* ast_new_ary(int size){
    struct node* ary_node = (struct node*) malloc(sizeof(struct node));
    ary_node->ast_node.ary_node.ary_size = size;
    ary_node->ast_node.ary_node.type = NULL;
    ary_node->flag = T_ARY_NODE;
    return ary_node;
}

struct node* ast_add_ptr_to_decl(struct node* ptr_node, struct node* direct_decl){
    // identiier, declarator, depending on what the direct decl is, we do different things
    struct node* next = direct_decl;
    struct node* curr = direct_decl;
    if (curr->flag == I_NODE){
        next = curr->next;
    }else if (curr->flag == T_ARY_NODE){
        next = curr->ast_node.ary_node.type;
    }else{
        next = curr->ast_node.ptr_node.ptr_to_node;
    }
    while (next != NULL){
        if (curr->flag == I_NODE){
            curr = next;
            next = curr->next;
        }else if (curr->flag == T_ARY_NODE){
            curr = next;
            next = curr->ast_node.ary_node.type;
        }else{
            curr = next;
            next = curr->ast_node.ptr_node.ptr_to_node;
        }
    }
    if (curr->flag == I_NODE){
        curr->next = ptr_node;
    }else if (curr->flag == T_ARY_NODE){
        curr->ast_node.ary_node.type = ptr_node;
    }else{
        curr->ast_node.ptr_node.ptr_to_node = ptr_node;
    }

}

// make a new structure node
struct node* ast_new_struct(char* ident, int flag){
    struct node * new_node = (struct node*) malloc(sizeof(struct node));
    char* c_fname = (char*) malloc(4096*sizeof(char));
    strcpy(c_fname, fname);
    if (ident != NULL){
        char* tag_name = (char*) malloc(strlen(ident)*sizeof(char));
        strcpy(tag_name, ident);
        new_node->ast_node.struct_tag_node.node.name = ident;
    }else{
        new_node->ast_node.struct_tag_node.node.name = NULL;    // anonymous structs
    }
    new_node->ast_node.struct_tag_node.node.line_num = line_num;
    new_node->ast_node.struct_tag_node.node.fname=  c_fname;
    new_node->ast_node.struct_tag_node.node.nspace = N_TAGS;    // in the namespace for tags
    new_node->flag = flag;
    new_node->ast_node.struct_tag_node.size = 0;
    new_node->ast_node.struct_tag_node.sym_table = NULL;
    new_node->ast_node.struct_tag_node.isComplete = 0;  // not complete yet lol
}

struct node* ast_new_binop(int opcode, struct node* left, struct node* right){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.binop_node.opcode = opcode;
    n->ast_node.binop_node.left = left;
    n->ast_node.binop_node.right = right;    
    n->flag = E_BINOP;
    return n;
}

struct node* ast_new_assign(struct node* lval, struct node* rval){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.assign_node.lval = lval;
    n->ast_node.assign_node.rval = rval;
    n->flag = ST_ASSIGN;
    return n;
}

struct node* ast_new_for(struct node* init_clause, struct node* end_cond, struct node* action){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.for_node.init_clause = init_clause;
    n->ast_node.for_node.end_cond = end_cond;
    n->ast_node.for_node.action_clause = action;
    n->flag = ST_FOR;
    return n;
}

struct node* ast_new_while(struct node* cond, struct node* stmt){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.while_node.cond = cond;
    n->ast_node.while_node.action = stmt;
    n->flag = ST_WHILE;
    return n;
}

struct node* ast_new_do(struct node* stmt, struct node* cond){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.do_node.stmt = stmt;
    n->ast_node.do_node.cond = cond;
    n->flag = ST_DO;
    return n;

}

struct node* ast_new_if(struct node* cond, struct node* action, struct node* else_action){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.if_node.action = action;
    n->ast_node.if_node.cond = cond;
    n->ast_node.if_node.else_action = else_action;
    n->flag = ST_IF;
    return n;
}

struct node* ast_new_const(int value){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.constant_node.value = value;
    n->flag = E_CONSTANT;
    return n;
}

struct node* ast_new_const_char(char value){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.constant_node.char_value = value;
    n->flag = E_CONST_CHAR;
    return n;
}

struct node* ast_new_const_string(char* str, int str_size, int string_count){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.constant_node.str_value = (char*) malloc(str_size * sizeof(char));
    strncpy(n->ast_node.constant_node.str_value, str, str_size);
    n->ast_node.constant_node.str_size = str_size;
    n->ast_node.constant_node.str_count = string_count;
    n->flag = E_STR;
    return n;
}

struct node* ast_new_unary(int opcode, struct node* operand){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.unary_node.opcode = opcode;
    n->ast_node.unary_node.operand = operand;
    n->flag = E_UNARY;
    return n;
}

struct node* ast_new_indsel(int flag, struct node* selector, char* selectee){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.indsel_node.selector = selector;
    char* name = malloc(strlen(selectee) * sizeof(char));
    name = selectee;
    n->ast_node.indsel_node.selectee = name;
    n->flag = flag;
    return n;
}

struct node* ast_new_deref(struct node* dereferee){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.deref_node.dereferee = dereferee;
    n->flag = E_DEREF;
    return n;
};

struct node* ast_new_fn_call(struct node* expr_list, struct node* fn_caller){
    struct node* arg_list = expr_list;
    int count = 0;
    struct node* n = (struct node*) malloc(sizeof(struct node));
    while (arg_list != NULL){
        count += 1;
        arg_list = arg_list->next;
    }
    n->flag = E_FN_CALL;
    n->ast_node.fn_call_node.num_args = count;
    n->ast_node.fn_call_node.caller = fn_caller;
    n->ast_node.fn_call_node.arg = expr_list;
    return n;
}

struct node* ast_new_switch(struct node* switch_cond, struct node* body){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->flag = ST_SWITCH;
    n->ast_node.switch_node.stmt = body;
    n->ast_node.switch_node.expr_node = switch_cond;
    return n;
}

struct node* ast_new_stmt(int type_flag){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->flag = type_flag;
    return n;
}

struct node* ast_new_return(struct node* return_type){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->flag = ST_RETURN;
    if (return_type != NULL){
        n->ast_node.return_node.return_item = return_type;
    }
    return n;
}

struct node* ast_new_case(struct node* const_expr){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    if(const_expr == NULL){
        n->flag = ST_DEFAULT;
    }else{
        n->flag = ST_CASE;
        n->ast_node.case_node.const_expr = const_expr;
    }
    return n;
}

struct node* ast_new_goto(struct node* label){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->ast_node.goto_node.stmt = label;
    n->flag = ST_GOTO; 
    return n;
}

struct node* ast_new_expr_arg(struct node* prev_node, struct node* new_arg){
	struct node* n = (struct node*) malloc(sizeof(struct node));
	struct node* curr_node;
	n->ast_node.elist_node.ptr_to_arg = new_arg;
	n->flag = E_LIST;
	if (prev_node == NULL){
		prev_node = n;
	}else{
		curr_node = prev_node;
		while (curr_node->next != NULL){
			curr_node = curr_node->next;
		}
		curr_node->next = n;
	}
	return prev_node;
}


