#include "ast.h"
#include "quads.h"
void inst_label(char* name);
void inst_txt_directive();
void inst_static_directive();
void inst_file_directive(char* name);
void inst_local_directive(char* name, int stat_count);
void inst_comm_directive(char* name, int size, int alignment, int stat_count);
void inst_func_directive(char* func_name);
void inst_directive(char* directive);
void inst_func_prologue();
void inst_two_operands(int opcode, struct node* res, struct node* src1, struct node* src2);
void inst_print_vars(struct node* n);
void inst_return(struct node* n);
void inst_jump(int opcode, char* false_inst, char* true_inst, struct bblock* false_arm, struct bblock* true_arm);
