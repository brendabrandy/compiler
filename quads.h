extern int fn_counter;
int bb_counter;
struct bblock* cur_bb;
struct quad{
    int opcode;
    struct quad* next;
	struct bblock *t_block, *f_block;
    struct node *result, *src1, *src2;
};

struct bblock{
    int fn_count, bb_count;
	int next_linker;
    int visited;
    struct quad *list_of_quads;
	struct bblock * t_block, * f_block;
    struct bblock * from_cond_block;
    struct bblock * s_block;
    struct bblock * p_block;
};

void print_bb(struct bblock* bb);
void link_bb(struct bblock* bb, int linkage, struct bblock* b1, struct bblock* b2);
void print_quads();
struct node* gen_return(struct node* return_node);
struct bblock* print_branch(struct quad* quad, struct bblock* block);
struct node* ast_typeof(struct node* node);
struct bblock* new_bb();
void generate_quads(struct node* stmt, int scope, struct node* ident);
void gen_quads(struct node* stmt, struct bblock* break_node, struct bblock* cont_node);
struct node* gen_assign(struct node* node);
struct node* gen_lvalue(struct node* node, int *mode);
struct node* gen_rvalue(struct node* node, struct node* target);
void emit(int opcode, struct node* left, struct node* right, struct node* target);
struct node* new_temporary();
void print_quad(struct quad* curr_quad);
void print_node(struct node* my_node);
void print_vars(struct node* curr_node);
int find_size(struct node* node);
void gen_condexpr(struct node* cond, struct bblock* Bt, struct bblock* Bf);
struct node* gen_if(struct node* if_node, struct bblock* break_node, struct bblock* cont_node);
struct node* gen_while(struct node* while_node);
struct node* gen_do(struct node* do_node);
struct node* gen_for(struct node* for_node);
struct node* gen_break(struct bblock* break_node);
struct node* gen_cont(struct bblock* cont_node);
