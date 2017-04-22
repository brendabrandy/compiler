%{
    #include <stdio.h>
    #include "sym_table.h"
    extern FILE* yyin;
    extern int yyparse();
    extern int yylex();
    char *fname;
    int fn_counter = 0;
    extern struct scope_node* curr_scope;
    struct node* list;
	extern int stat_count;
    extern int line_num;
    struct node* list_header;   // the start of the AST of expressions and statements
    void yyerror(char *s);
    int main();
    // precedence goes from low to high 
    // sizeof, casting
%}

%union{
        struct string_lit{
            char *ident_name;
            char * string_literal;
            int string_size;
        }string_lit;
        char *ident_name;
        int constant;
        struct number{
            unsigned long long int number;
            long double doub_number;
            int num_numberspec;
            int num_sizespec;
            int num_unsigned;
        }number;
        struct char_lit{
            char actual_char;
        }char_lit;
        int scalar_type;    // temporary area to store type_spec, stg_spec, func_spec and type_qual
        struct node* node;
} 
%start start
%token <number> NUMBER 
%token <ident_name>IDENT
%token <string_lit> STRING
%token <char_lit> CHARLIT
%token <keywords> BREAK CASE CONTINUE DEFAULT DO ELSE ENUM FOR GOTO IF RETURN SWITCH TYPEDEF WHILE
%token <op> INDSEL PLUSPLUS MINUSMINUS SIZEOF SHL SHR GTEQ LTEQ EQEQ NOTEQ
%token <op> LOGAND LOGOR INDIRECTION ADDRESS 
%token <op> PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ XOREQ
%token <stg> AUTO EXTERN REGISTER STATIC
%token <qual> CONST RESTRICT VOLATILE
%token <type> CHAR INT DOUBLE FLOAT LONG _BOOL UNION STRUCT _COMPLEX SHORT ENUMBER INLINE SIGNED UNSIGNED VOID _IMAGINARY

%nonassoc ELLIPSIS
%left ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ XOREQ
%right '?' ':'
%left LOGOR
%left LOGAND
%left '|'
%left '^'
%left '&'
%left EQEQ NOTEQ
%left '<' '>' LTEQ GTEQ
%left SHL SHR
%left '+' '-'
%left '*' '/' '%'
%right INDIRECTION ADDRESS UPLUS UMINUS '!' '~' SIZEOF PREFIX_PLUSPLUS PREFIX_MINUSMINUS
%left POSTFIX_PLUSPLUS POSTFIX_MINUSMINUS INT INDSEL '.'

%type<node> primary_expr multiplicative_expr additive_expr shift_expr relational_expr equality_expr
%type<node> postfix_expr cast_expr subscript_expr unary_expr postinc_expr expr_list
%type<node> postdec_expr const_expr assignment_expr comma_expr comp_selec_expr function_call

%type<node> iterative_stmt conditional_stmt for_expr stmt decl_or_stmt decl_or_stmt_list
%type<node> null_stmt return_stmt top_level_decl
%type<scalar_type> type_qual func_spec type_spec stg_spec

%type<node> simple_decl decl_spec init_decl_list direct_decl func_decl
%type<node> pointer_decl pointer param_type_list ident_list full_func_decl 
%type<node> param_list param_decl declarator compound_stmt arr_decl struct_spec
%type<node> struct_type_ref component_decl_list component_declarator struct_type_def component_decl_spec
%type<node> union_type_ref union_type_def forward_decl label
%type<node> conditional_expr expr logical_or_expr logical_and_expr bitwise_and_expr bitwise_or_expr
bitwise_xor_expr conditional_body
%%
    start:                               {}
            | start top_level_decl       {}
            ;

    top_level_decl:   decl      {}
                    | func_def  {}
                    ;

    func_def:     full_func_decl compound_stmt   {}
                ; 

    full_func_decl: decl_spec func_decl {$$ = add_type_node($2, $1);
                                         $$ = insert_sym($$->ast_node.common_node.name,
                                                         $$->ast_node.common_node.nspace,
                                                         $$,1);}
    
    decl_or_stmt_list:    decl_or_stmt    {struct node* n = (struct node*) malloc(sizeof(struct node));
                                           $$ = n;
                                           $$->flag = LIST;  
                                           $$->ast_node.list_node.head_list = NULL; 
                                           if ($1 != NULL){
                                                $$->ast_node.list_node.head_list = $1; 
                                          }}
                        | decl_or_stmt_list decl_or_stmt  {struct node* n = $1->ast_node.list_node.head_list;
                                                           if ($2 != NULL){
                                                            if (n == NULL){
                                                                $1->ast_node.list_node.head_list = $2;
                                                            }else{
                                                                while (n->next != NULL){n = n->next;}
                                                                n->next = $2;
                                                            }
                                                          }
                                                          $$ = $1;}
                        ;

    decl_or_stmt:     decl  {$$ = NULL;}
                    | stmt  {}
                    ;
    
    decl:    decl_spec init_decl_list ';'                          {}
           | forward_decl                                          {}
           | struct_spec ';'                                       {}
           ;
    
    decl_spec:    stg_spec              {$$ = ast_new_scalar_type($1);}
	            | type_spec		        {$$ = ast_new_scalar_type($1);}
	            | struct_spec           {}
                | type_qual		        {$$ = ast_new_scalar_type($1);}
	            | func_spec		        {$$ = ast_new_scalar_type($1);}
	            | decl_spec type_spec   {$$ = ast_add_scalar_type($1,$2);}
                | decl_spec struct_spec {$2->next = $1;}
	            | decl_spec stg_spec    {$$ = ast_add_scalar_type($1,$2);}
	            | decl_spec type_qual   {$$ = ast_add_scalar_type($1,$2);}
	            | decl_spec func_spec   {$$ = ast_add_scalar_type($1,$2);}	
	            ;	

    init_decl_list:   declarator	                    {
                                                         add_type_node($1,$<node>0);
                                                         $$ = insert_sym($1->ast_node.common_node.name,
                                                                        $1->ast_node.common_node.nspace,
                                                                        $1,1);
                                                        }
    	            | init_decl_list ',' declarator    {
                                                        add_type_node($3, $<node>0);
                                                        $$ = insert_sym($3->ast_node.common_node.name,
                                                                        $3->ast_node.common_node.nspace,
                                                                        $3,1);
                                                        }
                                                        
	            ;	
	
    stg_spec:     AUTO	    {$$ = T_AUTO;}
  	            | EXTERN	{$$ = T_EXTERN;}
	            | REGISTER	{$$ = T_REGISTER;}
	            | STATIC	{$$ = T_STATIC;}
	            ;	
	
    func_spec:    INLINE	{$$ = T_INLINE;}
	        ;	
	
    type_spec:    SHORT                     {$$ = T_SHORT;}
	            | SHORT INT                 {$$ = T_SHORT;}
	            | SIGNED SHORT              {$$ = T_SHORT;}
	            | SIGNED SHORT INT          {$$ = T_SHORT;}
                | INT                       {$$ = T_INT;}
	            | SIGNED INT                {$$ = T_INT;}
	            | SIGNED                    {$$ = T_INT;}
	            | LONG                      {$$ = T_LONG;}
                | LONG INT                  {$$ = T_LONG;}
	            | SIGNED LONG               {$$ = T_LONG;}
	            | SIGNED LONG INT           {$$ = T_LONG;}
                | LONG LONG                 {$$ = T_LONGLONG;}
	            | LONG LONG INT             {$$ = T_LONGLONG;}
	            | SIGNED LONG LONG          {$$ = T_LONGLONG;}
                | SIGNED LONG LONG INT      {$$ = T_LONGLONG;}
                | UNSIGNED SHORT            {$$ = T_USHORT;}
                | SHORT UNSIGNED            {$$ = T_USHORT;}
                | UNSIGNED                  {$$ = T_UINT;}
                | UNSIGNED LONG             {$$ = T_ULONG;}
                | LONG UNSIGNED             {$$ = T_ULONG;}
                | UNSIGNED LONG LONG        {$$ = T_ULONGLONG;}
                | LONG LONG UNSIGNED        {$$ = T_ULONGLONG;}
	            | UNSIGNED SHORT INT        {$$ = T_USHORT;}
                | SHORT UNSIGNED INT        {$$ = T_USHORT;}
	            | UNSIGNED INT              {$$ = T_UINT;}
	            | UNSIGNED LONG INT         {$$ = T_ULONG;}
                | LONG UNSIGNED INT         {$$ = T_ULONG;}            
	            | UNSIGNED LONG LONG INT    {$$ = T_ULONGLONG;}
                | LONG LONG UNSIGNED INT    {$$ = T_ULONGLONG;}
                | CHAR                      {$$ = T_CHAR;}
	            | SIGNED CHAR               {$$ = T_SCHAR;}
	            | UNSIGNED CHAR             {$$ = T_UCHAR;}
                | _BOOL                     {$$ = T_BOOL;}
                | FLOAT                     {$$ = T_FLOAT;}
	            | DOUBLE                    {$$ = T_DOUBLE;}
	            | LONG DOUBLE               {$$ = T_LONGDOUBLE;}
	            | FLOAT _COMPLEX            {$$ = T_FLOATCOMPLEX;}
	            | DOUBLE _COMPLEX           {$$ = T_DOUBLECOMPLEX;}
	            | LONG DOUBLE _COMPLEX      {$$ = T_LONGDOUBLECOMPLEX;}
	            | VOID	                    {$$ =  T_VOID;}
	        ;	

    struct_spec:     enum_type_spec        {}
                   | struct_type_spec      {}
                   | union_type_spec       {}
                   ;

    type_qual:    CONST     {$$ = T_CONST;}	
	            | VOLATILE	{$$ = T_VOLATILE;}
	            | RESTRICT	{$$ = T_RESTRICT;}
	            ;	
	
    declarator:    pointer_decl	{}
	             | direct_decl	{}
	             ;	
    direct_decl:     simple_decl        {}
	               | '(' declarator ')'	{}
	               | arr_decl	        {}
                   | func_decl          {}
	               ;

    simple_decl:     IDENT   {$$ = ast_new_ident($1,I_NODE);}	
                   ;
    pointer_decl:     pointer direct_decl	{$$ = add_type_node($2,$1);}
	                ;	
	
    pointer:      '*'	                        {$$ = ast_new_ptr();}
	            | '*' pointer                   {$$ = ast_new_ptr();
                                                 $2->ast_node.ptr_node.ptr_to_node = $$;}
	            ;	
    	
    abstract_decl:    pointer	                    {}
                    | direct_abstract_decl	        {}
                    | pointer direct_abstract_decl	{}
                    ;	
	
	arr_decl:     direct_decl '[' ']'	        {$$ = ast_new_ary(0);
                                                 $$ = add_type_node($1,$$);}
	            | direct_decl '[' NUMBER ']'	{$$ = ast_new_ary($3.number);
                                                 $$ = add_type_node($1, $$);}
	            ;	
	

	func_decl:    direct_decl '(' param_type_list ')'	{$$ = ast_new_func($1);
                                                         $$->next->ast_node.type_fn_node.arg = $3;
                                                         }
	            | direct_decl '(' ')' 	                {$$ = ast_new_func($1);}
	            | direct_decl '(' ident_list ')' 	    {$$ = ast_new_func($1);
                                                         $$->next->ast_node.type_fn_node.arg = $3;}
	            ;	

  	param_type_list:      param_list	            {}
	                    | param_list ',' ELLIPSIS	{}
	                    ;	
		
	param_list:       param_decl	            {}
	                | param_list ',' param_decl	{$$ = ast_func_add_arg($1, $3);}
	                ;	
		
	param_decl:       decl_spec declarator	    {$$ = ast_func_make_arg($1, $2);}
	                | decl_spec	                {$$ = ast_func_make_arg($1, NULL);}
	                | decl_spec abstract_decl	{}
	                ;	
	
	enum_type_spec:   enum_type_def     {}
	                | enum_type_ref     {}
	                ;
	
	enum_type_def:    ENUM '{' enum_def_list '}'             {}
	                | ENUM IDENT '{' enum_def_list '}'       {}
	                | ENUM '{' enum_def_list ',' '}'         {}
	                | ENUM IDENT '{' enum_def_list ',' '}'   {}
	                ;
	
	enum_type_ref:    ENUM IDENT {}
	                ; 
	
    enum_def_list:    enum_constant_def                     {}
                    | enum_def_list ',' enum_constant_def   {}
                    ;

    enum_constant_def:    IDENT             {}
                        | IDENT '=' expr    {}
                        ;

    forward_decl:         STRUCT IDENT ';' {
                                            struct sym_node* struct_sym;
                                            if ((struct_sym = lookup($2,N_TAGS,1)) == NULL){
                                                $$ = ast_new_struct($2, I_STRUCT_TAG_NODE);
                                                $$ = insert_sym($$->ast_node.struct_tag_node.node.name,N_TAGS,$$,1);
                                            }else{
                                                printf("You are wrong!\n");
                                            }}

    struct_type_spec:     struct_type_def   struct_block {}
                        | struct_type_ref   {}
                        ;

    struct_type_def:      STRUCT '{'        {$$ = ast_new_struct(NULL, I_STRUCT_TAG_NODE) ; 
                                             $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                             N_TAGS, $$, 1);
                                             if ($$ != NULL){
                                                enter_block($$, 1);
                                                $$->ast_node.struct_tag_node.sym_table = curr_scope;
                                             
                                             }
                                             }

                        | STRUCT IDENT '{'  {
                                             struct sym_node* struct_sym;
                                             if (curr_scope != NULL && (struct_sym = lookup($2, N_TAGS, 1)) != NULL){
                                                $$ = struct_sym->ast_node;   
                                                $$->ast_node.struct_tag_node.node.line_num = line_num; 
                                            }else{
                                                $$ = ast_new_struct($2, I_STRUCT_TAG_NODE); 
                                                $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                             N_TAGS,$$, 1); 

                                             }
                                             if ($$ != NULL){
                                                create_sym_table($$->ast_node.struct_tag_node.node.name, 1);
                                                $$->ast_node.struct_tag_node.sym_table = curr_scope;
                                             }}
                        ;

    struct_block:        field_list '}'     {$<node>0->ast_node.struct_tag_node.isComplete = 1;
                                             struct sym_node* node = curr_scope->sym_node;
                                             //print_debug_stmt($<node>0);
                                             curr_scope = curr_scope->prev_scope;
                                             }

    struct_type_ref:      STRUCT IDENT  {
                                         struct sym_node* struct_sym;
                                         if ((struct_sym = lookup($2,N_TAGS,0)) != NULL){
                                            $$ = struct_sym->ast_node;
                                         }else{
                                            $$ = ast_new_struct($2, I_STRUCT_TAG_NODE);
                                            $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                            N_TAGS,$$, 1);
                                         }}
                        ;

    field_list:   component_decl                {}
                | field_list component_decl     {}
                ;

    component_decl:   component_decl_spec component_decl_list ';'     {}
                    ;
    component_decl_spec:      type_spec     {$$ = ast_new_scalar_type($1);}
                            | struct_spec   {}

    component_decl_list:      component_declarator                          {add_type_node($1,$<node>0);
                                                                             $$ = insert_sym($1->ast_node.common_node.name,
                                                                                             N_MINIDEFS,$1,1);}
                            | component_decl_list ',' component_declarator  {add_type_node($3,$<node>0);
                                                                             $$ = insert_sym($3->ast_node.common_node.name,
                                                                                             N_MINIDEFS,$3,1);}
                            ;

    component_declarator:     declarator        {}
                            | bit_field         {}
                            ;


    bit_field:    ':' NUMBER             {}
                | declarator ':' NUMBER  {}
                ;

    union_type_spec:      union_type_def struct_block {}
                        | union_type_ref              {}
                        ;

    union_type_def:   UNION '{'                         {$$ = ast_new_struct(NULL, I_UNION_TAG_NODE) ; 
                                                         $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                                        N_TAGS, $$, 1);
                                                         if ($$ != NULL){
                                                            enter_block($$, 1);
                                                            $$->ast_node.struct_tag_node.sym_table = curr_scope;
                                                        }}

                    | UNION IDENT '{'                   {$$ = ast_new_struct($2, I_UNION_TAG_NODE);
                                                         $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                                         N_TAGS, $$,1);
                                                         if ($$ != NULL){
                                                            enter_block($$,1);
                                                            $$->ast_node.struct_tag_node.sym_table = curr_scope;
                                                         }}
                    ;
    
    union_type_ref:   UNION IDENT   {struct sym_node* struct_sym;
                                     if ((struct_sym = lookup($2,N_TAGS,0)) != NULL){
                                        $$ = struct_sym->ast_node;
                                     }else{
                                        $$ = ast_new_struct($2, I_UNION_TAG_NODE);
                                        $$ = insert_sym($$->ast_node.struct_tag_node.node.name,
                                                        N_TAGS,$$, 1);
                                     }}

    direct_abstract_decl:     '(' abstract_decl ')'                         {}
                            | direct_abstract_decl '['NUMBER']'                {}
                            | direct_abstract_decl '[' expr ']'             {}
                            | direct_abstract_decl '[' '*' ']'              {}
                            | direct_abstract_decl '(' param_type_list ')'  {}
                            | '[' NUMBER ']'                                   {}
                            | '[' expr ']'                                  {}
                            | '[' '*' ']'                                   {}
                            | '(' param_type_list ')'                       {}
                            | '[' ']'                                       {}
                            | '(' ')'                                       {}
                            ;
    stmt:     expr ';'                      {$$ = $1;}
            | label ':' stmt                {
                                             if ($1->flag == ST_CASE){
                                                $1->ast_node.case_node.stmt = $3;
                                             }else if ($1->flag == ST_DEFAULT){
                                                $1->ast_node.default_node.stmt = $3;
                                             }else{
                                                $1->ast_node.stmt_label_node.stmt = $3;
                                             }
                                             $$ = $1;}
            | compound_stmt                 {$$ = $1;}
            | conditional_stmt              {$$ = $1;}
            | iterative_stmt                {$$ = $1;}
            | SWITCH '(' expr ')' stmt      {$$ = ast_new_switch($3, $5); 
                                             make_switch_map($$, $5);}
            | BREAK ';'                     {$$ = ast_new_stmt(ST_BREAK);}
            | CONTINUE ';'                  {$$ = ast_new_stmt(ST_CONTINUE);}
            | GOTO IDENT ';'                    {struct sym_node* n;
                                             if ((n = lookup($2, N_LABELS, 0)) == NULL){
                                                $$ = ast_new_ident($2,I_STMT_LABEL_NODE);
                                                $$ = insert_sym($2,N_LABELS,$$,1);
                                            }else{
                                                $$ = n->ast_node;
                                            }
                                             $$ = ast_new_goto($$);}
            | return_stmt                   {}
            | null_stmt                     {$$ = NULL;}
            ;

    conditional_stmt:     IF '(' expr ')' {$<node>$ = ast_new_if($3, NULL,NULL);} conditional_body {$$ = $<node>5;}
                        ;

    conditional_body:     stmt {$<node>0->ast_node.if_node.action = $1;$$ = $<node>0;}
                        | stmt ELSE stmt {$<node>0->ast_node.if_node.else_action = $3; $<node>0->ast_node.if_node.action = $1;$$ = $<node>0;}

    iterative_stmt:       DO {$<node>$ = ast_new_do(NULL,NULL);} stmt WHILE '(' expr ')' ';'    {$<node>2->ast_node.do_node.cond = $<node>6;
                                                                                                 $<node>2->ast_node.do_node.stmt = $3;
                                                                                                 $$ = $<node>2;}
                        | WHILE '('expr ')' {$<node>$ = ast_new_while($3, NULL);} stmt            {$<node>5->ast_node.while_node.action = $6;
                                                                                                  $$ = $<node>5;}
                        | FOR for_expr stmt                 {$2->ast_node.for_node.stmt = $3; $$ = $2;}
                        ;

    label:    IDENT                {struct sym_node* n;
                                     if ((n = lookup($1, N_LABELS, 0)) == NULL){
                                        $$ = ast_new_ident($1,I_STMT_LABEL_NODE);
                                        $$ = insert_sym($1,N_LABELS,$$,1);
                                    }else{
                                        $$ = n->ast_node;
                                    }}
            | CASE const_expr       {$$ = ast_new_case($2);}
            | DEFAULT               {$$ = ast_new_case(NULL);}
            ;


    const_expr:   NUMBER        {$$ = ast_new_const($1.number);}
                | CHARLIT       {$$ = ast_new_const_char($1.actual_char);}
                ;

    for_expr:     '(' ';' ';' ';' ')'            {$$ = ast_new_for(NULL,NULL,NULL);}
                | '(' expr ';' ';' ')'           {$$ = ast_new_for($2,NULL,NULL);}
                | '(' ';' expr ';' ')'           {$$ = ast_new_for(NULL,$3,NULL);}
                | '(' ';' ';' expr ')'           {$$ = ast_new_for(NULL,NULL,$4);}
                | '(' expr ';' expr ';' ')'      {$$ = ast_new_for($2,$4,NULL);}
                | '(' expr ';' ';' expr ')'      {$$ = ast_new_for($2,NULL,$5);}
                | '(' ';' expr ';' expr ')'      {$$ = ast_new_for(NULL,$3,$5);}
                | '(' expr ';' expr ';' expr ')' {$$ = ast_new_for($2,$4,$6);}
                ;

    compound_stmt:    '{'{enter_block($<node>0, 0);} decl_or_stmt_list '}' { print_func_dump(0, $3, $<node>0);
                                                                             if (curr_scope->scope_num == S_FUNCTION)
                                                                                fn_counter += 1;
                                                                             generate_quads($3, curr_scope->scope_num, $<node>0);
                                                                             leave_block();
                                                                             $$ = $3;}
                    | '{' '}'   {}
                    ;

    return_stmt:      RETURN expr ';'   {$$ = ast_new_return($2);}
                    | RETURN ';'        {$$ = ast_new_return(NULL);}
                    ;
    
    null_stmt:        ';' {}
                    ; 

    primary_expr:     IDENT         {struct sym_node* n = lookup($1, N_OTHERS, 0);
                                     $$ = n->ast_node;}
                    | NUMBER        {$$ = ast_new_const($1.number);}
                    | '(' expr ')'  {$$ = $2;}
                    ;

    postfix_expr:     primary_expr      {}
                    | subscript_expr    {}
                    | comp_selec_expr   {}
                    | function_call     {}
                    | postinc_expr      {}
                    | postdec_expr      {}
                    ;

    subscript_expr:   postfix_expr '[' expr ']'   {$$ = ast_new_binop(E_ADD,$1,$3);
                                                   $$ = ast_new_deref($$);}
                    ;
    
    function_call:    postfix_expr '(' expr_list ')'  {$$ = ast_new_fn_call($3, $1);}
                    | postfix_expr '(' ')'            {$$ = ast_new_fn_call(NULL,$1);}
                    ;
    
    expr_list:    assignment_expr                     {$$ = ast_new_expr_arg(NULL,$1);}
                | expr_list ',' assignment_expr       {$$ = ast_new_expr_arg($1, $3);}
                ;

    comp_selec_expr:    postfix_expr '.' IDENT        {$$ = ast_new_indsel(E_DOT, $1, $3);}
                      | postfix_expr INDSEL IDENT     {$$ = ast_new_indsel(E_INDSEL, $1, $3);}
                      ;
    
    postinc_expr:     postfix_expr PLUSPLUS %prec POSTFIX_PLUSPLUS      {$$ = ast_new_unary(E_POSTINC, $1);}
                    ;
    postdec_expr:     postfix_expr MINUSMINUS %prec POSTFIX_MINUSMINUS  {$$ = ast_new_unary(E_POSTDEC, $1);}
                    ;

    
    cast_expr:    unary_expr                    {}
                | '(' type_spec ')' cast_expr   {}
                | '(' struct_spec ')' cast_expr {}
                ;

    unary_expr:   postfix_expr                                  {}
                | SIZEOF  '(' type_spec ')'                     {$$ = ast_new_scalar_type($3);
                                                                 $$ = ast_new_unary(E_SIZEOF, $$);}
                | SIZEOF unary_expr                             {$$ = ast_new_unary(E_SIZEOF, $2);} 
                | '-' cast_expr %prec UMINUS                    {$$ = ast_new_unary(E_UMINUS, $2);}
                | '+' cast_expr %prec UPLUS                     {$$ = ast_new_unary(E_UPLUS, $2);}
                | '!' cast_expr                                 {$$ = ast_new_unary(E_LOGNOT, $2);}
                | '~' cast_expr                                 {$$ = ast_new_unary(E_BITNOT, $2);}
                | '&' cast_expr %prec ADDRESS                   {$$ = ast_new_unary(E_ADDRESS, $2);}
                | '*' cast_expr %prec INDIRECTION               {$$ = ast_new_deref($2);}
                | PLUSPLUS unary_expr %prec PREFIX_PLUSPLUS     {$$ = ast_new_const(1);
                                                                 $$ = ast_new_binop(E_ADD, $2, $$);
                                                                 $$ = ast_new_assign($2, $$);}
                | MINUSMINUS unary_expr %prec PREFIX_MINUSMINUS {$$ = ast_new_const(1);
                                                                 $$ = ast_new_binop(E_MINUS, $2, $$);
                                                                 $$ = ast_new_assign($2, $$);}
                ;

    multiplicative_expr:      cast_expr                            {}
                            | multiplicative_expr '*' cast_expr    {$$ = ast_new_binop(E_MUL,$1,$3);}
                            | multiplicative_expr '/' cast_expr    {$$ = ast_new_binop(E_DIV,$1,$3);}
                            | multiplicative_expr '%' cast_expr    {$$ = ast_new_binop(E_MOD,$1,$3);}
                            ;
    additive_expr:    multiplicative_expr                       {}
                    | additive_expr '+' multiplicative_expr     {$$ = ast_new_binop(E_ADD,$1,$3);}
                    | additive_expr '-' multiplicative_expr     {$$ = ast_new_binop(E_MINUS,$1,$3);}
                    ;

    shift_expr:       additive_expr                 {}
                    | shift_expr SHL additive_expr  {$$ = ast_new_binop(E_SHL, $1,$3);}
                    | shift_expr SHR additive_expr  {$$ = ast_new_binop(E_SHR,$1,$3);}
                    ;

    relational_expr:      shift_expr
                        | relational_expr '<' shift_expr    {$$ = ast_new_binop(E_LT,$1,$3);}
                        | relational_expr '>' shift_expr    {$$ = ast_new_binop(E_GT,$1,$3);}
                        | relational_expr LTEQ shift_expr   {$$ = ast_new_binop(E_LTEQ, $1,$3);}
                        | relational_expr GTEQ shift_expr   {$$ = ast_new_binop(E_GTEQ, $1,$3);}
                        ;
    
    equality_expr:    relational_expr                       {}
                    | equality_expr EQEQ relational_expr    {$$ = ast_new_binop(E_EQEQ, $1, $3);}
                    | equality_expr NOTEQ relational_expr   {$$ = ast_new_binop(E_NOTEQ, $1, $3);}
                    ;

    bitwise_or_expr:      bitwise_xor_expr                      {}
                        | bitwise_or_expr '|' bitwise_xor_expr  {$$ = ast_new_binop(E_OR,$1,$3);}
                        ;

    bitwise_xor_expr:     bitwise_and_expr                      {}
                        | bitwise_xor_expr '^' bitwise_and_expr {$$ = ast_new_binop(E_XOR,$1,$3);}
                        ;
    
    bitwise_and_expr:     equality_expr                         {}
                        | bitwise_and_expr '&' equality_expr    {$$ = ast_new_binop(E_AND,$1,$3);}
                        ;
    
    logical_or_expr:      logical_and_expr                          {}
                        | logical_or_expr LOGOR logical_and_expr    {$$ = ast_new_binop(E_LOGOR,$1,$3);}
                        ;

    logical_and_expr:     bitwise_or_expr                           {}
                        | logical_and_expr LOGAND bitwise_or_expr   {$$ = ast_new_binop(E_LOGAND,$1,$3);}
                        ;

    conditional_expr:     logical_or_expr                                   {}
                        | logical_or_expr '?' expr ':' conditional_expr     {$$ = ast_new_binop(E_ACTION,$3,$5);
                                                                             $$ = ast_new_binop(E_COND,$1,$$);}
                        ;

    assignment_expr:      conditional_expr	                    {}
                        | unary_expr '=' assignment_expr	    {$$ = ast_new_assign($1, $3);}
                        | unary_expr PLUSEQ assignment_expr	    {$$ = ast_new_binop(E_ADD, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr MINUSEQ assignment_expr	{$$ = ast_new_binop(E_MINUS, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr TIMESEQ assignment_expr	{$$ = ast_new_binop(E_MUL, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr DIVEQ assignment_expr	    {$$ = ast_new_binop(E_DIV, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr MODEQ assignment_expr	    {$$ = ast_new_binop(E_MOD, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr SHLEQ assignment_expr	    {$$ = ast_new_binop(E_SHL, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr SHREQ assignment_expr	    {$$ = ast_new_binop(E_SHR, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr ANDEQ assignment_expr	    {$$ = ast_new_binop(E_AND, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr OREQ assignment_expr	    {$$ = ast_new_binop(E_OR, $1, $3);  
                                                                 $$ = ast_new_assign($1, $$);}
                        | unary_expr XOREQ assignment_expr	    {$$ = ast_new_binop(E_XOR, $1, $3);
                                                                 $$ = ast_new_assign($1, $$);}
			            ;

    comma_expr:   assignment_expr	                {}
                | comma_expr ',' assignment_expr	{struct node* n = $1;
                                                     while(n->next != NULL){n=n->next;}
                                                     n->next = $3;}
                ;	
	
    expr:     comma_expr	{}
            ;	
	
    ident_list:   IDENT	                {$$ = ast_new_ident($1, 0);}
                | ident_list ',' IDENT	{$$ = ast_new_ident($3, 0);}
                ;	


%%

int main(int argc, char* argv[]){
    yyin = fopen(argv[1],"r");
    list = (struct node*) malloc(sizeof(struct node));
	list->flag = LIST;
	stat_count = 0;
    do{
        yyparse();
    }while(!feof(yyin));
    return 0;
    // pointers and array pointers
}

void yyerror(char *s){
    fprintf(stderr , "syntax error: %s\n", s);
}
