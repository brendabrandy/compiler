// Name : Brenda So
// Date : 3/4/2017
// Goal : to make an AST for my parser
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flags.h"
struct node * ast_new_ident(char *name, int type);
struct node * ast_new_scalar_type(int scalar_type);
struct node * ast_add_scalar_type(struct node* n,int scalar_type);
struct node * add_type_node(struct node* ident_node, struct node* type_node);
struct node * ident_var_type(struct node* ident_node);
struct node * ast_new_func(struct node* ident_node);
struct node * ast_new_ptr();
struct node * ast_new_ary(int size);
struct node * ast_func_make_arg(struct node* decl_specs, struct node* ident_node);
struct node * ast_func_add_arg(struct node* first_arg, struct node* current_arg);
struct node * ast_add_ptr_to_decl(struct node* ptr_node, struct node* direct_decl);
struct node * ast_new_struct(char* name, int flag);
struct node * ast_new_binop(int opcode, struct node* left, struct node* right);
struct node * ast_new_assign(struct node* lval, struct node* rval);
struct node * ast_new_for(struct node* init_clause, struct node* end_cond, struct node* action);
struct node * ast_new_while(struct node* cond, struct node* stmt);
struct node * ast_new_do(struct node* stmt, struct node* cond);
struct node * ast_new_if(struct node* cond, struct node* action, struct node* else_action);
struct node * ast_new_const(int value);
struct node * ast_new_unary(int opcode, struct node* operand);
struct node * ast_new_indsel(int flag, struct node* selector, char* selectee);
struct node * ast_new_deref(struct node* dereferee);
struct node * ast_new_fn_call(struct node* expr_list, struct node* fn_caller);
struct node * ast_new_switch(struct node* switch_cond, struct node* body);
struct node * ast_new_stmt(int type_flag);
struct node * ast_new_return(struct node* return_type);
struct node * ast_new_const_char(char value);
struct node * ast_new_case(struct node *const_expr);
struct node * ast_new_goto(struct node* label);
struct node * ast_new_expr_arg(struct node* prev_node, struct node* new_arg);


struct TYPE_ARY_NODE{
    int ary_size;
    struct node* type;
};

struct TYPE_SCALAR_NODE{
    int type;
    int stg_class;  // temporary space for the variable storage class
    int qualifier;
    int inline_spec;
};

struct TYPE_FN_NODE{
    struct node* return_type;
    struct node *arg; 
};

struct TYPE_PTR_NODE{
    struct node* ptr_to_node;
};

struct TYPE_ARG_NODE{
    struct node * ident;
    struct node * type;
    struct node * next_arg;
};


struct IDENT_COMMON_NODE{
    char *name;     // name of the variable, if it has one
    int line_num;   // line number where the symbol is first defined
    char *fname; // filename where the variable is defined 
    int nspace;  // namespace of the node, 0 : others, 1 : tags, 2 : labels
    int flag;
};

struct IDENT_VAR_NODE{
    struct IDENT_COMMON_NODE node;
    int stg;    // type of storage class,0 for extern, 1 for auto, 2 for static, 3 for 
    int offset; // offset within stack frame
};

struct IDENT_FN_NODE{
    struct IDENT_COMMON_NODE node;
    int stg;                 // type of storage class   (extern or static)
    int inline_spec; // whether the inline specifier is present (either 1 or 0)
    int isDefined;  // whether a definition of the function is seen yet
};

struct IDENT_STRUCT_TAG_NODE{
    struct IDENT_COMMON_NODE node;
    int size;
    struct scope_node* sym_table;    // pointer to symbol table containing member definitions
    int isComplete;     // whether the definition is complete or not    
};

struct IDENT_ENUM_TAG_NODE{
    struct IDENT_COMMON_NODE node;
    int isComplete; //whether the definition is complete or not
};

struct IDENT_ENUM_CONSTANT_NODE{
    struct IDENT_COMMON_NODE node;
    struct IDENT_ENUM_TAG_NODE* enum_tag;   // what enum tag this enum constant refers to
};

struct IDENT_STMT_LABEL_NODE{
    struct IDENT_COMMON_NODE node;
    struct node* stmt;
};

struct IDENT_TYPEDEF_NODE{
    struct IDENT_COMMON_NODE node;
    void * equiv_type;      // pointer to equivalent type
};

struct IDENT_MEMBER_NODE{
    struct IDENT_COMMON_NODE node;
    int offset;     // offset within struct
    int width;      // bitfield width
    int bit_offset; // bit offset
};

struct IDENT_BIT_FIELD{
    struct IDENT_COMMON_NODE node;
    int num_bits;
};

struct TEMP_NODE{
    char* name;
	struct node* ary_temp;
    int offset;
};

struct EXPR_BINOP_NODE{
    struct node* left;
    struct node* right;
    int opcode;
};

struct EXPR_CONSTANT_NODE{
    int value;
    char char_value;
};

struct EXPR_UNARY_NODE{
    int opcode;
    struct node* operand;
};

struct EXPR_INDSEL_NODE{
    struct node* selector;
    char* selectee;
};

struct EXPR_ELIST_NODE{
	struct node* ptr_to_arg;
};

struct EXPR_DEREF_NODE{
    struct node* dereferee;
};

struct EXPR_FN_CALL_NODE{
    struct node* caller;
    struct node* arg;
    int num_args;
};

struct STMT_ASSIGN_NODE{
    struct node* lval;
    struct node* rval;
};

struct STMT_IF_NODE{
    struct node* cond;
    struct node* action;
    struct node* else_action;
};

struct STMT_WHILE_NODE{
    struct node* cond;
    struct node* action;
};

struct STMT_FOR_NODE{
    struct node* init_clause;
    struct node* end_cond;
    struct node* action_clause;
    struct node* stmt;
};

struct STMT_DO_NODE{
    struct node* stmt;
    struct node* cond;
};

struct STMT_RETURN_NODE{
    struct node* return_item;
};

struct STMT_SWITCH_NODE{
    struct node* expr_node;
    struct node* stmt;
    struct node* label_maps;
};

struct STMT_SWITCH_MAP{
    struct node* const_expr;
    struct node* case_stmt;
};

struct STMT_GOTO_NODE{
    struct node* stmt;
};

struct STMT_CASE_NODE{
    struct node* const_expr; 
    struct node* stmt;
};

struct STMT_DEFAULT_NODE{
    struct node* stmt;
};

struct LIST_NODE{
    struct node* head_list;
};

struct node{
    union ast_node{
        struct IDENT_COMMON_NODE        common_node;
        struct IDENT_VAR_NODE           var_node;
        struct IDENT_FN_NODE            fn_node;
        struct IDENT_STRUCT_TAG_NODE    struct_tag_node;
        struct IDENT_ENUM_TAG_NODE      enum_tag_node;
        struct IDENT_ENUM_CONSTANT_NODE enum_constant_node;
        struct IDENT_STMT_LABEL_NODE    stmt_label_node;
        struct IDENT_TYPEDEF_NODE       typedef_node;
        struct IDENT_MEMBER_NODE        member_node;
        struct IDENT_BIT_FIELD          bit_field_node;
        struct TYPE_SCALAR_NODE         scalar_node;
        struct TYPE_FN_NODE             type_fn_node;
        struct TYPE_PTR_NODE            ptr_node;
        struct TYPE_ARG_NODE            arg_node;
        struct TYPE_ARY_NODE            ary_node;
        struct EXPR_BINOP_NODE          binop_node;
        struct EXPR_UNARY_NODE          unary_node;
        struct EXPR_INDSEL_NODE         indsel_node;
        struct EXPR_DEREF_NODE          deref_node;
        struct EXPR_CONSTANT_NODE       constant_node;
        struct EXPR_FN_CALL_NODE        fn_call_node;
		struct EXPR_ELIST_NODE			elist_node;
        struct STMT_ASSIGN_NODE         assign_node;
        struct STMT_IF_NODE             if_node;
        struct STMT_WHILE_NODE          while_node;
        struct STMT_FOR_NODE            for_node;
        struct STMT_DO_NODE             do_node;
        struct STMT_SWITCH_MAP          switch_map;
        struct STMT_RETURN_NODE         return_node;
        struct STMT_SWITCH_NODE         switch_node; 
        struct STMT_GOTO_NODE           goto_node;  
        struct STMT_CASE_NODE           case_node; 
        struct STMT_DEFAULT_NODE        default_node; 
        struct TEMP_NODE              temp_node;
        struct LIST_NODE                list_node;
    }ast_node;
    struct node* next;
    int flag;
};

