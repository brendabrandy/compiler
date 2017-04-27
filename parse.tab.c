/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "sym_table.h"
    extern FILE* yyin;
    extern int yyparse();
    extern int yylex();
    int show_lex;
    int show_decl;
    int show_ast;
    int show_quads;
    int show_targetcode;
    char *fname;
    int string_count;
    int fn_counter = 0;
    extern struct scope_node* curr_scope;
    struct node* list;
	extern int static_count;
    extern int line_num;
    struct node* list_header;   // the start of the AST of expressions and statements
    void yyerror(char *s);
    int main();
    // precedence goes from low to high 
    // sizeof, casting

#line 93 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    STRING = 260,
    CHARLIT = 261,
    BREAK = 262,
    CASE = 263,
    CONTINUE = 264,
    DEFAULT = 265,
    DO = 266,
    ELSE = 267,
    ENUM = 268,
    FOR = 269,
    GOTO = 270,
    IF = 271,
    RETURN = 272,
    SWITCH = 273,
    TYPEDEF = 274,
    WHILE = 275,
    INDSEL = 276,
    PLUSPLUS = 277,
    MINUSMINUS = 278,
    SIZEOF = 279,
    SHL = 280,
    SHR = 281,
    GTEQ = 282,
    LTEQ = 283,
    EQEQ = 284,
    NOTEQ = 285,
    LOGAND = 286,
    LOGOR = 287,
    INDIRECTION = 288,
    ADDRESS = 289,
    PLUSEQ = 290,
    MINUSEQ = 291,
    TIMESEQ = 292,
    DIVEQ = 293,
    MODEQ = 294,
    SHLEQ = 295,
    SHREQ = 296,
    ANDEQ = 297,
    OREQ = 298,
    XOREQ = 299,
    AUTO = 300,
    EXTERN = 301,
    REGISTER = 302,
    STATIC = 303,
    CONST = 304,
    RESTRICT = 305,
    VOLATILE = 306,
    CHAR = 307,
    INT = 308,
    DOUBLE = 309,
    FLOAT = 310,
    LONG = 311,
    _BOOL = 312,
    UNION = 313,
    STRUCT = 314,
    _COMPLEX = 315,
    SHORT = 316,
    ENUMBER = 317,
    INLINE = 318,
    SIGNED = 319,
    UNSIGNED = 320,
    VOID = 321,
    _IMAGINARY = 322,
    ELLIPSIS = 323,
    UPLUS = 324,
    UMINUS = 325,
    PREFIX_PLUSPLUS = 326,
    PREFIX_MINUSMINUS = 327,
    POSTFIX_PLUSPLUS = 328,
    POSTFIX_MINUSMINUS = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parse.y" /* yacc.c:355  */

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

#line 230 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "parse.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  424

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     2,     2,     2,    82,    75,     2,
      93,    94,    80,    78,    69,    79,    91,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    92,
      76,    70,    77,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    95,     2,    96,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,    73,    98,    86,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    83,    84,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,    99,   100,   103,   106,   111,   118,
     130,   131,   134,   135,   136,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   151,   157,   166,   167,   168,
     169,   172,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   217,   218,   219,   222,   223,   224,   227,   228,
     230,   231,   232,   233,   236,   238,   241,   242,   246,   247,
     248,   251,   253,   258,   261,   262,   266,   267,   270,   271,
     274,   275,   276,   279,   280,   283,   284,   285,   286,   289,
     292,   293,   296,   297,   300,   309,   310,   313,   323,   340,
     348,   359,   360,   363,   365,   366,   368,   371,   376,   377,
     381,   382,   385,   386,   389,   397,   406,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   427,   428,
     437,   438,   439,   440,   442,   443,   444,   452,   453,   456,
     456,   459,   460,   462,   462,   465,   465,   467,   470,   477,
     478,   482,   483,   486,   487,   488,   489,   490,   491,   492,
     493,   496,   496,   502,   505,   506,   509,   512,   514,   515,
     516,   517,   520,   521,   522,   523,   524,   525,   528,   532,
     533,   536,   537,   540,   541,   544,   546,   550,   551,   552,
     555,   556,   558,   559,   560,   561,   562,   563,   564,   565,
     568,   573,   574,   575,   576,   578,   579,   580,   583,   584,
     585,   588,   589,   590,   591,   592,   595,   596,   597,   600,
     601,   604,   605,   608,   609,   612,   613,   616,   617,   620,
     621,   625,   626,   627,   629,   631,   633,   635,   637,   639,
     641,   643,   645,   649,   650,   655,   658,   659
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "STRING", "CHARLIT",
  "BREAK", "CASE", "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM", "FOR",
  "GOTO", "IF", "RETURN", "SWITCH", "TYPEDEF", "WHILE", "INDSEL",
  "PLUSPLUS", "MINUSMINUS", "SIZEOF", "SHL", "SHR", "GTEQ", "LTEQ", "EQEQ",
  "NOTEQ", "LOGAND", "LOGOR", "INDIRECTION", "ADDRESS", "PLUSEQ",
  "MINUSEQ", "TIMESEQ", "DIVEQ", "MODEQ", "SHLEQ", "SHREQ", "ANDEQ",
  "OREQ", "XOREQ", "AUTO", "EXTERN", "REGISTER", "STATIC", "CONST",
  "RESTRICT", "VOLATILE", "CHAR", "INT", "DOUBLE", "FLOAT", "LONG",
  "_BOOL", "UNION", "STRUCT", "_COMPLEX", "SHORT", "ENUMBER", "INLINE",
  "SIGNED", "UNSIGNED", "VOID", "_IMAGINARY", "ELLIPSIS", "','", "'='",
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UPLUS", "UMINUS", "'!'", "'~'", "PREFIX_PLUSPLUS",
  "PREFIX_MINUSMINUS", "POSTFIX_PLUSPLUS", "POSTFIX_MINUSMINUS", "'.'",
  "';'", "'('", "')'", "'['", "']'", "'{'", "'}'", "$accept", "start",
  "top_level_decl", "func_def", "full_func_decl", "decl_or_stmt_list",
  "decl_or_stmt", "decl", "decl_spec", "init_decl_list", "stg_spec",
  "func_spec", "type_spec", "struct_spec", "type_qual", "declarator",
  "direct_decl", "simple_decl", "pointer_decl", "pointer", "abstract_decl",
  "arr_decl", "func_decl", "param_type_list", "param_list", "param_decl",
  "enum_type_spec", "enum_type_def", "enum_type_ref", "enum_def_list",
  "enum_constant_def", "forward_decl", "struct_type_spec",
  "struct_type_def", "struct_block", "struct_type_ref", "field_list",
  "component_decl", "component_decl_spec", "component_decl_list",
  "component_declarator", "bit_field", "union_type_spec", "union_type_def",
  "union_type_ref", "direct_abstract_decl", "stmt", "conditional_stmt",
  "@1", "conditional_body", "iterative_stmt", "@2", "@3", "label",
  "const_expr", "for_expr", "compound_stmt", "$@4", "return_stmt",
  "null_stmt", "primary_expr", "postfix_expr", "subscript_expr",
  "function_call", "expr_list", "comp_selec_expr", "postinc_expr",
  "postdec_expr", "cast_expr", "unary_expr", "multiplicative_expr",
  "additive_expr", "shift_expr", "relational_expr", "equality_expr",
  "bitwise_or_expr", "bitwise_xor_expr", "bitwise_and_expr",
  "logical_or_expr", "logical_and_expr", "conditional_expr",
  "assignment_expr", "comma_expr", "expr", "ident_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    44,
      61,    63,    58,   124,    94,    38,    60,    62,    43,    45,
      42,    47,    37,   324,   325,    33,   126,   326,   327,   328,
     329,    46,    59,    40,    41,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF -250

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-250)))

#define YYTABLE_NINF -169

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -250,  1198,  -250,    26,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,   -47,    -5,    16,  -250,    29,    30,    20,
    -250,   147,   159,  -250,  -250,  -250,    -4,  -250,  1138,  -250,
    -250,  -250,     6,  -250,  -250,  -250,  -250,  -250,  -250,   331,
    -250,  -250,   331,  -250,    17,   120,  -250,  -250,  -250,    69,
      23,   125,    88,  -250,   -15,  -250,  -250,   145,  -250,  -250,
     130,   149,  -250,  -250,   160,   161,   108,  -250,  -250,    31,
     138,    75,    -1,  -250,  -250,  -250,  -250,  -250,  -250,    84,
    -250,  -250,    40,  -250,   124,  -250,  -250,  -250,  -250,   235,
    -250,    41,  -250,   120,   168,   -27,  -250,  -250,  -250,   189,
    -250,  -250,  -250,  -250,  -250,  -250,   190,  -250,  -250,   191,
    -250,  -250,   358,   152,  -250,   156,  -250,    75,  -250,   860,
      11,    84,  -250,  -250,   243,   179,    14,  -250,  -250,   -18,
    1021,    12,  -250,  -250,  -250,  -250,  -250,   180,  -250,  -250,
     162,    81,   164,  -250,  -250,   165,   249,   167,   871,   171,
     181,  1055,  1055,  1080,  1021,  1021,  1021,  1021,  1021,  1021,
    -250,   761,   262,  -250,  -250,  1138,  -250,  -250,  -250,   185,
    -250,  -250,  -250,  -250,   431,  -250,  -250,  -250,  -250,  -250,
    -250,   153,    83,    25,    93,    19,    79,   188,   209,   220,
      18,   266,  -250,  -250,   229,   210,  -250,  -250,  -250,  -250,
     599,  -250,   211,   234,  -250,   -16,   208,  -250,  -250,   303,
      41,  -250,    13,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,   453,   936,   453,   230,  1021,  -250,   232,
    1021,  1021,  1021,  -250,  -250,   806,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,   236,   237,   238,  -250,  -250,   453,
     325,  -250,  -250,   330,   610,  1021,  1021,  1021,  1021,  1021,
    1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,
    1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,
    1021,  1021,  1021,  1021,  1021,  1021,  1021,  -250,   543,   423,
    -250,    37,  -250,   129,  -250,  1220,   332,  -250,  -250,  -250,
    -250,  -250,   315,   962,   246,  -250,  -250,   245,  -250,   251,
     252,   255,  1021,  1021,  -250,  -250,  -250,  -250,  -250,    -2,
    -250,   247,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,    83,    83,    25,    25,
      93,    93,    93,    93,    19,    19,   209,   220,    79,   266,
     278,   188,  -250,  -250,   257,   258,   260,   482,  -250,   261,
     129,  1245,  1089,  -250,  -250,  -250,   265,   971,   285,   995,
    -250,   453,  -250,  -250,  -250,  -250,  1021,  -250,  -250,  1021,
    -250,  -250,  -250,  -250,  -250,   259,   274,   491,   283,  1021,
     297,   299,   677,   702,   302,   453,  -250,   453,  -250,  -250,
    -250,  -250,  -250,  -250,   304,  -250,  -250,  -250,   305,  -250,
     306,   714,   389,  -250,  -250,   310,  -250,  -250,  -250,   324,
     453,  -250,  -250,  -250
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,    27,    28,    29,    30,    75,    77,
      76,    61,    36,    66,    65,    39,    64,     0,     0,    32,
      31,    38,    49,    71,     3,     5,     0,     4,     0,    15,
      19,    16,    17,    18,    72,   103,   104,    13,    73,     0,
     116,    74,     0,   133,   109,     0,    69,    68,    40,    67,
      43,    51,   136,   134,   120,   117,    33,    48,    62,    37,
      41,    34,    63,    56,    50,    47,   181,     6,    84,     0,
      86,     0,     0,    22,    24,    20,    21,    23,    25,    79,
      80,    78,     0,    82,    83,    14,   124,   125,   115,     0,
     121,     0,   132,     0,   112,     0,   110,    70,    44,    53,
      58,   135,   114,   118,    55,    42,    45,    35,    57,    52,
      54,   183,     0,   120,    87,     0,    83,     0,    12,     0,
       0,    85,   119,   122,     0,   128,     0,   126,   129,     0,
       0,     0,   105,    60,    46,    59,   188,   187,   190,   189,
       0,     0,     0,   170,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,     8,    10,     0,    11,   151,   152,     0,
     150,   157,   158,   192,   210,   193,   195,   194,   196,   197,
     221,   207,   225,   228,   231,   236,   243,   247,   239,   241,
     249,   245,   251,   263,   265,     0,    81,    26,   266,    94,
     101,    17,     0,    96,    98,     0,     0,    91,   130,     0,
       0,   123,     0,   106,   187,   113,   107,   111,   154,   171,
     172,   169,   155,     0,     0,     0,     0,     0,   185,     0,
       0,     0,     0,   219,   220,     0,   212,   217,   207,   214,
     213,   218,   215,   216,     0,     0,     0,   182,     9,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
     100,    88,   102,    89,    93,     0,     0,    95,    92,   131,
     127,   108,     0,     0,     0,   167,   156,     0,   184,     0,
       0,     0,     0,     0,   191,   149,   204,   203,   200,     0,
     201,     0,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   252,   222,   223,   224,   226,   227,   229,   230,
     235,   234,   232,   233,   237,   238,   240,   242,   244,   246,
       0,   248,   264,   147,     0,     0,   188,     0,   146,     0,
      90,     0,     0,    97,    99,   267,     0,     0,     0,     0,
     159,     0,   165,   211,   208,   209,     0,   199,   198,     0,
     137,   145,   142,   144,   143,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,   202,   250,
     141,   138,   140,   139,     0,   173,   176,   175,     0,   174,
       0,     0,   161,   160,   166,     0,   179,   178,   177,     0,
       0,   164,   180,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,  -250,  -250,  -250,  -250,   263,   419,     8,  -250,
     -13,     4,     1,    10,     9,   -43,   -74,  -250,  -250,   -69,
     142,  -250,   403,  -249,  -250,   137,  -250,  -250,  -250,   341,
     -56,  -250,  -250,  -250,   393,  -250,  -250,   350,  -250,  -250,
     231,  -250,  -250,  -250,  -250,   151,  -213,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,   414,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -152,  -132,
     -40,   -39,   -48,   -38,   166,   187,   169,   184,  -250,   183,
      95,  -200,  -250,  -130,  -250
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,    25,    26,   162,   163,   164,   200,    72,
      29,    30,    31,   201,    33,    78,    79,    80,    81,    82,
     292,    83,   116,   202,   203,   204,    34,    35,    36,    95,
      96,    37,    38,    39,    88,    40,    89,    90,    91,   126,
     127,   128,    41,    42,    43,   293,   166,   167,   395,   413,
     168,   223,   397,   169,   221,   225,   170,   112,   171,   172,
     173,   174,   175,   176,   319,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   205
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     215,   114,   237,   239,   240,   241,   242,   243,   121,    28,
     302,    32,   305,    46,   206,    73,    94,    94,   229,   233,
     234,   236,   238,   238,   238,   238,   238,   238,   115,    75,
      44,   246,    74,    52,    54,   113,   315,    77,    76,   355,
      86,    68,   131,    86,    68,    68,   274,   275,   125,    87,
     283,   212,    87,   296,   320,    47,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   376,   117,    48,
      49,   132,    50,    56,   197,   217,    98,   102,   297,    68,
     213,    51,   103,   210,   219,    57,   352,   220,    99,   284,
      86,   118,   377,    66,   304,   276,   277,   307,    85,    87,
     309,   310,   246,   270,   271,   246,   211,   207,   278,   279,
     216,   301,   385,   124,    93,   333,   334,   335,   272,   273,
     165,    70,    32,    45,    94,   321,    53,    55,    55,    97,
     288,   291,   289,    71,    71,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,    73,   238,   350,    70,   217,   290,   396,   359,
     374,   375,   244,   267,   268,   269,    75,   125,    71,    74,
     165,   245,    32,   368,    77,    76,   398,   119,   100,   120,
     238,   238,   412,   105,   414,   101,   106,    73,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   104,    58,
      59,    75,   107,    60,    74,   241,   111,   423,    61,    77,
      76,    62,    63,   108,   110,    64,   109,   121,    70,   291,
      65,    -7,   361,   266,   362,   238,   340,   341,   342,   343,
     336,   337,   388,   338,   339,   241,   311,   391,   130,   394,
     344,   345,   133,   134,   135,   115,   208,   238,     3,   103,
     196,   209,  -168,   226,   218,   238,   222,   249,   224,   404,
     227,   280,   408,   410,   230,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   231,     3,   145,   146,   147,   148,
     149,   419,   150,   281,   151,   152,   153,    11,    12,    13,
      14,    15,    16,    17,    69,   282,    19,   285,   286,    21,
      22,    23,   287,   295,   298,   294,   299,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   306,    19,   308,    20,    21,    22,    23,   316,
     312,   313,   314,   122,   317,   366,   365,   154,   369,   370,
     155,   156,   157,   378,     3,   371,   372,   158,   159,   373,
     379,   380,   381,   400,   160,   161,   382,   384,   389,    66,
     247,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     401,     3,   145,   146,   147,   148,   149,   392,   150,   403,
     151,   152,   153,    11,    12,    13,    14,    15,    16,    17,
      69,   405,    19,   406,   411,    21,    22,    23,   415,   416,
     417,   420,   421,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   422,    19,
      27,    20,    21,    22,    23,   248,   356,   214,   138,   139,
     354,    84,   364,   154,   129,    92,   155,   156,   157,   123,
      67,   300,   360,   158,   159,   151,   152,   153,   348,   346,
     160,   161,   250,   251,   252,    66,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   347,   349,   145,   146,   147,
     148,   149,   351,   150,   399,   151,   152,   153,     0,     0,
       0,     0,     0,     0,     0,   136,   214,   138,   139,     0,
       0,     0,     0,     0,   136,   214,   138,   139,   154,     0,
       0,   155,   156,   357,   151,   152,   153,     0,   158,   159,
       0,     0,     0,   151,   152,   153,   161,     0,     0,   358,
       0,     0,   253,     0,   254,     0,   255,     0,   154,     0,
       0,   155,   156,   157,     0,     0,     0,     0,   158,   159,
       0,     0,     0,     0,     0,   160,   161,    68,     0,     0,
      66,     0,     0,     0,     0,     0,     3,   154,     0,     0,
     155,   156,   157,     0,     0,     0,   154,   158,   159,   155,
     156,   157,     0,     0,     0,   161,   158,   159,   383,     0,
       0,     0,     0,     0,   161,     0,     0,   402,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    69,    68,    19,     0,    20,    21,    22,    23,
       0,     0,     3,   136,   214,   138,   139,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,     0,   288,   353,   289,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    69,     0,
      19,     0,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     136,   214,   138,   139,     0,   154,     0,     0,   155,   156,
     157,     0,   288,     0,   289,   158,   159,     0,     0,   151,
     152,   153,     0,   161,   318,   136,   214,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   214,   138,
     139,     0,     0,     0,   151,   152,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,   156,   157,     0,     0,
       0,     0,   158,   159,   136,   214,   138,   139,     0,     0,
     161,   407,     0,     0,     3,     0,     0,   154,     0,     0,
     155,   156,   157,   151,   152,   153,     0,   158,   159,   154,
       0,     0,   155,   156,   157,   161,   409,     0,     0,   158,
     159,     0,     0,     0,     0,     0,     0,   161,   418,   136,
     214,   138,   139,    11,    12,    13,    14,    15,    16,    17,
      69,     0,    19,     0,     0,    21,    22,    23,   151,   152,
     153,     0,     0,     0,     0,     0,   154,     0,     0,   155,
     156,   157,     0,     0,     0,     0,   158,   159,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,    11,    12,
      13,    14,    15,    16,   198,     0,     0,    19,     0,     0,
      21,    22,    23,     3,   136,   214,   138,   139,     0,     0,
       0,   154,     0,     0,   155,   156,   157,     0,     0,     0,
       0,   158,   159,   151,   152,   153,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    69,
       0,    19,     0,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     214,   138,   139,     0,     0,     0,   154,     0,     0,   155,
     156,   157,     0,     0,   199,     0,   158,   159,   151,   152,
     153,     0,     0,   228,   161,   136,   214,   138,   139,     0,
       0,     0,     0,     0,   136,   214,   138,   139,     0,     0,
       0,     0,     0,     0,   151,   152,   153,     0,     0,     0,
       0,     0,     0,   151,   152,   153,     0,     0,   136,   214,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,   156,   157,   151,   152,   153,
       0,   158,   159,     0,   136,   214,   138,   139,   303,   161,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,   156,   157,   151,   152,   153,   154,   158,   159,   155,
     156,   157,     0,     0,   367,   161,   158,   159,   136,   214,
     138,   139,     0,   390,   161,     0,     0,     0,     0,     0,
     154,     0,     0,   155,   156,   157,     0,   151,   152,   153,
     158,   159,     0,   136,   214,   138,   139,   393,   161,     0,
       0,     0,   386,   214,   138,   139,   154,     0,     0,   155,
     156,   157,   151,   152,   153,     0,   158,   159,     0,     0,
       0,   151,   152,   153,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,   156,   157,     0,     0,     0,     0,
     158,   159,    68,     0,     0,     0,     0,     0,   232,     0,
       0,     3,     0,     0,     0,   154,     0,     0,   155,   156,
     157,     0,     0,     0,   154,   158,   159,   155,   156,   387,
       0,     0,     0,   235,   158,   159,     0,     0,     0,     0,
       0,     0,   161,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    69,     2,    19,
       0,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,    19,
       0,    20,    21,    22,    23,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    69,
       0,    19,     0,    20,    21,    22,    23,     0,   363,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    69,     0,    19,     0,    20,    21,
      22,    23
};

static const yytype_int16 yycheck[] =
{
     130,    70,   154,   155,   156,   157,   158,   159,    82,     1,
     223,     1,   225,    60,     3,    28,     4,     4,   148,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    71,    28,
       4,   161,    28,     4,     4,     4,   249,    28,    28,   288,
      39,     4,    69,    42,     4,     4,    27,    28,    91,    39,
      32,    69,    42,    69,   254,    60,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,    69,    69,    53,
      54,    98,    56,    53,   117,   131,    53,    92,    94,     4,
      98,    65,    97,    69,     3,    65,   286,     6,    65,    71,
      89,    92,    94,    97,   224,    76,    77,   227,    92,    89,
     230,   231,   232,    78,    79,   235,    92,    96,    29,    30,
      98,    98,   361,    72,    97,   267,   268,   269,    25,    26,
     112,    80,   112,    97,     4,   255,    97,    97,    97,    60,
      93,   200,    95,    93,    93,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   165,   285,   284,    80,   212,   200,   371,   289,
     312,   313,   161,    80,    81,    82,   165,   210,    93,   165,
     162,   161,   162,   303,   165,   165,   376,    93,    53,    95,
     312,   313,   395,    53,   397,    97,    56,   200,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    53,    52,
      53,   200,    53,    56,   200,   357,    98,   420,    61,   200,
     200,    52,    53,    53,    53,    56,    56,   291,    80,   288,
      61,    97,    93,    70,    95,   357,   274,   275,   276,   277,
     270,   271,   362,   272,   273,   387,   235,   367,    70,   369,
     278,   279,    53,    53,    53,   288,     3,   379,    13,    97,
      94,    72,    72,     4,    92,   387,    92,    72,    93,   389,
      93,    73,   392,   393,    93,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    93,    13,    14,    15,    16,    17,
      18,   411,    20,    74,    22,    23,    24,    52,    53,    54,
      55,    56,    57,    58,    59,    75,    61,    31,    69,    64,
      65,    66,    92,    69,    96,    94,     3,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    92,    61,    92,    63,    64,    65,    66,     4,
      94,    94,    94,    98,     4,    20,     4,    75,    92,    94,
      78,    79,    80,    96,    13,    94,    94,    85,    86,    94,
      72,    94,    94,    94,    92,    93,    96,    96,    93,    97,
      98,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      96,    13,    14,    15,    16,    17,    18,    92,    20,    96,
      22,    23,    24,    52,    53,    54,    55,    56,    57,    58,
      59,    94,    61,    94,    92,    64,    65,    66,    94,    94,
      94,    12,    92,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    94,    61,
       1,    63,    64,    65,    66,   162,     3,     4,     5,     6,
     288,    28,   295,    75,    93,    42,    78,    79,    80,    89,
      26,   210,   291,    85,    86,    22,    23,    24,   282,   280,
      92,    93,    21,    22,    23,    97,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   281,   283,    14,    15,    16,
      17,    18,   285,    20,   379,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    75,    -1,
      -1,    78,    79,    80,    22,    23,    24,    -1,    85,    86,
      -1,    -1,    -1,    22,    23,    24,    93,    -1,    -1,    96,
      -1,    -1,    91,    -1,    93,    -1,    95,    -1,    75,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    92,    93,     4,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    13,    75,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    75,    85,    86,    78,
      79,    80,    -1,    -1,    -1,    93,    85,    86,    96,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     4,    61,    -1,    63,    64,    65,    66,
      -1,    -1,    13,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    93,    94,    95,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
       3,     4,     5,     6,    -1,    75,    -1,    -1,    78,    79,
      80,    -1,    93,    -1,    95,    85,    86,    -1,    -1,    22,
      23,    24,    -1,    93,    94,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    86,     3,     4,     5,     6,    -1,    -1,
      93,    94,    -1,    -1,    13,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    22,    23,    24,    -1,    85,    86,    75,
      -1,    -1,    78,    79,    80,    93,    94,    -1,    -1,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,     3,
       4,     5,     6,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    -1,    -1,    64,    65,    66,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,     4,    -1,    -1,    61,    -1,    -1,
      64,    65,    66,    13,     3,     4,     5,     6,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    22,    23,    24,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    -1,    -1,    94,    -1,    85,    86,    22,    23,
      24,    -1,    -1,    92,    93,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    22,    23,    24,
      -1,    85,    86,    -1,     3,     4,     5,     6,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    22,    23,    24,    75,    85,    86,    78,
      79,    80,    -1,    -1,    92,    93,    85,    86,     3,     4,
       5,     6,    -1,    92,    93,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    -1,    22,    23,    24,
      85,    86,    -1,     3,     4,     5,     6,    92,    93,    -1,
      -1,    -1,     3,     4,     5,     6,    75,    -1,    -1,    78,
      79,    80,    22,    23,    24,    -1,    85,    86,    -1,    -1,
      -1,    22,    23,    24,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,     4,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    13,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    75,    85,    86,    78,    79,    80,
      -1,    -1,    -1,    93,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    61,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    13,    61,
      -1,    63,    64,    65,    66,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    63,    64,    65,    66,    -1,    68,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    63,    64,
      65,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   100,     0,    13,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    61,
      63,    64,    65,    66,   101,   102,   103,   106,   107,   109,
     110,   111,   112,   113,   125,   126,   127,   130,   131,   132,
     134,   141,   142,   143,     4,    97,    60,    60,    53,    54,
      56,    65,     4,    97,     4,    97,    53,    65,    52,    53,
      56,    61,    52,    53,    56,    61,    97,   155,     4,    59,
      80,    93,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   120,   121,    92,   111,   112,   133,   135,
     136,   137,   133,    97,     4,   128,   129,    60,    53,    65,
      53,    97,    92,    97,    53,    53,    56,    53,    53,    56,
      53,    98,   156,     4,   118,   114,   121,    69,    92,    93,
      95,   115,    98,   136,    72,   114,   138,   139,   140,   128,
      70,    69,    98,    53,    53,    53,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    14,    15,    16,    17,    18,
      20,    22,    23,    24,    75,    78,    79,    80,    85,    86,
      92,    93,   104,   105,   106,   107,   145,   146,   149,   152,
     155,   157,   158,   159,   160,   161,   162,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    94,   114,     4,    94,
     107,   112,   122,   123,   124,   183,     3,    96,     3,    72,
      69,    92,    69,    98,     4,   182,    98,   129,    92,     3,
       6,   153,    92,   150,    93,   154,     4,    93,    92,   182,
      93,    93,    93,   168,   168,    93,   168,   167,   168,   167,
     167,   167,   167,   167,   111,   112,   182,    98,   105,    72,
      21,    22,    23,    91,    93,    95,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    70,    80,    81,    82,
      78,    79,    25,    26,    27,    28,    76,    77,    29,    30,
      73,    74,    75,    32,    71,    31,    69,    92,    93,    95,
     114,   118,   119,   144,    94,    69,    69,    94,    96,     3,
     139,    98,   145,    92,   182,   145,    92,   182,    92,   182,
     182,   111,    94,    94,    94,   145,     4,     4,    94,   163,
     180,   182,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   167,   167,   167,   169,   169,   170,   170,
     171,   171,   171,   171,   172,   172,   175,   176,   173,   178,
     182,   174,   180,    94,   119,   122,     3,    80,    96,   182,
     144,    93,    95,    68,   124,     4,    20,    92,   182,    92,
      94,    94,    94,    94,   167,   167,    69,    94,    96,    72,
      94,    94,    96,    96,    96,   122,     3,    80,   182,    93,
      92,   182,    92,    92,   182,   147,   145,   151,   180,   179,
      94,    96,    96,    96,   182,    94,    94,    94,   182,    94,
     182,    92,   145,   148,   145,    94,    94,    94,    94,   182,
      12,    92,    94,   145
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   101,   101,   102,   103,   104,   104,
     105,   105,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   109,   109,
     109,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   116,   117,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   126,   126,   127,
     128,   128,   129,   129,   130,   131,   131,   132,   132,   133,
     134,   135,   135,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   147,
     146,   148,   148,   150,   149,   151,   149,   149,   152,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   156,   155,   155,   157,   157,   158,   159,   159,   159,
     159,   159,   160,   160,   160,   160,   160,   160,   161,   162,
     162,   163,   163,   164,   164,   165,   166,   167,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     171,   172,   172,   172,   172,   172,   173,   173,   173,   174,
     174,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   181,   181,   182,   183,   183
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     2,     1,     2,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     2,     1,     1,
       2,     2,     3,     2,     3,     3,     4,     2,     2,     1,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     4,
       4,     1,     2,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     1,     2,     1,     1,
       2,     3,     4,     4,     3,     4,     1,     3,     1,     3,
       2,     1,     2,     1,     1,     4,     5,     5,     6,     2,
       1,     3,     1,     3,     3,     2,     1,     2,     3,     2,
       2,     1,     2,     3,     1,     1,     1,     3,     1,     1,
       2,     3,     2,     1,     2,     3,     2,     3,     4,     4,
       4,     4,     3,     3,     3,     3,     2,     2,     2,     3,
       1,     1,     1,     5,     2,     2,     3,     1,     1,     0,
       6,     1,     3,     0,     8,     0,     6,     3,     1,     2,
       1,     1,     1,     5,     5,     5,     5,     6,     6,     6,
       7,     0,     4,     2,     3,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     1,     3,     3,     3,     2,     2,     1,     4,     4,
       1,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "parse.y" /* yacc.c:1646  */
    {}
#line 1842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "parse.y" /* yacc.c:1646  */
    {}
#line 1848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 99 "parse.y" /* yacc.c:1646  */
    {}
#line 1854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "parse.y" /* yacc.c:1646  */
    {}
#line 1860 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "parse.y" /* yacc.c:1646  */
    {}
#line 1866 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = add_type_node((yyvsp[0].node), (yyvsp[-1].node));
                                         (yyval.node) = insert_sym((yyval.node)->ast_node.common_node.name,
                                                         (yyval.node)->ast_node.common_node.nspace,
                                                         (yyval.node),1);}
#line 1875 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "parse.y" /* yacc.c:1646  */
    {struct node* n = (struct node*) malloc(sizeof(struct node));
                                           (yyval.node) = n;
                                           (yyval.node)->flag = LIST;  
                                           (yyval.node)->ast_node.list_node.head_list = NULL; 
                                           if ((yyvsp[0].node) != NULL){
                                                (yyval.node)->ast_node.list_node.head_list = (yyvsp[0].node); 
                                          }}
#line 1887 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "parse.y" /* yacc.c:1646  */
    {struct node* n = (yyvsp[-1].node)->ast_node.list_node.head_list;
                                                           if ((yyvsp[0].node) != NULL){
                                                            if (n == NULL){
                                                                (yyvsp[-1].node)->ast_node.list_node.head_list = (yyvsp[0].node);
                                                            }else{
                                                                while (n->next != NULL){n = n->next;}
                                                                n->next = (yyvsp[0].node);
                                                            }
                                                          }
                                                          (yyval.node) = (yyvsp[-1].node);}
#line 1902 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 130 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1908 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "parse.y" /* yacc.c:1646  */
    {}
#line 1914 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "parse.y" /* yacc.c:1646  */
    {}
#line 1920 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "parse.y" /* yacc.c:1646  */
    {}
#line 1926 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 136 "parse.y" /* yacc.c:1646  */
    {}
#line 1932 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1944 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "parse.y" /* yacc.c:1646  */
    {}
#line 1950 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1956 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 143 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1962 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 144 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "parse.y" /* yacc.c:1646  */
    {(yyvsp[0].node)->next = (yyvsp[-1].node);}
#line 1974 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 146 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1980 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1992 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "parse.y" /* yacc.c:1646  */
    {
                                                         add_type_node((yyvsp[0].node),(yyvsp[-1].node));
                                                         (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                        (yyvsp[0].node)->ast_node.common_node.nspace,
                                                                        (yyvsp[0].node),1);
                                                        }
#line 2003 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parse.y" /* yacc.c:1646  */
    {
                                                        add_type_node((yyvsp[0].node), (yyvsp[-3].node));
                                                        (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                        (yyvsp[0].node)->ast_node.common_node.nspace,
                                                                        (yyvsp[0].node),1);
                                                        }
#line 2014 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 166 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_AUTO;}
#line 2020 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 167 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_EXTERN;}
#line 2026 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_REGISTER;}
#line 2032 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 169 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_STATIC;}
#line 2038 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INLINE;}
#line 2044 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2050 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2056 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 177 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2062 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 178 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2068 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2074 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2080 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 181 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2086 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 182 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2092 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 183 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2098 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 184 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2104 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2110 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 186 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2116 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 187 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2122 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 188 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2128 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 189 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2134 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 190 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2140 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 191 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2146 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 192 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UINT;}
#line 2152 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 193 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2158 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 194 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2164 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 195 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2170 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 196 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2176 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 197 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2182 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 198 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2188 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 199 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UINT;}
#line 2194 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 200 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2200 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 201 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2206 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 202 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2212 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 203 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2218 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 204 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_CHAR;}
#line 2224 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 205 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SCHAR;}
#line 2230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 206 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UCHAR;}
#line 2236 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 207 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_BOOL;}
#line 2242 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_FLOAT;}
#line 2248 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_DOUBLE;}
#line 2254 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 210 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGDOUBLE;}
#line 2260 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 211 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_FLOATCOMPLEX;}
#line 2266 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 212 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_DOUBLECOMPLEX;}
#line 2272 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 213 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGDOUBLECOMPLEX;}
#line 2278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) =  T_VOID;}
#line 2284 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "parse.y" /* yacc.c:1646  */
    {}
#line 2290 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "parse.y" /* yacc.c:1646  */
    {}
#line 2296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 219 "parse.y" /* yacc.c:1646  */
    {}
#line 2302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 222 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_CONST;}
#line 2308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 223 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_VOLATILE;}
#line 2314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 224 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_RESTRICT;}
#line 2320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 227 "parse.y" /* yacc.c:1646  */
    {}
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 228 "parse.y" /* yacc.c:1646  */
    {}
#line 2332 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 230 "parse.y" /* yacc.c:1646  */
    {}
#line 2338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 231 "parse.y" /* yacc.c:1646  */
    {}
#line 2344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 232 "parse.y" /* yacc.c:1646  */
    {}
#line 2350 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 233 "parse.y" /* yacc.c:1646  */
    {}
#line 2356 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 236 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name),I_NODE);}
#line 2362 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 238 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = add_type_node((yyvsp[0].node),(yyvsp[-1].node));}
#line 2368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 241 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ptr();}
#line 2374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 242 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ptr();
                                                 (yyvsp[0].node)->ast_node.ptr_node.ptr_to_node = (yyval.node);}
#line 2381 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 246 "parse.y" /* yacc.c:1646  */
    {}
#line 2387 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 247 "parse.y" /* yacc.c:1646  */
    {}
#line 2393 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 248 "parse.y" /* yacc.c:1646  */
    {}
#line 2399 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 251 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ary(0);
                                                 (yyval.node) = add_type_node((yyvsp[-2].node),(yyval.node));}
#line 2406 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 253 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ary((yyvsp[-1].number).number);
                                                 (yyval.node) = add_type_node((yyvsp[-3].node), (yyval.node));}
#line 2413 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 258 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-3].node));
                                                         (yyval.node)->next->ast_node.type_fn_node.arg = (yyvsp[-1].node);
                                                         }
#line 2421 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 261 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-2].node));}
#line 2427 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 262 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-3].node));
                                                         (yyval.node)->next->ast_node.type_fn_node.arg = (yyvsp[-1].node);}
#line 2434 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 266 "parse.y" /* yacc.c:1646  */
    {}
#line 2440 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 267 "parse.y" /* yacc.c:1646  */
    {}
#line 2446 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 270 "parse.y" /* yacc.c:1646  */
    {}
#line 2452 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 271 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_add_arg((yyvsp[-2].node), (yyvsp[0].node));}
#line 2458 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 274 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_make_arg((yyvsp[-1].node), (yyvsp[0].node));}
#line 2464 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 275 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_make_arg((yyvsp[0].node), NULL);}
#line 2470 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 276 "parse.y" /* yacc.c:1646  */
    {}
#line 2476 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 279 "parse.y" /* yacc.c:1646  */
    {}
#line 2482 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 280 "parse.y" /* yacc.c:1646  */
    {}
#line 2488 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 283 "parse.y" /* yacc.c:1646  */
    {}
#line 2494 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 284 "parse.y" /* yacc.c:1646  */
    {}
#line 2500 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 285 "parse.y" /* yacc.c:1646  */
    {}
#line 2506 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 286 "parse.y" /* yacc.c:1646  */
    {}
#line 2512 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 289 "parse.y" /* yacc.c:1646  */
    {}
#line 2518 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 292 "parse.y" /* yacc.c:1646  */
    {}
#line 2524 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 293 "parse.y" /* yacc.c:1646  */
    {}
#line 2530 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 296 "parse.y" /* yacc.c:1646  */
    {}
#line 2536 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 297 "parse.y" /* yacc.c:1646  */
    {}
#line 2542 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 300 "parse.y" /* yacc.c:1646  */
    {
                                            struct sym_node* struct_sym;
                                            if ((struct_sym = lookup((yyvsp[-1].ident_name),N_TAGS,1)) == NULL){
                                                (yyval.node) = ast_new_struct((yyvsp[-1].ident_name), I_STRUCT_TAG_NODE);
                                                (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,N_TAGS,(yyval.node),1);
                                            }else{
                                                printf("You are wrong!\n");
                                            }}
#line 2555 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 309 "parse.y" /* yacc.c:1646  */
    {}
#line 2561 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 310 "parse.y" /* yacc.c:1646  */
    {}
#line 2567 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 313 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct(NULL, I_STRUCT_TAG_NODE) ; 
                                             (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                             N_TAGS, (yyval.node), 1);
                                             if ((yyval.node) != NULL){
                                                enter_block((yyval.node), 1);
                                                (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                             
                                             }
                                             }
#line 2581 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 323 "parse.y" /* yacc.c:1646  */
    {
                                             struct sym_node* struct_sym;
                                             if (curr_scope != NULL && (struct_sym = lookup((yyvsp[-1].ident_name), N_TAGS, 1)) != NULL){
                                                (yyval.node) = struct_sym->ast_node;   
                                                (yyval.node)->ast_node.struct_tag_node.node.line_num = line_num; 
                                            }else{
                                                (yyval.node) = ast_new_struct((yyvsp[-1].ident_name), I_STRUCT_TAG_NODE); 
                                                (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                             N_TAGS,(yyval.node), 1); 

                                             }
                                             if ((yyval.node) != NULL){
                                                create_sym_table((yyval.node)->ast_node.struct_tag_node.node.name, 1);
                                                (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                             }}
#line 2601 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 340 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->ast_node.struct_tag_node.isComplete = 1;
                                             struct sym_node* node = curr_scope->sym_node;
                                             if (show_decl == 1){
                                                print_debug_stmt((yyvsp[-2].node));
                                             }
                                             curr_scope = curr_scope->prev_scope;
                                             }
#line 2613 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 348 "parse.y" /* yacc.c:1646  */
    {
                                         struct sym_node* struct_sym;
                                         if ((struct_sym = lookup((yyvsp[0].ident_name),N_TAGS,0)) != NULL){
                                            (yyval.node) = struct_sym->ast_node;
                                         }else{
                                            (yyval.node) = ast_new_struct((yyvsp[0].ident_name), I_STRUCT_TAG_NODE);
                                            (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                            N_TAGS,(yyval.node), 1);
                                         }}
#line 2627 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 359 "parse.y" /* yacc.c:1646  */
    {}
#line 2633 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 360 "parse.y" /* yacc.c:1646  */
    {}
#line 2639 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 363 "parse.y" /* yacc.c:1646  */
    {}
#line 2645 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 365 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 2651 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 366 "parse.y" /* yacc.c:1646  */
    {}
#line 2657 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 368 "parse.y" /* yacc.c:1646  */
    {add_type_node((yyvsp[0].node),(yyvsp[-1].node));
                                                                             (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                                             N_MINIDEFS,(yyvsp[0].node),1);}
#line 2665 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 371 "parse.y" /* yacc.c:1646  */
    {add_type_node((yyvsp[0].node),(yyvsp[-3].node));
                                                                             (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                                             N_MINIDEFS,(yyvsp[0].node),1);}
#line 2673 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 376 "parse.y" /* yacc.c:1646  */
    {}
#line 2679 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 377 "parse.y" /* yacc.c:1646  */
    {}
#line 2685 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 381 "parse.y" /* yacc.c:1646  */
    {}
#line 2691 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 382 "parse.y" /* yacc.c:1646  */
    {}
#line 2697 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 385 "parse.y" /* yacc.c:1646  */
    {}
#line 2703 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 386 "parse.y" /* yacc.c:1646  */
    {}
#line 2709 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 389 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct(NULL, I_UNION_TAG_NODE) ; 
                                                         (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                                        N_TAGS, (yyval.node), 1);
                                                         if ((yyval.node) != NULL){
                                                            enter_block((yyval.node), 1);
                                                            (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                                        }}
#line 2721 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 397 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct((yyvsp[-1].ident_name), I_UNION_TAG_NODE);
                                                         (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                                         N_TAGS, (yyval.node),1);
                                                         if ((yyval.node) != NULL){
                                                            enter_block((yyval.node),1);
                                                            (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                                         }}
#line 2733 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 406 "parse.y" /* yacc.c:1646  */
    {struct sym_node* struct_sym;
                                     if ((struct_sym = lookup((yyvsp[0].ident_name),N_TAGS,0)) != NULL){
                                        (yyval.node) = struct_sym->ast_node;
                                     }else{
                                        (yyval.node) = ast_new_struct((yyvsp[0].ident_name), I_UNION_TAG_NODE);
                                        (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                        N_TAGS,(yyval.node), 1);
                                     }}
#line 2746 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 415 "parse.y" /* yacc.c:1646  */
    {}
#line 2752 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 416 "parse.y" /* yacc.c:1646  */
    {}
#line 2758 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 417 "parse.y" /* yacc.c:1646  */
    {}
#line 2764 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 418 "parse.y" /* yacc.c:1646  */
    {}
#line 2770 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 419 "parse.y" /* yacc.c:1646  */
    {}
#line 2776 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 420 "parse.y" /* yacc.c:1646  */
    {}
#line 2782 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 421 "parse.y" /* yacc.c:1646  */
    {}
#line 2788 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 422 "parse.y" /* yacc.c:1646  */
    {}
#line 2794 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 423 "parse.y" /* yacc.c:1646  */
    {}
#line 2800 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 424 "parse.y" /* yacc.c:1646  */
    {}
#line 2806 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 425 "parse.y" /* yacc.c:1646  */
    {}
#line 2812 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 427 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2818 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 428 "parse.y" /* yacc.c:1646  */
    {
                                             if ((yyvsp[-2].node)->flag == ST_CASE){
                                                (yyvsp[-2].node)->ast_node.case_node.stmt = (yyvsp[0].node);
                                             }else if ((yyvsp[-2].node)->flag == ST_DEFAULT){
                                                (yyvsp[-2].node)->ast_node.default_node.stmt = (yyvsp[0].node);
                                             }else{
                                                (yyvsp[-2].node)->ast_node.stmt_label_node.stmt = (yyvsp[0].node);
                                             }
                                             (yyval.node) = (yyvsp[-2].node);}
#line 2832 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 437 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2838 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 438 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2844 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 439 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2850 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 440 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_switch((yyvsp[-2].node), (yyvsp[0].node)); 
                                             make_switch_map((yyval.node), (yyvsp[0].node));}
#line 2857 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 442 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_stmt(ST_BREAK);}
#line 2863 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 443 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_stmt(ST_CONTINUE);}
#line 2869 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 444 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n;
                                             if ((n = lookup((yyvsp[-1].ident_name), N_LABELS, 0)) == NULL){
                                                (yyval.node) = ast_new_ident((yyvsp[-1].ident_name),I_STMT_LABEL_NODE);
                                                (yyval.node) = insert_sym((yyvsp[-1].ident_name),N_LABELS,(yyval.node),1);
                                            }else{
                                                (yyval.node) = n->ast_node;
                                            }
                                             (yyval.node) = ast_new_goto((yyval.node));}
#line 2882 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 452 "parse.y" /* yacc.c:1646  */
    {}
#line 2888 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 453 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2894 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 456 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_if((yyvsp[-1].node), NULL,NULL);}
#line 2900 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 456 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2906 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 459 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.if_node.action = (yyvsp[0].node);(yyval.node) = (yyvsp[-1].node);}
#line 2912 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 460 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-3].node)->ast_node.if_node.else_action = (yyvsp[0].node); (yyvsp[-3].node)->ast_node.if_node.action = (yyvsp[-2].node);(yyval.node) = (yyvsp[-3].node);}
#line 2918 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 462 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_do(NULL,NULL);}
#line 2924 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 462 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-6].node)->ast_node.do_node.cond = (yyvsp[-2].node);
                                                                                                 (yyvsp[-6].node)->ast_node.do_node.stmt = (yyvsp[-5].node);
                                                                                                 (yyval.node) = (yyvsp[-6].node);}
#line 2932 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 465 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_while((yyvsp[-1].node), NULL);}
#line 2938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 465 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.while_node.action = (yyvsp[0].node);
                                                                                                  (yyval.node) = (yyvsp[-1].node);}
#line 2945 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 467 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.for_node.stmt = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node);}
#line 2951 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 470 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n;
                                     if ((n = lookup((yyvsp[0].ident_name), N_LABELS, 0)) == NULL){
                                        (yyval.node) = ast_new_ident((yyvsp[0].ident_name),I_STMT_LABEL_NODE);
                                        (yyval.node) = insert_sym((yyvsp[0].ident_name),N_LABELS,(yyval.node),1);
                                    }else{
                                        (yyval.node) = n->ast_node;
                                    }}
#line 2963 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 477 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_case((yyvsp[0].node));}
#line 2969 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 478 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_case(NULL);}
#line 2975 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 482 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const((yyvsp[0].number).number);}
#line 2981 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 483 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const_char((yyvsp[0].char_lit).actual_char);}
#line 2987 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 486 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,NULL,NULL);}
#line 2993 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 487 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-3].node),NULL,NULL);}
#line 2999 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 488 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,(yyvsp[-2].node),NULL);}
#line 3005 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 489 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,NULL,(yyvsp[-1].node));}
#line 3011 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 490 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-4].node),(yyvsp[-2].node),NULL);}
#line 3017 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 491 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-4].node),NULL,(yyvsp[-1].node));}
#line 3023 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 492 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,(yyvsp[-3].node),(yyvsp[-1].node));}
#line 3029 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 493 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node));}
#line 3035 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 496 "parse.y" /* yacc.c:1646  */
    {enter_block((yyvsp[-1].node), 0);}
#line 3041 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 496 "parse.y" /* yacc.c:1646  */
    { print_func_dump(0, (yyvsp[-1].node), (yyvsp[-4].node));
                                                                             if (curr_scope->scope_num == S_FUNCTION)
                                                                                fn_counter += 1;
                                                                             generate_quads((yyvsp[-1].node), curr_scope->scope_num, (yyvsp[-4].node));
                                                                             leave_block();
                                                                             (yyval.node) = (yyvsp[-1].node);}
#line 3052 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 502 "parse.y" /* yacc.c:1646  */
    {}
#line 3058 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 505 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_return((yyvsp[-1].node));}
#line 3064 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 506 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_return(NULL);}
#line 3070 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 509 "parse.y" /* yacc.c:1646  */
    {}
#line 3076 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 512 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n = lookup((yyvsp[0].ident_name), N_OTHERS, 0);
                                     (yyval.node) = n->ast_node;}
#line 3083 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 514 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const((yyvsp[0].number).number);}
#line 3089 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 515 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const_char((yyvsp[0].char_lit).actual_char);}
#line 3095 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 516 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const_string((yyvsp[0].string_lit).string_literal, (yyvsp[0].string_lit).string_size, string_count);string_count += 1; inst_print_string((yyval.node));}
#line 3101 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 517 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 3107 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 520 "parse.y" /* yacc.c:1646  */
    {}
#line 3113 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 521 "parse.y" /* yacc.c:1646  */
    {}
#line 3119 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 522 "parse.y" /* yacc.c:1646  */
    {}
#line 3125 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 523 "parse.y" /* yacc.c:1646  */
    {}
#line 3131 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 524 "parse.y" /* yacc.c:1646  */
    {}
#line 3137 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 525 "parse.y" /* yacc.c:1646  */
    {}
#line 3143 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 528 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD,(yyvsp[-3].node),(yyvsp[-1].node));
                                                   (yyval.node) = ast_new_deref((yyval.node));}
#line 3150 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 532 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_fn_call((yyvsp[-1].node), (yyvsp[-3].node));}
#line 3156 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 533 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_fn_call(NULL,(yyvsp[-2].node));}
#line 3162 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 536 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_expr_arg(NULL,(yyvsp[0].node));}
#line 3168 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 537 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_expr_arg((yyvsp[-2].node), (yyvsp[0].node));}
#line 3174 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 540 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_indsel(E_DOT, (yyvsp[-2].node), (yyvsp[0].ident_name));}
#line 3180 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 541 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_indsel(E_INDSEL, (yyvsp[-2].node), (yyvsp[0].ident_name));}
#line 3186 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 544 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_POSTINC, (yyvsp[-1].node));}
#line 3192 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 546 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_POSTDEC, (yyvsp[-1].node));}
#line 3198 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 550 "parse.y" /* yacc.c:1646  */
    {}
#line 3204 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 551 "parse.y" /* yacc.c:1646  */
    {}
#line 3210 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 552 "parse.y" /* yacc.c:1646  */
    {}
#line 3216 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 555 "parse.y" /* yacc.c:1646  */
    {}
#line 3222 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 556 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[-1].scalar_type));
                                                                 (yyval.node) = ast_new_unary(E_SIZEOF, (yyval.node));}
#line 3229 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 558 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_SIZEOF, (yyvsp[0].node));}
#line 3235 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 559 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_UMINUS, (yyvsp[0].node));}
#line 3241 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 560 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_UPLUS, (yyvsp[0].node));}
#line 3247 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 561 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_LOGNOT, (yyvsp[0].node));}
#line 3253 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 562 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_BITNOT, (yyvsp[0].node));}
#line 3259 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 563 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_ADDRESS, (yyvsp[0].node));}
#line 3265 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 564 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_deref((yyvsp[0].node));}
#line 3271 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 565 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const(1);
                                                                 (yyval.node) = ast_new_binop(E_ADD, (yyvsp[0].node), (yyval.node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[0].node), (yyval.node));}
#line 3279 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 568 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const(1);
                                                                 (yyval.node) = ast_new_binop(E_MINUS, (yyvsp[0].node), (yyval.node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[0].node), (yyval.node));}
#line 3287 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 573 "parse.y" /* yacc.c:1646  */
    {}
#line 3293 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 574 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MUL,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3299 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 575 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_DIV,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3305 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 576 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MOD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3311 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 578 "parse.y" /* yacc.c:1646  */
    {}
#line 3317 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 579 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3323 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 580 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MINUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3329 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 583 "parse.y" /* yacc.c:1646  */
    {}
#line 3335 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 584 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHL, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3341 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 585 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3347 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 589 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3353 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 590 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_GT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3359 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 591 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LTEQ, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3365 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 592 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_GTEQ, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3371 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 595 "parse.y" /* yacc.c:1646  */
    {}
#line 3377 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 596 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3383 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 597 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3389 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 600 "parse.y" /* yacc.c:1646  */
    {}
#line 3395 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 601 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_OR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3401 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 604 "parse.y" /* yacc.c:1646  */
    {}
#line 3407 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 605 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_XOR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3413 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 608 "parse.y" /* yacc.c:1646  */
    {}
#line 3419 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 609 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_AND,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3425 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 612 "parse.y" /* yacc.c:1646  */
    {}
#line 3431 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 613 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LOGOR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3437 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 616 "parse.y" /* yacc.c:1646  */
    {}
#line 3443 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 617 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LOGAND,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3449 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 620 "parse.y" /* yacc.c:1646  */
    {}
#line 3455 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 621 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ACTION,(yyvsp[-2].node),(yyvsp[0].node));
                                                                             (yyval.node) = ast_new_binop(E_COND,(yyvsp[-4].node),(yyval.node));}
#line 3462 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 625 "parse.y" /* yacc.c:1646  */
    {}
#line 3468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 626 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_assign((yyvsp[-2].node), (yyvsp[0].node));}
#line 3474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 627 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3481 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 629 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MINUS, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3488 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 631 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MUL, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3495 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 633 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_DIV, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3502 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 635 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MOD, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3509 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 637 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHL, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3516 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 639 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHR, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3523 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 641 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_AND, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3530 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 643 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_OR, (yyvsp[-2].node), (yyvsp[0].node));  
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3537 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 645 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_XOR, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3544 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 649 "parse.y" /* yacc.c:1646  */
    {}
#line 3550 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 650 "parse.y" /* yacc.c:1646  */
    {struct node* n = (yyvsp[-2].node);
                                                     while(n->next != NULL){n=n->next;}
                                                     n->next = (yyvsp[0].node);}
#line 3558 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 655 "parse.y" /* yacc.c:1646  */
    {}
#line 3564 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 658 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name), 0);}
#line 3570 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 659 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name), 0);}
#line 3576 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3580 "parse.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 663 "parse.y" /* yacc.c:1906  */


int main(int argc, char* argv[]){
    list = (struct node*) malloc(sizeof(struct node));
	list->flag = LIST;
	static_count = 0;
    string_count = 0;
    int c;
    show_lex = 0;
    show_decl = 0;
    show_ast= 0;
    show_quads = 0;
    show_targetcode = 0;
    while ((c = getopt(argc, argv, "daqtl")) != -1){
        switch(c){
            case 'l':
                show_lex = 1;
                break;
            case 'd':
                // done
                show_decl = 1;
                break;
            case 'a':
                // done
                show_ast = 1;
                break;
            case 'q':
                // done
                show_quads = 1;
                break;
            case 't':
                show_targetcode = 1;
                break;
            default:
                break;
        }    
    }
    yyin = fopen(argv[optind], "r");
    do{
        yyparse();
        if (yylval < 257 && yylval > 0){
            fprintf(stdout,"%s\t%d\t%c\t\n", fname, line_num, yylval);
        }
    }while(!feof(yyin));
    return 0;
    // pointers and array pointers
}

void yyerror(char *s){
    fprintf(stderr , "syntax error: %s\n", s);
}
