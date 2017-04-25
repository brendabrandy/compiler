#include <stdio.h>
#include "inst.h"
#include "flags.h"
// are we assuming the user declares all vars first?
// how to determine padding?
// can we just print to stdout?
// NOTE : Need to support string literals to support printf
// NOTE : Do we need to make directives for implicit global vars?
// QUES : How do we determine the padding?
// NOTE : when we say something like int a = 'c' , do we promote char to int?

extern int stack_offset;

// prints the name of the label
void inst_label(char* name){
	fprintf(stdout,"%s:\n", name);
	return;
}

void inst_file_directive(char* name){
	fprintf(stdout, "\t.file\t%s", name);
}

void inst_txt_directive(){
	fprintf(stdout,"\t.text\n");
}

// prints the .comm block for bss block
void inst_comm_directive(char* name, int size, int alignment, int stat_count){
    if (stat_count >= 0){
        fprintf(stdout,"\t.comm\t%s.%d,%d,%d\n", name, stat_count, size, alignment);
    }else{
	    fprintf(stdout,"\t.comm\t%s,%d,%d\n", name, size, alignment);
    }
}

void inst_local_directive(char* name, int stat_count){
    if (stat_count >= 0){
        fprintf(stdout,"\t.local\t%s.%d\n", name, stat_count);
    }else{
        fprintf(stdout,"\t.local\t%s\n", name);
    }
}

// prints the directives for function
void inst_func_directive(char* func_name){
	fprintf(stdout,"\t.globl\t%s\n", func_name);
	fprintf(stdout,"\t.type\t%s,@function\n", func_name);
}

// generates the function prologue
void inst_func_prologue(){
	fprintf(stdout, "\tpushl\t%%ebp\n");
	fprintf(stdout, "\tmovl\t%%esp, %%ebp\n");
    fprintf(stdout, "\tsubl\t$%d, %%esp\n", stack_offset);
    if (stack_offset %16 != 0){
        int padding = stack_offset%16;
        fprintf(stdout,"\tsubl\t$%d, %%esp\n", padding);
    }
	return;
}

void inst_mov(int opcode, struct node* res, struct node* src1){
    fprintf(stdout,"\tmovl\t");
    inst_print_vars(src1);
    fprintf(stdout,", ");
    inst_print_vars(res);
    fprintf(stdout,"\n");
}


void access_mem(int opcode, struct node* addr, struct node* reg){
	switch(opcode){
		case QUAD_LOAD:
			// the form will be in reg = LOAD [addr]
            // leal addr %ecx
            // movl (%ecx), %ebx
            // movl %ebx, reg
            fprintf(stdout, "\tleal\t");
            inst_print_vars(addr);
            fprintf(stdout, ", %%ecx\n");
			fprintf(stdout, "\tmovl\t(%%ecx), %%ebx\n");
            fprintf(stdout,"\tmovl\t%%ebx, ");
			inst_print_vars(reg);
			fprintf(stdout,"\n");
			break;
		case QUAD_STORE:
			// the form wil be in STORE reg, [addr]
            // leal addr, %ecx
            // movl reg, %ebx
            // movl %ebx,(%ecx)
			fprintf(stdout,"\tleal\t");
			inst_print_vars(addr);
			fprintf(stdout,", %%ecx\n");
            fprintf(stdout,"\tmovl\t");
			inst_print_vars(reg);
			fprintf(stdout,", %%ebx\n");
            fprintf(stdout,"\tmovl\t%%ebx, (%%ecx)\n");
			break;
		case QUAD_LEA:
			// the form will be in reg = LEA addr
			fprintf(stdout,"\tleal\t");
			inst_print_vars(addr);
			fprintf(stdout,", ");
			inst_print_vars(reg);
			fprintf(stdout,"\n");
			break;
	}	
}

// generates assembly for quads expression like res = OPCODE src1
// general strategy will be
// mov src1, %ecx
// OPCODE %ecx
// mov %ecx, res
void inst_one_operand(int opcode, struct node* res, struct node* src1){
    fprintf(stdout,"\tmovl\t");
    inst_print_vars(src1);
    fprintf(stdout,", %%ecx\n\t");
    switch(opcode){
        case E_BITNOT:
            fprintf(stdout,"notl"); 
            break;
        case E_UMINUS:
            fprintf(stdout,"negl");
            break;
    }
    fprintf(stdout,"\t%%ecx\n\tmovl\t%%ecx, ");
    inst_print_vars(res);
    fprintf(stdout,"\n");
    
}
// mov src2, %ecx
// div src1, %ecx
// mov %eax, res for division 
// mov %edx, res for modulo
void inst_division(int opcode, struct node* res, struct node* src1, struct node* src2){
    fprintf(stdout,"\tmovl\t");
    inst_print_vars(src2);
    fprintf(stdout,", %%ecx\n");
    fprintf(stdout,"\tdivl\t");
    inst_print_vars(src1);
    fprintf(stdout,", %%ecx");
    switch(opcode){
        case E_DIV:
            fprintf(stdout,"\tmovl\t%%eax, ");
            break;
        case E_MOD:
            fprintf(stdout,"\tmovl\t%%edx, ");
            break;
    }
    inst_print_vars(res);
    fprintf(stdout,"\n");
}


// generates assembly for quads expression like res = OPCODE src1, src2
// general strategy will be
// mov src2, %ecx
// OPCODE src1, %ecx
// mov %ecx, res 
void inst_two_operands(int opcode, struct node* res, struct node* src1, struct node* src2){
    // print mov src2, %ecx
    fprintf(stdout,"\tmovl\t");
    inst_print_vars(src2);
    fprintf(stdout,", %%ecx\n\t");
    // print opcode
    switch(opcode){
        case E_ADD:
            fprintf(stdout,"addl");
            break;
        case E_MINUS:
            fprintf(stdout,"subl");
            break;
        case E_SHL:
            fprintf(stdout,"sall");
            break;
        case E_SHR:
            fprintf(stdout,"shrl");
            break;
        case E_XOR:
            fprintf(stdout,"xorl");
            break;
		case E_MUL:
			fprintf(stdout,"imull");
			break;
        case E_AND:
            fprintf(stdout,"andl");
            break;
        case E_OR:
            fprintf(stdout,"orl");
            break;
    }
    // print src1, %ecx
    fprintf(stdout,"\t");
    inst_print_vars(src1);
    fprintf(stdout,", %%ecx\n");
    // print mov %ecx, res
    fprintf(stdout,"\tmovl\t%%ecx, ");
    inst_print_vars(res);
    fprintf(stdout,"\n");
}

void inst_print_vars(struct node* n){
    // what if it's an arugment?
    switch(n->flag){
        case I_VAR_NODE:
            // get the offset
            if (n->ast_node.var_node.stg == T_AUTO)
                fprintf(stdout,"-$%d(%%ebp)", n->ast_node.var_node.offset);
            else if (n->ast_node.var_node.stg == T_EXTERN)
                fprintf(stdout,"%s", n->ast_node.var_node.node.name);
            else if (n->ast_node.var_node.stg == T_STATIC)
                fprintf(stdout,"%s.%d", n->ast_node.var_node.node.name, n->ast_node.var_node.static_count);
            break;
        case I_FN_NODE:
            fprintf(stdout,"%s", n->ast_node.fn_node.node.name);
            break;
        case T_TEMP_NODE:
            fprintf(stdout,"-$%d(%%ebp)", n->ast_node.temp_node.offset);
            break;
        case E_CONSTANT:
            fprintf(stdout,"-$%d", n->ast_node.constant_node.value);
            break;
    }
}

// generates assembly for branching
void inst_jump(int opcode, char* false_inst, char* true_inst, struct bblock* false_arm, struct bblock* true_arm){
	switch(opcode){
		case QUAD_BR:
			fprintf(stdout, "\t%s\t.BB%d.%d\n", false_inst, false_arm->fn_count, false_arm->bb_count);
			break;
		default:
			fprintf(stdout, "\t%s\t.BB%d.%d\n", false_inst, false_arm->fn_count, false_arm->bb_count);
			fprintf(stdout, "\t%s\t.BB%d.%d\n", true_inst, true_arm->fn_count, true_arm->bb_count);
			break;
	};
}

// generates a function call
void inst_fn_call(int opcode, struct node* res, struct node* src1, struct node* src2){
    switch(opcode){
        case QUAD_CALL:
            fprintf(stdout,"\tcall\t");
            inst_print_vars(src1);
            fprintf(stdout,"\n");
            if (res != NULL){
                fprintf(stdout,"\tmovl\t%%eax, ");
                inst_print_vars(res);
                fprintf(stdout,"\n");
            }
            break;
    }
}

void inst_return(struct node* n){
    if (n != NULL){
        fprintf(stdout, "\tmovl\t");
        inst_print_vars(n);
        fprintf(stdout,", %%eax\n");
    }
	fprintf(stdout,"\tleave\n");
	fprintf(stdout,"\tret\n");
	return;
}
