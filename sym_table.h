#include "quads.h"
#include "flags.h"
#include "ast.h"
struct scope_node{
    struct scope_node* prev_scope;
    char *name;
    char *fname;
    int line_num;
    int scope_num;
    struct sym_node* sym_node;  // my symbol table is a linked list
};

struct sym_node{
    struct node* ast_node;
    struct sym_node* next;
    char *sym_name;
    int nspace;
    struct sym_node* prev;
};

void print_debug_stmt(struct node* n);
void create_sym_table(char* name, int num);
void destroy_sym_table();
void print_type(struct node* ptr);
void enter_block(struct node* n, int num);
void leave_block();
struct node* insert_into_list();
void print_func_dump(int indent, struct node* n, struct node* ident);
void print_stmt(struct node* stmt, int indent);
void make_switch_map(struct node* switch_body, struct node* stmt);
struct sym_node* lookup(char *name, int nspace, int confine_to_current_scope);
struct node* insert_sym(char* name, int nspace, struct node* new_node, int new_def);
int offset_inc(struct node* n);
