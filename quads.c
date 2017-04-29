#include "flags.h"
#include "inst.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// Do i need to keep a master list of quads? YES
// How do we keep track of temporary values, are we going to implement a global counter to count how many has been generated? keep a master list of temporary nodes and let the quads point to that?

// what's done
// arithmetic operation, assignment operators, bitwise/shift operators
// pointer arithmetic, array arithmetic (basic), expression statements
// return statements, if statements, loop statements, break/continue stmt
// function calls, sizeof operations, array arithmetic, unary operators

// what still needs to be done

// optional
// ternary operators
// handling structs / unions
extern int show_quads;
extern int show_targetcode;
extern int stack_offset;
struct node* head_temp;

void generate_quads(struct node* stmt, int scope, struct node* ident){
    struct bblock* head_bb;
    if (scope != S_FUNCTION){
        return;
    }
    if (show_targetcode == 1){
    	inst_txt_directive();
	    inst_func_directive(ident->ast_node.fn_node.node.name);
	    inst_label(ident->ast_node.fn_node.node.name);
	    inst_func_prologue();	
    }
    bb_counter = 0;
    cur_bb = new_bb();
    head_bb = cur_bb;
    gen_quads(stmt, NULL, NULL);
    print_bb(head_bb);
}

void gen_quads(struct node* stmt, struct bblock* break_node, struct bblock* cont_node){
    // do a post order traversal
    struct node* curr_stmt = stmt;
    struct node* rval;
    while (curr_stmt != NULL){
        switch(curr_stmt->flag){
            case ST_ASSIGN:
                // how do you generate quad for a = b = c;
                // how do you get sizeof to work?
                // unary operators -- how to make it work?
                // how do you get array arithmetic? should i store it in the AST tree?
                gen_assign(curr_stmt);
                break;
			case ST_IF:
				gen_if(curr_stmt, break_node, cont_node);
                break;
            case ST_RETURN:
                gen_return(curr_stmt);
                break;
            case ST_WHILE:
                gen_while(curr_stmt);
                break;
            case ST_DO:
                gen_do(curr_stmt);
                break;
            case ST_FOR:
                gen_for(curr_stmt); 
                break;
            case ST_BREAK:
                gen_break(break_node); 
                break;
            case E_FN_CALL:
                gen_rvalue(curr_stmt, NULL);
                break;
            case E_UNARY:
                gen_rvalue(curr_stmt, NULL);
                break;                
            case E_BINOP:
                gen_rvalue(curr_stmt, NULL);
                break;
			case ST_CONTINUE:
				gen_break(cont_node);
				break;
            case LIST:
                gen_quads(curr_stmt->ast_node.list_node.head_list, break_node, cont_node);
            default:
                break; 
        }
        curr_stmt = curr_stmt->next;
    }
}

// generates the necessary quads for return statements.
struct node* gen_return(struct node* return_node){
    struct node* ret;
    if (return_node->ast_node.return_node.return_item == NULL){
        emit(QUAD_RETURN, NULL, NULL, NULL);
        return NULL;
    }
    struct node* retval = gen_rvalue(return_node->ast_node.return_node.return_item, NULL);
    emit(QUAD_RETURN, retval, NULL, NULL);
    return NULL;
}

struct node* gen_break(struct bblock* break_node){
    struct bblock *Bn;
	Bn = new_bb();
    link_bb(cur_bb, ALWAYS, break_node, NULL);
	cur_bb = Bn;
}

// generates the necessary quads for if statements. Currently cannot handle complicated 
// conditional expressions. Returns the node after evaluating true/false
struct node* gen_if(struct node* if_node, struct bblock* break_node, struct bblock* cont_node){
    struct bblock *Bt, *Bf, *Bn;
    Bt = new_bb();
    Bf = new_bb();
    if (if_node->ast_node.if_node.else_action != NULL){
        Bn = new_bb();
    }else{
        Bn = Bf;
    }
    gen_condexpr(if_node->ast_node.if_node.cond, Bt, Bf);  // creates branches to Bt, Bf
    cur_bb = Bt;
    gen_quads(if_node->ast_node.if_node.action, break_node, cont_node);
    link_bb(cur_bb, ALWAYS, Bn, NULL);
    if (if_node->ast_node.if_node.else_action){
        cur_bb = Bf;
        gen_quads(if_node->ast_node.if_node.else_action, break_node, cont_node);
        link_bb(cur_bb, ALWAYS, Bn, NULL);
    }
    cur_bb = Bn;
}

// generates the necessary quads for while statements. Currently cannot handle complicated
// conditional expressions. 
struct node* gen_while(struct node* while_node){
    struct bblock *Bt, *Bn, *Bo;
    Bo = new_bb();  // condition
    Bt = new_bb();  // body
    Bn = new_bb();  // fall through
    // Link while loop with Bn and Bt
    link_bb(cur_bb, ALWAYS, Bo, NULL);
    cur_bb = Bo;
    gen_condexpr(while_node->ast_node.while_node.cond, Bt, Bn);
    cur_bb = Bt;
    // generates quads for body and link body with Bn
    gen_quads(while_node->ast_node.while_node.action, Bn, Bt);
    link_bb(cur_bb, ALWAYS, Bo, NULL);
    cur_bb = Bn;
    
}

struct node* gen_do(struct node* do_node){
    struct bblock *Bt, *Bn, *Bo;
    Bt = new_bb(); // body
    Bo = new_bb(); // condition
    Bn = new_bb(); // fall through
    link_bb(cur_bb, ALWAYS, Bt, NULL);
    cur_bb = Bt; // BODY
    gen_quads(do_node->ast_node.do_node.stmt, Bn, Bt);
    link_bb(cur_bb, ALWAYS, Bo, NULL);
    cur_bb = Bo; // CONDITION
    gen_condexpr(do_node->ast_node.do_node.cond, Bt, Bn);
    cur_bb = Bn;
}

struct node* gen_for(struct node* for_node){
    struct bblock *body, *increment, *condition, *Bn;
    body = new_bb();
    increment = new_bb();
    condition = new_bb();
    Bn = new_bb();
    gen_quads(for_node->ast_node.for_node.init_clause, NULL, NULL);
    link_bb(cur_bb, ALWAYS, condition, NULL);
    
    cur_bb = body;
    gen_quads(for_node->ast_node.for_node.stmt, Bn, increment);
    link_bb(cur_bb, ALWAYS, increment, NULL);
    
    cur_bb = increment;
    gen_quads(for_node->ast_node.for_node.action_clause, NULL, NULL);
    link_bb(cur_bb, ALWAYS, condition, NULL);   // overwrites! :(
    
    cur_bb = condition;
    gen_condexpr(for_node->ast_node.for_node.end_cond, body, Bn);
    cur_bb = Bn;
}

// cannot handle complicated conditional expressions yet
void gen_condexpr(struct node* cond, struct bblock* Bt, struct bblock* Bf){
    // generate code to evaluate conditional expressions
    // what if there is assignments / function calls?
    // (a+b == c+d)
    // (a>b && c>d)
    struct node *left, *right, *temp, *zero;
    struct bblock* cond1;
    if(cond->flag == E_BINOP){
        switch(cond->ast_node.binop_node.opcode){
            case E_LOGAND:
                cond1 = new_bb();   // evaluate second condition
                // generate condition expression for first condition
                gen_condexpr(cond->ast_node.binop_node.left, cond1, Bf);
                // generate condition expression for second condition
                cur_bb = cond1;
                gen_condexpr(cond->ast_node.binop_node.right, Bt, Bf);
				break;
            case E_LOGOR:
                cond1 = new_bb();
                gen_condexpr(cond->ast_node.binop_node.left, Bt, cond1);
                cur_bb = cond1;
                gen_condexpr(cond->ast_node.binop_node.right, Bt, Bf);
                break;
            case E_EQEQ:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                emit(QUAD_CMP, left, right, NULL); 
                emit(QUAD_BREQ, NULL, NULL, NULL);
				break;
	        case E_NOTEQ:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                emit(QUAD_CMP, left, right, NULL);
                emit(QUAD_BRNEQ, NULL, NULL, NULL);
                break;
		    case E_LT:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
				emit(QUAD_CMP, left, right, NULL);
				emit(QUAD_BRLT, NULL, NULL, NULL);
				break;
            case E_GT:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                emit(QUAD_CMP, left, right, NULL);
                emit(QUAD_BRGT, NULL, NULL, NULL);
                break;
            case E_LTEQ:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                emit(QUAD_CMP, left, right,NULL);
                emit(QUAD_BRLE, NULL, NULL, NULL);
                break;
            case E_GTEQ:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                emit(QUAD_CMP, left, right, NULL);
                emit(QUAD_BRGE, NULL, NULL, NULL);
                break;
            default:
                left = gen_rvalue(cond->ast_node.binop_node.left, NULL);
                right = gen_rvalue(cond->ast_node.binop_node.right, NULL);
                temp = new_temporary();
                zero = ast_new_const(0);
                emit(cond->ast_node.binop_node.opcode, left, right, temp);
                emit(QUAD_CMP, temp, zero, NULL);
                emit(QUAD_BRGE, NULL, NULL, NULL);
                break; 
        }
    }else if (cond->flag == E_UNARY){
        struct node* operand;
        operand = gen_rvalue(cond->ast_node.unary_node.operand, NULL);
        switch(cond->ast_node.unary_node.opcode){
            case E_LOGNOT:
                temp = new_temporary();
                zero = ast_new_const(0);
                emit(QUAD_NOT, operand, NULL, temp);
                emit(QUAD_CMP, temp, zero, NULL);
                emit(QUAD_BRLE, NULL, NULL, NULL);
                break;
            default:
                // SIZEOF, POSTINC, POSTDEC, ADDRESS, BITNOT, 
                temp = new_temporary();
                zero = ast_new_const(0);
                emit(QUAD_CMP, operand, zero, NULL);    
                emit(QUAD_BRGE, NULL, NULL, NULL);
                break;
        }
    }else{
        temp = gen_rvalue(cond, NULL);
        zero = ast_new_const(0);
        emit(QUAD_CMP, temp, zero, NULL);
        emit(QUAD_BRGE, NULL, NULL, NULL);
    }

    // link current basic block to the true or false blocks
    link_bb(cur_bb, BRANCHES, Bt, Bf);
    // link current basic block to the two true or false blocks
}

void link_bb(struct bblock* bb, int linkage, struct bblock* b1, struct bblock* b2){
	if (linkage == ALWAYS){
		bb->next_linker = ALWAYS;
		bb->s_block = b1;
        b1->p_block = bb;
        emit(QUAD_BR, NULL, NULL, NULL);
	}else{
		bb->next_linker = BRANCHES;
		bb->t_block = b1;
		bb->f_block = b2;
        b1->from_cond_block = bb;
        b2->from_cond_block = bb;
	}
}

struct bblock* new_bb(){
    struct bblock* bb;
    bb = (struct bblock*) malloc(sizeof(struct bblock));
    bb_counter += 1;
    bb->visited = 0;
    bb->bb_count = bb_counter;
    bb->fn_count = fn_counter;
    return bb;
}

struct node* gen_assign(struct node* node){
    int dstmode;
    struct node* src;
    struct node* dst = gen_lvalue(node->ast_node.assign_node.lval, &dstmode);
    if (&dstmode == NULL){
        // NOTE: need to specify line number and file name
        fprintf(stderr,"Invalid LHS of assignment\n");
        return dst;
    }
    if (dstmode == E_DIRECT){
        src = gen_rvalue(node->ast_node.assign_node.rval, dst);
        if (src->flag == E_CONST_CHAR || src->flag == E_CONSTANT || src->flag == E_STR){
            emit(QUAD_MOV, src, NULL , dst);
        }
    }else{
        struct node* t1 = gen_rvalue(node->ast_node.assign_node.rval, NULL);
        emit(QUAD_STORE, t1, dst, NULL);
    }
    return dst;    
}

struct node* gen_lvalue(struct node* node, int *mode){
    struct node* ret_val; 
    if (node->flag == I_VAR_NODE && node->next->flag == T_SCALAR_NODE) {
        *mode = E_DIRECT;
        return node;
    }
    if (node->flag == E_CONSTANT || node->flag == E_CONST_CHAR || node->flag == E_STR) return NULL;
    if (node->flag == E_DEREF){
        *mode = E_INDIRECT;
        ret_val = gen_rvalue(node->ast_node.deref_node.dereferee, NULL);
    }
    if (node->flag == I_VAR_NODE && node->next->flag == T_PTR_NODE){
        // if it is a pointer, return the pointer
        *mode = E_DIRECT;
        return node;
    }
    return ret_val;
}

struct node*  gen_rvalue(struct node* node,struct node* target){
    struct node* left, *right, *addr, *temp, *ar_size_node, *my_ptr;
	struct node* temper, *zero, *one;
    struct bblock * Bt, *Bf, *Bn;
	int opcodes;
    int ary_size;
    if (node->flag==I_VAR_NODE && (node->next->flag==T_SCALAR_NODE || node->next->flag == T_PTR_NODE) || node->flag == I_FN_NODE){
        return node;  // if it is a scalar
    }
    if (node->flag == I_VAR_NODE &&(node->next->flag == T_ARY_NODE)){
        // if it is an array
        target = new_temporary();
        emit(QUAD_LEA, node, NULL, target);
        return target;
    }
	if (node->flag == T_PTR_NODE) return node->ast_node.ptr_node.ptr_to_node;
    if (node->flag == E_CONSTANT || node->flag == E_CONST_CHAR || node->flag == E_STR) return node;      // if it is a constant
	if (node->flag == E_UNARY){
        struct node* ptr_to;
		switch(node->ast_node.unary_node.opcode){
			case E_SIZEOF:
				left = ast_new_const(find_size(node->ast_node.unary_node.operand));
				right = NULL;
				opcodes = QUAD_MOV;
				break;
			case E_ADDRESS:
				left = gen_rvalue(node->ast_node.unary_node.operand, NULL);
				right = NULL;
                temp = ast_typeof(target);
                if (temp != NULL && temp->flag == T_PTR_NODE){
                    // if your target is a pointer
                    emit(QUAD_MOV, left, right, target);
                    return target;
                }
                ptr_to = ast_new_ptr();
                ptr_to->ast_node.ptr_node.ptr_to_node = left;
                opcodes = QUAD_LEA;
				break;
            case E_LOGNOT:
                Bt = new_bb();
                Bf = new_bb();
                Bn = new_bb();
                temp = new_temporary();
                zero = ast_new_const(0);
                one = ast_new_const(1);
                gen_condexpr(node, Bt, Bf);
                cur_bb = Bt;
                emit(QUAD_MOV, one, NULL, target);
                link_bb(cur_bb, ALWAYS, Bn, NULL);
                cur_bb = Bf;
                emit(QUAD_MOV, zero, NULL, target);
                link_bb(cur_bb, ALWAYS, Bn, NULL);
                cur_bb = Bn;
                return target;
                break;
            case E_POSTINC:
                temp = new_temporary();
                left = gen_rvalue(node->ast_node.unary_node.operand, NULL);
                one = ast_new_const(1);
                emit(QUAD_MOV, left, NULL, temp);
                emit(E_ADD, left, one, left);
                return temp;
                break;
            case E_POSTDEC:
                temp = new_temporary();
                left = gen_rvalue(node->ast_node.unary_node.operand, NULL);
                one = ast_new_const(1);
                emit(QUAD_MOV, left, NULL, temp);
                emit(E_MINUS, left, one, left);
                return temp;
                break;
            default:
                left = gen_rvalue(node->ast_node.unary_node.operand, NULL);
                right = NULL;
                opcodes = node->ast_node.unary_node.opcode;
		}
		if (target == NULL){
			target = new_temporary();
            if (ptr_to != NULL){
                target->ast_node.temp_node.ary_temp = ptr_to;
            }   
        }
		emit(opcodes, left, right,target);
        return target;
	}
    if (node->flag == E_BINOP){
        int opcode = node->ast_node.binop_node.opcode;
   		int ary_size;
		struct node* temper, *new_targ;
		struct node* l_type, *r_type, *ar_size_node;
        struct node* ptr_to = NULL;
        left = gen_rvalue(node->ast_node.binop_node.left, NULL);
		right = gen_rvalue(node->ast_node.binop_node.right, NULL);
		if (left != NULL){
            if (left->flag == T_TEMP_NODE && left->ast_node.temp_node.ary_temp != NULL){
                l_type = ast_typeof(left);
            }else{
		        l_type = ast_typeof(node->ast_node.binop_node.left);
            }
        }
        if (right != NULL){
            if (right->flag == T_TEMP_NODE && right->ast_node.temp_node.ary_temp != NULL){
                r_type = ast_typeof(right);
            }else{
                r_type = ast_typeof(node->ast_node.binop_node.right);
            }
        }
        if (opcode >= E_LT && opcode <= E_GT){
            // if an rvalue turns out to be a logical operation
            struct bblock* Bt, *Bf, *Bn;
            Bt = new_bb();
            Bf = new_bb();
            Bn = new_bb();
            zero = ast_new_const(0);
            one = ast_new_const(1);
            gen_condexpr(node, Bt, Bf);
            cur_bb = Bt;
            emit(QUAD_MOV, one, NULL, target);
            link_bb(cur_bb, ALWAYS, Bn, NULL);
            cur_bb = Bf;
            emit(QUAD_MOV, zero, NULL, target);
            link_bb(cur_bb, ALWAYS, Bn, NULL);
            cur_bb = Bn;
            return target;
        }
		if ((r_type->flag == E_CONSTANT || r_type->flag == T_SCALAR_NODE) && (l_type->flag == T_ARY_NODE || l_type->flag == T_PTR_NODE)){
			if (l_type->flag == T_ARY_NODE){
                fprintf(stderr,"I am an array %d\n", l_type->ast_node.ary_node.ary_size);
				ary_size = find_size(l_type->ast_node.ary_node.type);
            }
			else
				ary_size = find_size(l_type->ast_node.ptr_node.ptr_to_node);
		    fprintf(stderr,"array size is %d\n", ary_size);	
			ar_size_node = ast_new_const(ary_size);
			temper = new_temporary();
			emit(E_MUL, ar_size_node, right, temper);
			right = temper;
			ptr_to = ast_new_ptr();
			ptr_to->ast_node.ptr_node.ptr_to_node = l_type->ast_node.ary_node.type;
		}else if ((l_type->flag == E_CONSTANT || l_type->flag == T_SCALAR_NODE) && (r_type->flag == T_ARY_NODE || r_type->flag == T_PTR_NODE)){
            if (r_type->flag == T_ARY_NODE)
                ary_size = find_size(r_type->ast_node.ary_node.type);
            else
                ary_size = find_size(r_type->ast_node.ptr_node.ptr_to_node);
            ar_size_node = ast_new_const(ary_size);
            temper = new_temporary();
            ptr_to = ast_new_ptr();
            ptr_to->ast_node.ptr_node.ptr_to_node = r_type->ast_node.ary_node.type;
        }
		if (target == NULL){
			target = new_temporary();
			if (ptr_to != NULL){
				target->ast_node.temp_node.ary_temp = ptr_to->ast_node.ptr_node.ptr_to_node;
			}
		}
		emit(node->ast_node.binop_node.opcode, left, right, target);
		return target;

	}
    if (node->flag == E_DEREF){
        // if the node is a reference to an address
		struct node* temp;
		struct node* new_typeof = ast_typeof(node->ast_node.deref_node.dereferee);
        if (new_typeof->flag == T_ARY_NODE){
			temp = gen_rvalue(node->ast_node.deref_node.dereferee, NULL);
			// change the dereferreee from an array to a pointer
			node->ast_node.deref_node.dereferee = temp->ast_node.temp_node.ary_temp;
			if (target != NULL){
				emit(QUAD_LOAD, temp, NULL, target);
				return target;
			}
			return temp;
        }
        addr = gen_rvalue(node->ast_node.deref_node.dereferee, NULL);
        if (target == NULL)
            target = new_temporary();
        emit(QUAD_LOAD, addr, NULL, target);
        return target;
    }
	if (node->flag == E_FN_CALL){
		// get the arguments!
		struct node* args = node->ast_node.fn_call_node.arg;
		struct node* targs;
		struct node* i;
		int counter = 0;
		while (args != NULL){
			counter += 1;
			args = args->next;	
		}
		for (int k = 0; k < counter; k++){
			args = node->ast_node.fn_call_node.arg;
			// traverse list counter-1-i times
			for (int j = 0; j < counter-1-k ; j++){
				args = args->next;
			}
			targs = gen_rvalue(args, NULL);
			i = ast_new_const(counter-1-k);
			emit(QUAD_ARGS, i, targs, NULL);
		}
		if (target == NULL)
			target = new_temporary();	
		struct node* myConst = ast_new_const(node->ast_node.fn_call_node.num_args);
		emit(QUAD_CALL, node->ast_node.fn_call_node.caller, myConst, target);
		return target;
	}
	if (node->flag == E_LIST){
		return gen_rvalue(node->ast_node.elist_node.ptr_to_arg, NULL);
	}

    return NULL;
}

// This function starts from a certain node, and go down the AST to see what's the final AST form of the expression
struct node* ast_typeof(struct node* node){
	if (node == NULL) return NULL;
    if (node->flag == E_BINOP){
		struct node* left, *right;
		left = ast_typeof(node->ast_node.binop_node.left);
		right = ast_typeof(node->ast_node.binop_node.right);
		if ((left->flag == T_PTR_NODE||left->flag == T_ARY_NODE) && (right->flag == T_SCALAR_NODE || right->flag == E_CONSTANT)){
			// if it is a scalar adding an array, return a pointer to the array
			return left;
		}else if ((left->flag == T_SCALAR_NODE||left->flag == E_CONSTANT) && (right->flag == T_ARY_NODE || right->flag == T_PTR_NODE)){
			return right;
		}
	}else if (node->flag == I_VAR_NODE){
		return ast_typeof(node->next);
	}else if (node->flag == E_DEREF){
		return ast_typeof(node->ast_node.deref_node.dereferee);
	}else if (node->flag == T_TEMP_NODE && node->ast_node.temp_node.ary_temp != NULL){
        return node->ast_node.temp_node.ary_temp;
	}else if (node->flag == T_ARY_NODE){
		// creates a pointer that points to the type of node
		return node;
	}
	return node;
}

void emit(int opcode, struct node* left, struct node* right, struct node* target){
    struct quad* curr = cur_bb->list_of_quads;
    struct quad * n;
    if (curr == NULL){
        cur_bb->list_of_quads = (struct quad*) malloc(sizeof(struct quad));
        n = cur_bb->list_of_quads;
    }else{
        while(curr->next != NULL){
            curr = curr->next;
        }
        n = (struct quad*) malloc(sizeof(struct quad));
        curr->next = n;
    }
    n->opcode = opcode;
    n->result = target;
    n->src1 = left;
    n->src2 = right;    
}

// creates a new temporary node, store it in a master list of nodes
struct node* new_temporary(){
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->flag = T_TEMP_NODE;
    n->ast_node.temp_node.offset = stack_offset;
    int counter = 1;
    char temp_name[8];
    struct node* curr_node = head_temp;
    if (curr_node == NULL){
        head_temp = n;
    }else{
        counter = 2;
        while (curr_node->next != NULL){
            curr_node = curr_node->next;
            counter += 1;
        }
        curr_node->next = n;
    }
    // determine the name of the node
    if (counter < 10){
        sprintf(temp_name, "T0000%d",counter);
    }else if (counter < 100){
        sprintf(temp_name, "T000%d", counter);
    }else if (counter < 1000){
        sprintf(temp_name, "T00%d", counter);
    }else if (counter < 10000){
        sprintf(temp_name,"T0%d",counter);
    }else{
        sprintf(temp_name,"T%d",counter);
    }
    stack_offset += 4;
    n->ast_node.temp_node.name = (char*) malloc(sizeof(char)*8);
    strncpy(n->ast_node.temp_node.name, temp_name,7);
    return n;
}

void print_bb(struct bblock* bb){
    struct bblock* my_bb;
    struct quad* my_quad;
    struct bblock* brancher = NULL;
    my_bb = bb;
	char* bname;
	bname = (char*) malloc(sizeof(char)*1024);
    while(my_bb != NULL){
        my_quad = my_bb->list_of_quads;
        if (my_bb->visited != 1){
            my_bb->visited = 1;
			sprintf(bname, ".BB%d.%d", my_bb->fn_count, my_bb->bb_count);
            if (show_quads == 1)
                fprintf(stderr,"%s:\n", bname);
			inst_label(bname);
            while(my_quad != NULL){
			    if (my_quad->opcode >= QUAD_BRLT && my_quad->opcode <= QUAD_BRGE || 
                    my_quad->opcode == QUAD_BR){
				    print_branch(my_quad, my_bb);
                    break;
			    }else{
                    print_quad(my_quad);
                }
                my_quad = my_quad->next;
            }
        }
        if (my_bb->from_cond_block != NULL && my_bb->from_cond_block == my_bb->s_block){
            if (my_bb->p_block == NULL){
                break;  // while loop
            }else{
                // do while loop, at body
                my_bb = my_bb->s_block;
            }
        }else{
            // check whether it is a do while loop?
            if (my_bb->t_block != NULL && my_bb->t_block == my_bb->p_block){
                my_bb = my_bb->f_block;   
            }else{
                if (my_bb->s_block != NULL){
                    my_bb = my_bb->s_block;
                }else{
                    // check whether it is a for loop!
                    if (my_bb->t_block != my_bb->p_block){
                        break;
                    }
                    my_bb = my_bb->t_block; 
                }
            }
        }
    }
}

struct bblock* print_branch(struct quad* quad, struct bblock* bblock){
    if (show_quads == 1)
	    fprintf(stderr,"\t");
	switch(quad->opcode){
		case QUAD_BRLT:	
            if (show_quads == 1)
			    fprintf(stderr,"BRLT");
			inst_jump(QUAD_BRLT, "jnl", "jl", bblock->f_block, bblock->t_block);
			break;
        case QUAD_BREQ: 
            if (show_quads == 1)
			    fprintf(stderr,"BREQ");   
			inst_jump(QUAD_BREQ, "jne", "je", bblock->f_block, bblock->t_block);  
			break;
        case QUAD_BRNEQ: 
            if (show_quads == 1)
			    fprintf(stderr,"BRNEQ"); 
			inst_jump(QUAD_BRNEQ, "je", "jne", bblock->f_block, bblock->t_block);  
			break;
        case QUAD_BRGT: 
            if (show_quads == 1)
			    fprintf(stderr,"BRGT");
			inst_jump(QUAD_BRGT, "jng", "jg", bblock->f_block, bblock->t_block);     
			break;
        case QUAD_BRLE: 
            if (show_quads == 1)
			    fprintf(stderr,"BRLE");
			inst_jump(QUAD_BRLE, "jnle", "jle", bblock->f_block, bblock->t_block); 
			break;
        case QUAD_BRGE: 
            if (show_quads == 1)
			    fprintf(stderr,"BRGE"); 
			inst_jump(QUAD_BRGE, "jnge", "jge", bblock->f_block , bblock->t_block);
			break;
        case QUAD_BR:   
            if (show_quads == 1)
			    fprintf(stderr,"BR");
			inst_jump(QUAD_BR, "jmp", NULL, bblock->s_block, NULL);       
			break;
	}
    if (show_quads == 1)
	    fprintf(stderr,"\t");
    if (quad->opcode >= QUAD_BRLT && quad->opcode <= QUAD_BRGE){
        if (show_quads == 1)
    	    fprintf(stderr,".BB%d.%d, .BB%d.%d\n", bblock->f_block->fn_count, bblock->f_block->bb_count,
                                             bblock->t_block->fn_count, bblock->t_block->bb_count);
        if (bblock->t_block->visited == 0){
            print_bb(bblock->t_block);
        }
        if (bblock->f_block != bblock->t_block->s_block){
	        print_bb(bblock->f_block);
        }
        return bblock->t_block->s_block;
    }else{
        if (show_quads == 1)
            fprintf(stderr,".BB%d.%d\n", bblock->s_block->fn_count, bblock->s_block->bb_count);
        return bblock->s_block;
    }
}

// print quads
void print_quad(struct quad* curr_quad){
    // 1. res
    if (show_quads == 1){
        if (curr_quad->result != NULL){
            fprintf(stderr,"\t");
            print_node(curr_quad->result);
            fprintf(stderr," = ");
        }else{
            fprintf(stderr,"\t");
        }
    }
    // 2. opcode
    switch(curr_quad->opcode){
        case E_ADD:
            if (show_quads == 1) 
                fprintf(stderr, "ADD");
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);             break;
        case E_MINUS:
            if (show_quads == 1) 
                fprintf(stderr,"MINUS");    
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_MUL: 
            if (show_quads == 1)
			    fprintf(stderr,"MUL");
			inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
			break;
        case E_DIV:
            if (show_quads == 1) 
                fprintf(stderr,"DIV");
            inst_division(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_MOD:
            if (show_quads == 1) 
                fprintf(stderr,"MOD");
            inst_division(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_SHL: 
            if (show_quads == 1)
                fprintf(stderr,"SHL");  
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_SHR:
            if (show_quads == 1) 
                fprintf(stderr,"SHR");
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_XOR:
            if (show_quads == 1) 
                fprintf(stderr,"XOR");    
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_AND:
            if (show_quads == 1) 
                fprintf(stderr,"AND");
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_OR:
            if (show_quads == 1) 
                fprintf(stderr,"OR");
            inst_two_operands(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
            break;
        case E_BITNOT: 
            if (show_quads == 1)
                fprintf(stderr,"BNOT");
            inst_one_operand(curr_quad->opcode, curr_quad->result, curr_quad->src1);
            break;
        case E_UMINUS:
            if (show_quads == 1)
                fprintf(stderr,"UMIN");
            inst_one_operand(curr_quad->opcode, curr_quad->result, curr_quad->src1);
            break;
        case E_UPLUS: 
            if (show_quads == 1)
                fprintf(stderr,"UPLUS"); 
            inst_mov(curr_quad->opcode, curr_quad->result, curr_quad->src1);   
            break;
        case QUAD_LOAD: 
			if (show_quads == 1)
                fprintf(stderr,"LOAD");
			access_mem(curr_quad->opcode, curr_quad->src1, curr_quad->result);
			break;
        case QUAD_STORE: 
			if (show_quads == 1)
                fprintf(stderr,"STORE"); 
			access_mem(curr_quad->opcode, curr_quad->src2, curr_quad->src1);
			break;
        case QUAD_LEA: 
            if (show_quads == 1)
			    fprintf(stderr,"LEA");
			access_mem(curr_quad->opcode, curr_quad->src1, curr_quad->result);
			break;
        case QUAD_MOV:
            if (show_quads == 1)
                fprintf(stderr,"MOV");
            inst_mov(curr_quad->opcode, curr_quad->result, curr_quad->src1);
            break;
        case QUAD_CMP: 
            if (show_quads == 1)
                fprintf(stderr,"CMP");
            inst_cmp(curr_quad->src1, curr_quad->src2);
            break;
        case QUAD_RETURN: 
            if (show_quads == 1)
			    fprintf(stderr,"RETURN");
			if (curr_quad->src1 == NULL){
                inst_return(NULL);
            }else{
                inst_return(curr_quad->src1);
            }
			break;
		case QUAD_CALL:	
            if (show_quads == 1)
                fprintf(stderr,"CALL");	
            inst_fn_call(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);  
            break;
		case QUAD_ARGS: 
            if (show_quads == 1)
			    fprintf(stderr,"ARG");	  
			inst_fn_call(curr_quad->opcode, curr_quad->result, curr_quad->src1, curr_quad->src2);
			break;
        case QUAD_NOT:  
            if (show_quads == 1)
                fprintf(stderr,"NOT");
            inst_not_operator(curr_quad->result, curr_quad->src1);
            break;
    }
    if (show_quads == 1){
        if (curr_quad->src1 != NULL){
		    if (curr_quad->opcode == QUAD_LOAD || curr_quad->opcode == QUAD_STORE){
			    fprintf(stderr,"\t[");
    			print_node(curr_quad->src1);
	    		fprintf(stderr,"]");
		    }else{
        	    fprintf(stderr,"\t");
            	print_node(curr_quad->src1);
	    	}
        }
        if (curr_quad->src2 != NULL){
            fprintf(stderr,"\t,");
            print_node(curr_quad->src2);
        }
        fprintf(stderr,"\n");
    }
}

void print_node(struct node* my_node){
    switch(my_node->flag){
        case I_VAR_NODE: print_vars(my_node);    break;
		case I_FN_NODE:	fprintf(stderr,"$%s", my_node->ast_node.fn_node.node.name); break;
        case T_TEMP_NODE: fprintf(stderr,"%%%s",my_node->ast_node.temp_node.name);   break;
        case E_CONSTANT:  fprintf(stderr,"%d", my_node->ast_node.constant_node.value);  break;
        case E_STR:     fprintf(stderr,".string_%d", my_node->ast_node.constant_node.str_count); break;
        case E_CONST_CHAR: fprintf(stderr,"%c", my_node->ast_node.constant_node.char_value); break;
		default:    fprintf(stderr,"%d\n", my_node->flag); break;
    }

}

void print_vars(struct node* curr_node){
    if (curr_node->ast_node.var_node.stg == T_AUTO){
         // NOTE: Is this determined by the storage class?
        fprintf(stderr,"%s{lvar}", curr_node->ast_node.var_node.node.name);
    }else if (curr_node->ast_node.var_node.stg == T_EXTERN){
        fprintf(stderr,"%s{global}", curr_node->ast_node.var_node.node.name);
    }else if (curr_node->ast_node.var_node.stg == T_STATIC){
		fprintf(stderr,"%s.%d{static}", curr_node->ast_node.var_node.node.name, 
                                        curr_node->ast_node.var_node.static_count);
	}else{
        fprintf(stderr,"%s{wrong} %d", curr_node->ast_node.var_node.node.name,
                                       curr_node->next->ast_node.var_node.stg);
    }

}


int find_size(struct node* node){
    int node_types;
    if (node->flag == I_VAR_NODE){
        return find_size(node->next);
    }else if (node->flag == T_ARY_NODE){
        fprintf(stderr,"size of array is %d\n", node->ast_node.ary_node.ary_size);
        return node->ast_node.ary_node.ary_size*find_size(node->ast_node.ary_node.type);
    }else if (node->flag == T_PTR_NODE){
        return find_size(node->ast_node.ptr_node.ptr_to_node);
    }else if (node->flag == T_SCALAR_NODE){
        switch(node->ast_node.scalar_node.type){
            case T_SHORT:   return SIZEOF_SHORT;
            case T_INT:     return SIZEOF_INT;
            case T_LONG:    return SIZEOF_LONG;
            case T_CHAR:    return SIZEOF_CHAR;
        }
    }else if (node->flag == E_DEREF){
		return find_size(node->ast_node.deref_node.dereferee);
	}else if (node->flag == E_BINOP){
		int left = find_size(node->ast_node.binop_node.left);
		int right = find_size(node->ast_node.binop_node.right);
		if (left > right){
			return left;
		}else{
			return right;
		}
	}else if (node->flag == T_TEMP_NODE && node->ast_node.temp_node.ary_temp != NULL){
		return find_size(node->ast_node.temp_node.ary_temp);
	}
    return 0;
}

