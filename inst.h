#include "ast.h"
#include "quads.h"
void inst_label(char* name);
void inst_txt_directive();
void inst_static_directive();
void inst_file_directive(char* name);
void inst_comm_directive(char* name, int size, int alignment);
void inst_func_directive(char* func_name);
void inst_directive(char* directive);
void inst_func_prologue();
void inst_return(struct node* n);
void inst_jump(int opcode, char* false_inst, char* true_inst, struct bblock* false_arm, struct bblock* true_arm);
