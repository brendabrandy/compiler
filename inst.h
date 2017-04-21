#include "ast.h"
#include "quads.h"
void inst_label(char* name);
void inst_func_prologue();
void inst_return(struct node* n);
void inst_jump(int opcode, char* false_inst, char* true_inst, struct bblock* false_arm, struct bblock* true_arm);
