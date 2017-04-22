#include <stdio.h>
#include "quads.h"
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
    fprintf(stdout, "\tsubl\t$%d,%%esp\n", stack_offset);
    if (stack_offset %16 != 0){
        int padding = stack_offset%16;
        fprintf(stdout,"\tsubl\t$%d,%%esp\n", padding);
    }
	return;
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
void inst_fn_call(struct node* fn_node){
	
}

void inst_return(struct node* n){
	fprintf(stdout,"\tleave\n");
	fprintf(stdout,"\tret\n");
	return;
}
