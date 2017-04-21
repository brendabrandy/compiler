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
    #include "sym_table.h"
    extern FILE* yyin;
    extern int yyparse();
    extern int yylex();
    char *fname;
    int fn_counter = 0;
    extern struct scope_node* curr_scope;
    struct node* list;
    extern int line_num;
    struct node* list_header;   // the start of the AST of expressions and statements
    void yyerror(char *s);
    int main();
    // precedence goes from low to high 
    // sizeof, casting

#line 84 "parse.tab.c" /* yacc.c:339  */

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
#line 19 "parse.y" /* yacc.c:355  */

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

#line 221 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   1295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  265
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422

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
       0,    86,    86,    87,    90,    91,    94,    97,   102,   109,
     121,   122,   125,   126,   127,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   142,   148,   157,   158,   159,
     160,   163,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   208,   209,   210,   213,   214,   215,   218,   219,
     221,   222,   223,   224,   227,   229,   232,   233,   237,   238,
     239,   242,   244,   249,   252,   253,   257,   258,   261,   262,
     265,   266,   267,   270,   271,   274,   275,   276,   277,   280,
     283,   284,   287,   288,   291,   300,   301,   304,   314,   331,
     337,   348,   349,   352,   354,   355,   357,   360,   365,   366,
     370,   371,   374,   375,   378,   386,   395,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   416,   417,
     426,   427,   428,   429,   431,   432,   433,   441,   442,   445,
     445,   448,   449,   451,   451,   454,   454,   456,   459,   466,
     467,   471,   472,   475,   476,   477,   478,   479,   480,   481,
     482,   485,   485,   491,   494,   495,   498,   501,   503,   504,
     507,   508,   509,   510,   511,   512,   515,   519,   520,   523,
     524,   527,   528,   531,   533,   537,   538,   539,   542,   543,
     545,   546,   547,   548,   549,   550,   551,   552,   555,   560,
     561,   562,   563,   565,   566,   567,   570,   571,   572,   575,
     576,   577,   578,   579,   582,   583,   584,   587,   588,   591,
     592,   595,   596,   599,   600,   603,   604,   607,   608,   612,
     613,   614,   616,   618,   620,   622,   624,   626,   628,   630,
     632,   636,   637,   642,   645,   646
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

#define YYPACT_NINF -278

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-278)))

#define YYTABLE_NINF -169

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -278,  1182,  -278,    27,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,    -9,    21,   135,  -278,    30,    32,    15,
    -278,   188,   195,  -278,  -278,  -278,     0,  -278,  1122,  -278,
    -278,  -278,    19,  -278,  -278,  -278,  -278,  -278,  -278,   163,
    -278,  -278,   163,  -278,     4,   109,  -278,  -278,  -278,    57,
      20,    69,    29,  -278,   -25,  -278,  -278,    75,  -278,  -278,
      49,    97,  -278,  -278,    56,   100,    58,  -278,  -278,    66,
      89,    28,    -3,  -278,  -278,  -278,  -278,  -278,  -278,   -18,
    -278,  -278,    39,  -278,    84,  -278,  -278,  -278,  -278,   233,
    -278,   103,  -278,   109,   114,   -22,  -278,  -278,  -278,   133,
    -278,  -278,  -278,  -278,  -278,  -278,   137,  -278,  -278,   153,
    -278,  -278,   352,   116,  -278,   117,  -278,    28,  -278,   832,
      68,   -18,  -278,  -278,   228,   161,    18,  -278,  -278,   -19,
    1020,     6,  -278,  -278,  -278,  -278,  -278,   164,   158,    80,
     160,  -278,  -278,   162,   250,   165,   728,   166,   169,  1045,
    1045,  1054,  1020,  1020,  1020,  1020,  1020,  1020,  -278,   776,
     260,  -278,  -278,  1122,  -278,  -278,  -278,   193,  -278,  -278,
    -278,  -278,   413,  -278,  -278,  -278,  -278,  -278,  -278,   342,
     220,    52,   173,    17,   172,   199,   192,   206,    -2,   262,
    -278,  -278,   226,   204,  -278,  -278,  -278,  -278,   585,  -278,
     209,   235,  -278,   -29,   224,  -278,  -278,   319,   103,  -278,
       8,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,   443,   896,   443,   236,  1020,  -278,   237,  1020,  1020,
    1020,  -278,  -278,   849,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,   238,   239,   240,  -278,  -278,   443,   323,  -278,
    -278,   326,   596,  1020,  1020,  1020,  1020,  1020,  1020,  1020,
    1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,
    1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,  1020,
    1020,  1020,  1020,  1020,  1020,  -278,   529,   417,  -278,    87,
    -278,    25,  -278,  1204,   332,  -278,  -278,  -278,  -278,  -278,
     317,   927,   249,  -278,  -278,   248,  -278,   253,   254,   255,
    1020,  1020,  -278,  -278,  -278,  -278,  -278,   -16,  -278,   247,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,   220,   220,    52,    52,   173,   173,
     173,   173,    17,    17,   192,   206,   172,   262,   272,   199,
    -278,  -278,   256,   257,   258,   452,  -278,   268,    25,  1229,
    1070,  -278,  -278,  -278,   278,   936,   281,   961,  -278,   443,
    -278,  -278,  -278,  -278,  1020,  -278,  -278,  1020,  -278,  -278,
    -278,  -278,  -278,   293,   292,   476,   294,  1020,   295,   297,
     663,   680,   300,   443,  -278,   443,  -278,  -278,  -278,  -278,
    -278,  -278,   299,  -278,  -278,  -278,   301,  -278,   302,   692,
     382,  -278,  -278,   322,  -278,  -278,  -278,   325,   443,  -278,
    -278,  -278
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
       0,     0,   105,    60,    46,    59,   188,   187,     0,     0,
       0,   170,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     8,    10,     0,    11,   151,   152,     0,   150,   157,
     158,   190,   208,   191,   193,   192,   194,   195,   219,   205,
     223,   226,   229,   234,   241,   245,   237,   239,   247,   243,
     249,   261,   263,     0,    81,    26,   264,    94,   101,    17,
       0,    96,    98,     0,     0,    91,   130,     0,     0,   123,
       0,   106,   187,   113,   107,   111,   154,   171,   172,   169,
     155,     0,     0,     0,     0,     0,   185,     0,     0,     0,
       0,   217,   218,     0,   210,   215,   205,   212,   211,   216,
     213,   214,     0,     0,     0,   182,     9,     0,     0,   203,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,   100,    88,
     102,    89,    93,     0,     0,    95,    92,   131,   127,   108,
       0,     0,     0,   167,   156,     0,   184,     0,     0,     0,
       0,     0,   189,   149,   202,   201,   198,     0,   199,     0,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     250,   220,   221,   222,   224,   225,   227,   228,   233,   232,
     230,   231,   235,   236,   238,   240,   242,   244,     0,   246,
     262,   147,     0,     0,   188,     0,   146,     0,    90,     0,
       0,    97,    99,   265,     0,     0,     0,     0,   159,     0,
     165,   209,   206,   207,     0,   197,   196,     0,   137,   145,
     142,   144,   143,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,   200,   248,   141,   138,
     140,   139,     0,   173,   176,   175,     0,   174,     0,     0,
     161,   160,   166,     0,   179,   178,   177,     0,     0,   164,
     180,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,  -278,  -278,  -278,   263,   421,    13,  -278,
       5,     9,    -1,     7,    14,   -43,   -75,  -278,  -278,   -44,
     138,  -278,   397,  -277,  -278,   136,  -278,  -278,  -278,   333,
    -120,  -278,  -278,  -278,   386,  -278,  -278,   344,  -278,  -278,
     234,  -278,  -278,  -278,  -278,   154,  -208,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,   422,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -151,  -132,
     -60,   -45,   -80,   -38,   182,   181,   190,   191,  -278,   196,
      92,  -200,  -278,  -130,  -278
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,    25,    26,   160,   161,   162,   198,    72,
      29,    30,    31,   199,    33,    78,    79,    80,    81,    82,
     290,    83,   116,   200,   201,   202,    34,    35,    36,    95,
      96,    37,    38,    39,    88,    40,    89,    90,    91,   126,
     127,   128,    41,    42,    43,   291,   164,   165,   393,   411,
     166,   221,   395,   167,   219,   223,   168,   112,   169,   170,
     171,   172,   173,   174,   317,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   203
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     213,   235,   237,   238,   239,   240,   241,   121,    32,   353,
      94,   215,    94,   300,    28,   303,   227,   231,   232,   234,
     236,   236,   236,   236,   236,   236,   114,    75,   115,   244,
     281,    44,    68,    73,    52,    76,    54,    74,    86,   313,
     294,    86,    77,    68,   272,   273,    87,   131,   125,    87,
     210,    46,   318,   374,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   295,   117,   102,    56,   282,
     113,   204,   103,    98,   195,   119,   132,   120,   375,   211,
      57,    47,   383,   217,   350,    99,   218,   208,    86,   118,
     215,    68,   302,   274,   275,   305,    87,    66,   307,   308,
     244,    93,   105,   244,   214,   106,   299,    68,    70,   108,
     209,    85,   109,    94,   331,   332,   333,    97,   359,    32,
     360,    71,   100,   319,    45,   163,   101,    53,   104,    55,
     268,   269,    71,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     107,   236,   348,   110,   289,   288,   111,   357,   242,   372,
     373,   394,    75,    55,   205,   125,   243,    32,    73,    70,
      76,   366,    74,   163,   396,   124,     3,    77,   236,   236,
     286,    -7,   287,    70,   130,   410,   133,   412,    48,    49,
     134,    50,   338,   339,   340,   341,    71,    75,   270,   271,
      51,   276,   277,    73,   239,    76,   135,    74,   334,   335,
     421,   194,    77,   103,   121,    11,    12,    13,    14,    15,
      16,    17,    69,   236,    19,   336,   337,    21,    22,    23,
     386,   206,   309,   207,   239,   389,  -168,   392,   342,   343,
      58,    59,   289,   115,    60,   236,     3,    62,    63,    61,
     216,    64,   220,   236,   224,   222,    65,   402,   225,   228,
     406,   408,   229,   136,   137,   247,   279,   138,   139,   140,
     141,   142,   278,     3,   143,   144,   145,   146,   147,   417,
     148,   280,   149,   150,   151,    11,    12,    13,    14,    15,
      16,    17,    69,   283,    19,   284,   285,    21,    22,    23,
     265,   266,   267,   292,   293,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     296,    19,   297,    20,    21,    22,    23,   314,   304,   306,
     315,   122,   310,   311,   312,   152,   363,   364,   153,   154,
     155,   367,   368,   376,   377,   156,   157,   369,   370,   371,
     378,   379,   158,   159,   380,   136,   137,    66,   245,   138,
     139,   140,   141,   142,   382,     3,   143,   144,   145,   146,
     147,   387,   148,   390,   149,   150,   151,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   398,   399,   403,
     401,   404,   409,   413,   418,   414,   415,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   264,    19,   419,    20,    21,    22,    23,   420,
     354,   212,    27,   246,   352,    84,   129,   152,    92,   362,
     153,   154,   155,   123,   248,   249,   250,   156,   157,   149,
     150,   151,   298,   358,   158,   159,   136,   137,    67,    66,
     138,   139,   140,   141,   142,   136,   212,   143,   144,   145,
     146,   147,   346,   148,   349,   149,   150,   151,   344,   397,
     345,     0,     0,     0,   149,   150,   151,   347,     0,   136,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   153,   154,   355,   149,   150,
     151,     0,   156,   157,   251,     0,   252,     0,   253,     0,
     159,     0,     0,   356,     0,     0,     0,     0,   152,     0,
       0,   153,   154,   155,     0,     0,     0,   152,   156,   157,
     153,   154,   155,    68,     0,   158,   159,   156,   157,     0,
      66,     0,     3,     0,     0,   159,     0,     0,   381,     0,
       0,   152,     0,     0,   153,   154,   155,     0,     0,     0,
       0,   156,   157,     0,     0,     0,     0,     0,     0,   159,
       0,     0,   400,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    69,    68,
      19,     0,    20,    21,    22,    23,     0,     0,     3,   136,
     212,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
     151,     0,   286,   351,   287,     0,     0,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    69,     0,    19,     0,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   136,   212,     0,     0,
       0,   152,     0,     0,   153,   154,   155,     0,   286,     0,
     287,   156,   157,   136,   212,   149,   150,   151,     0,   159,
     316,     0,     0,     0,     0,   136,   212,     0,     0,     0,
       0,     0,   149,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   212,     0,     0,     0,     0,     0,   152,     0,
       0,   153,   154,   155,     0,     0,     0,     0,   156,   157,
     149,   150,   151,     0,     0,   152,   159,   405,   153,   154,
     155,     0,     0,     0,     0,   156,   157,   152,     0,     0,
     153,   154,   155,   159,   407,     0,     0,   156,   157,   136,
     212,     0,     0,     0,     0,   159,   416,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
     151,     0,     0,   152,     0,     0,   153,   154,   155,     0,
       0,     0,     0,   156,   157,     0,     0,     0,     0,     0,
     226,   159,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    69,   196,    19,     0,     0,
      21,    22,    23,     0,     0,     3,     0,     0,     0,     0,
       0,   152,   136,   212,   153,   154,   155,     0,     0,     0,
       0,   156,   157,     0,     0,     0,     0,     0,     0,   159,
       0,   149,   150,   151,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    69,     0,    19,     0,    20,    21,    22,    23,   136,
     212,    11,    12,    13,    14,    15,    16,     0,     0,     0,
      19,     0,     0,    21,    22,    23,     0,     0,   149,   150,
     151,     0,     0,     0,   152,     0,   197,   153,   154,   155,
     136,   212,     0,     0,   156,   157,     0,     0,     0,   136,
     212,     0,   159,     0,     0,     0,     0,     0,     0,   149,
     150,   151,     0,     0,     0,     0,     0,     0,   149,   150,
     151,     0,     0,     0,   136,   212,     0,     0,     0,     0,
       0,   152,     0,     0,   153,   154,   155,     0,     0,     0,
       0,   156,   157,   149,   150,   151,     0,     0,   301,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   153,   154,   155,     0,     0,
       0,   152,   156,   157,   153,   154,   155,     0,     0,   365,
     159,   156,   157,   136,   212,     0,     0,     0,   388,   159,
       0,     0,     0,     0,     0,     0,   152,     0,     0,   153,
     154,   155,   149,   150,   151,     0,   156,   157,   136,   212,
       0,     0,     0,   391,   159,     0,     0,   136,   212,     0,
       0,     0,     0,     0,     0,     0,     0,   149,   150,   151,
       0,     0,     0,   384,   212,     0,   149,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,     0,     0,     0,   156,   157,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     0,
     152,     0,     0,   153,   154,   155,    68,     0,     0,   152,
     156,   157,   153,   154,   155,     3,     0,     0,   230,   156,
     157,     0,     0,     0,     0,   152,     0,   233,   153,   154,
     385,     0,     0,     0,     0,   156,   157,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    69,     2,    19,     0,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     3,    19,     0,    20,    21,    22,    23,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    69,     0,    19,     0,    20,    21,    22,
      23,     0,   361,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    69,     0,
      19,     0,    20,    21,    22,    23
};

static const yytype_int16 yycheck[] =
{
     130,   152,   153,   154,   155,   156,   157,    82,     1,   286,
       4,   131,     4,   221,     1,   223,   146,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    70,    28,    71,   159,
      32,     4,     4,    28,     4,    28,     4,    28,    39,   247,
      69,    42,    28,     4,    27,    28,    39,    69,    91,    42,
      69,    60,   252,    69,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    94,    69,    92,    53,    71,
       4,     3,    97,    53,   117,    93,    98,    95,    94,    98,
      65,    60,   359,     3,   284,    65,     6,    69,    89,    92,
     210,     4,   222,    76,    77,   225,    89,    97,   228,   229,
     230,    97,    53,   233,    98,    56,    98,     4,    80,    53,
      92,    92,    56,     4,   265,   266,   267,    60,    93,   112,
      95,    93,    53,   253,    97,   112,    97,    97,    53,    97,
      78,    79,    93,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      53,   283,   282,    53,   198,   198,    98,   287,   159,   310,
     311,   369,   163,    97,    96,   208,   159,   160,   163,    80,
     163,   301,   163,   160,   374,    72,    13,   163,   310,   311,
      93,    97,    95,    80,    70,   393,    53,   395,    53,    54,
      53,    56,   272,   273,   274,   275,    93,   198,    25,    26,
      65,    29,    30,   198,   355,   198,    53,   198,   268,   269,
     418,    94,   198,    97,   289,    52,    53,    54,    55,    56,
      57,    58,    59,   355,    61,   270,   271,    64,    65,    66,
     360,     3,   233,    72,   385,   365,    72,   367,   276,   277,
      52,    53,   286,   286,    56,   377,    13,    52,    53,    61,
      92,    56,    92,   385,     4,    93,    61,   387,    93,    93,
     390,   391,    93,     3,     4,    72,    74,     7,     8,     9,
      10,    11,    73,    13,    14,    15,    16,    17,    18,   409,
      20,    75,    22,    23,    24,    52,    53,    54,    55,    56,
      57,    58,    59,    31,    61,    69,    92,    64,    65,    66,
      80,    81,    82,    94,    69,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      96,    61,     3,    63,    64,    65,    66,     4,    92,    92,
       4,    98,    94,    94,    94,    75,     4,    20,    78,    79,
      80,    92,    94,    96,    72,    85,    86,    94,    94,    94,
      94,    94,    92,    93,    96,     3,     4,    97,    98,     7,
       8,     9,    10,    11,    96,    13,    14,    15,    16,    17,
      18,    93,    20,    92,    22,    23,    24,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    94,    96,    94,
      96,    94,    92,    94,    12,    94,    94,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    70,    61,    92,    63,    64,    65,    66,    94,
       3,     4,     1,   160,   286,    28,    93,    75,    42,   293,
      78,    79,    80,    89,    21,    22,    23,    85,    86,    22,
      23,    24,   208,   289,    92,    93,     3,     4,    26,    97,
       7,     8,     9,    10,    11,     3,     4,    14,    15,    16,
      17,    18,   280,    20,   283,    22,    23,    24,   278,   377,
     279,    -1,    -1,    -1,    22,    23,    24,   281,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    80,    22,    23,
      24,    -1,    85,    86,    91,    -1,    93,    -1,    95,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    75,    85,    86,
      78,    79,    80,     4,    -1,    92,    93,    85,    86,    -1,
      97,    -1,    13,    -1,    -1,    93,    -1,    -1,    96,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    96,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     4,
      61,    -1,    63,    64,    65,    66,    -1,    -1,    13,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,     3,     4,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    -1,    93,    -1,
      95,    85,    86,     3,     4,    22,    23,    24,    -1,    93,
      94,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      22,    23,    24,    -1,    -1,    75,    93,    94,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    75,    -1,    -1,
      78,    79,    80,    93,    94,    -1,    -1,    85,    86,     3,
       4,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,    75,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,     4,    61,    -1,    -1,
      64,    65,    66,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    75,     3,     4,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    22,    23,    24,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,    63,    64,    65,    66,     3,
       4,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    22,    23,
      24,    -1,    -1,    -1,    75,    -1,    94,    78,    79,    80,
       3,     4,    -1,    -1,    85,    86,    -1,    -1,    -1,     3,
       4,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    86,    22,    23,    24,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    75,    85,    86,    78,    79,    80,    -1,    -1,    92,
      93,    85,    86,     3,     4,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    80,    22,    23,    24,    -1,    85,    86,     3,     4,
      -1,    -1,    -1,    92,    93,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,     3,     4,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    75,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,     4,    -1,    -1,    75,
      85,    86,    78,    79,    80,    13,    -1,    -1,    93,    85,
      86,    -1,    -1,    -1,    -1,    75,    -1,    93,    78,    79,
      80,    -1,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,    61,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    13,    61,    -1,    63,    64,    65,    66,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    -1,    63,    64,    65,
      66,    -1,    68,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    -1,    63,    64,    65,    66
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
      70,    69,    98,    53,    53,    53,     3,     4,     7,     8,
       9,    10,    11,    14,    15,    16,    17,    18,    20,    22,
      23,    24,    75,    78,    79,    80,    85,    86,    92,    93,
     104,   105,   106,   107,   145,   146,   149,   152,   155,   157,
     158,   159,   160,   161,   162,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    94,   114,     4,    94,   107,   112,
     122,   123,   124,   183,     3,    96,     3,    72,    69,    92,
      69,    98,     4,   182,    98,   129,    92,     3,     6,   153,
      92,   150,    93,   154,     4,    93,    92,   182,    93,    93,
      93,   168,   168,    93,   168,   167,   168,   167,   167,   167,
     167,   167,   111,   112,   182,    98,   105,    72,    21,    22,
      23,    91,    93,    95,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    70,    80,    81,    82,    78,    79,
      25,    26,    27,    28,    76,    77,    29,    30,    73,    74,
      75,    32,    71,    31,    69,    92,    93,    95,   114,   118,
     119,   144,    94,    69,    69,    94,    96,     3,   139,    98,
     145,    92,   182,   145,    92,   182,    92,   182,   182,   111,
      94,    94,    94,   145,     4,     4,    94,   163,   180,   182,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   167,   167,   167,   169,   169,   170,   170,   171,   171,
     171,   171,   172,   172,   175,   176,   173,   178,   182,   174,
     180,    94,   119,   122,     3,    80,    96,   182,   144,    93,
      95,    68,   124,     4,    20,    92,   182,    92,    94,    94,
      94,    94,   167,   167,    69,    94,    96,    72,    94,    94,
      96,    96,    96,   122,     3,    80,   182,    93,    92,   182,
      92,    92,   182,   147,   145,   151,   180,   179,    94,    96,
      96,    96,   182,    94,    94,    94,   182,    94,   182,    92,
     145,   148,   145,    94,    94,    94,    94,   182,    12,    92,
      94,   145
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
     160,   160,   160,   160,   160,   160,   161,   162,   162,   163,
     163,   164,   164,   165,   166,   167,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   169,   170,   170,   170,   171,   171,   171,   172,
     172,   172,   172,   172,   173,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   181,   181,   182,   183,   183
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
       7,     0,     4,     2,     3,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     1,
       3,     3,     3,     2,     2,     1,     4,     4,     1,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     3
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
#line 86 "parse.y" /* yacc.c:1646  */
    {}
#line 1829 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "parse.y" /* yacc.c:1646  */
    {}
#line 1835 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "parse.y" /* yacc.c:1646  */
    {}
#line 1841 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "parse.y" /* yacc.c:1646  */
    {}
#line 1847 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "parse.y" /* yacc.c:1646  */
    {}
#line 1853 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = add_type_node((yyvsp[0].node), (yyvsp[-1].node));
                                         (yyval.node) = insert_sym((yyval.node)->ast_node.common_node.name,
                                                         (yyval.node)->ast_node.common_node.nspace,
                                                         (yyval.node),1);}
#line 1862 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "parse.y" /* yacc.c:1646  */
    {struct node* n = (struct node*) malloc(sizeof(struct node));
                                           (yyval.node) = n;
                                           (yyval.node)->flag = LIST;  
                                           (yyval.node)->ast_node.list_node.head_list = NULL; 
                                           if ((yyvsp[0].node) != NULL){
                                                (yyval.node)->ast_node.list_node.head_list = (yyvsp[0].node); 
                                          }}
#line 1874 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "parse.y" /* yacc.c:1646  */
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
#line 1889 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1895 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "parse.y" /* yacc.c:1646  */
    {}
#line 1901 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "parse.y" /* yacc.c:1646  */
    {}
#line 1907 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "parse.y" /* yacc.c:1646  */
    {}
#line 1913 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "parse.y" /* yacc.c:1646  */
    {}
#line 1919 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1925 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1931 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "parse.y" /* yacc.c:1646  */
    {}
#line 1937 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1943 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 1949 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1955 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "parse.y" /* yacc.c:1646  */
    {(yyvsp[0].node)->next = (yyvsp[-1].node);}
#line 1961 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 137 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1967 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1973 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_add_scalar_type((yyvsp[-1].node),(yyvsp[0].scalar_type));}
#line 1979 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 142 "parse.y" /* yacc.c:1646  */
    {
                                                         add_type_node((yyvsp[0].node),(yyvsp[-1].node));
                                                         (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                        (yyvsp[0].node)->ast_node.common_node.nspace,
                                                                        (yyvsp[0].node),1);
                                                        }
#line 1990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "parse.y" /* yacc.c:1646  */
    {
                                                        add_type_node((yyvsp[0].node), (yyvsp[-3].node));
                                                        (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                        (yyvsp[0].node)->ast_node.common_node.nspace,
                                                                        (yyvsp[0].node),1);
                                                        }
#line 2001 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_AUTO;}
#line 2007 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_EXTERN;}
#line 2013 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 159 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_REGISTER;}
#line 2019 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 160 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_STATIC;}
#line 2025 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 163 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INLINE;}
#line 2031 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 166 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2037 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2043 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2049 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SHORT;}
#line 2055 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 170 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2061 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 171 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2067 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 172 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_INT;}
#line 2073 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 173 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2079 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 174 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2085 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2091 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 176 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONG;}
#line 2097 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2103 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2109 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 179 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2115 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 180 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGLONG;}
#line 2121 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 181 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2127 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 182 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2133 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UINT;}
#line 2139 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 184 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2145 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 185 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 186 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 187 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2163 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 188 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2169 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 189 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_USHORT;}
#line 2175 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 190 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UINT;}
#line 2181 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 191 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2187 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 192 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONG;}
#line 2193 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 193 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2199 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 194 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_ULONGLONG;}
#line 2205 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 195 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_CHAR;}
#line 2211 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 196 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_SCHAR;}
#line 2217 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 197 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_UCHAR;}
#line 2223 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 198 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_BOOL;}
#line 2229 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 199 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_FLOAT;}
#line 2235 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 200 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_DOUBLE;}
#line 2241 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 201 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGDOUBLE;}
#line 2247 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 202 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_FLOATCOMPLEX;}
#line 2253 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 203 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_DOUBLECOMPLEX;}
#line 2259 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 204 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_LONGDOUBLECOMPLEX;}
#line 2265 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 205 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) =  T_VOID;}
#line 2271 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 208 "parse.y" /* yacc.c:1646  */
    {}
#line 2277 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 209 "parse.y" /* yacc.c:1646  */
    {}
#line 2283 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 210 "parse.y" /* yacc.c:1646  */
    {}
#line 2289 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_CONST;}
#line 2295 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 214 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_VOLATILE;}
#line 2301 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 215 "parse.y" /* yacc.c:1646  */
    {(yyval.scalar_type) = T_RESTRICT;}
#line 2307 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 218 "parse.y" /* yacc.c:1646  */
    {}
#line 2313 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "parse.y" /* yacc.c:1646  */
    {}
#line 2319 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 221 "parse.y" /* yacc.c:1646  */
    {}
#line 2325 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 222 "parse.y" /* yacc.c:1646  */
    {}
#line 2331 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 223 "parse.y" /* yacc.c:1646  */
    {}
#line 2337 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 224 "parse.y" /* yacc.c:1646  */
    {}
#line 2343 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name),I_NODE);}
#line 2349 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 229 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = add_type_node((yyvsp[0].node),(yyvsp[-1].node));}
#line 2355 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 232 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ptr();}
#line 2361 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 233 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ptr();
                                                 (yyvsp[0].node)->ast_node.ptr_node.ptr_to_node = (yyval.node);}
#line 2368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 237 "parse.y" /* yacc.c:1646  */
    {}
#line 2374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 238 "parse.y" /* yacc.c:1646  */
    {}
#line 2380 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 239 "parse.y" /* yacc.c:1646  */
    {}
#line 2386 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 242 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ary(0);
                                                 (yyval.node) = add_type_node((yyvsp[-2].node),(yyval.node));}
#line 2393 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 244 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ary((yyvsp[-1].number).number);
                                                 (yyval.node) = add_type_node((yyvsp[-3].node), (yyval.node));}
#line 2400 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 249 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-3].node));
                                                         (yyval.node)->next->ast_node.type_fn_node.arg = (yyvsp[-1].node);
                                                         }
#line 2408 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 252 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-2].node));}
#line 2414 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 253 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_func((yyvsp[-3].node));
                                                         (yyval.node)->next->ast_node.type_fn_node.arg = (yyvsp[-1].node);}
#line 2421 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 257 "parse.y" /* yacc.c:1646  */
    {}
#line 2427 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 258 "parse.y" /* yacc.c:1646  */
    {}
#line 2433 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 261 "parse.y" /* yacc.c:1646  */
    {}
#line 2439 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 262 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_add_arg((yyvsp[-2].node), (yyvsp[0].node));}
#line 2445 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 265 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_make_arg((yyvsp[-1].node), (yyvsp[0].node));}
#line 2451 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 266 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_func_make_arg((yyvsp[0].node), NULL);}
#line 2457 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 267 "parse.y" /* yacc.c:1646  */
    {}
#line 2463 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 270 "parse.y" /* yacc.c:1646  */
    {}
#line 2469 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 271 "parse.y" /* yacc.c:1646  */
    {}
#line 2475 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 274 "parse.y" /* yacc.c:1646  */
    {}
#line 2481 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 275 "parse.y" /* yacc.c:1646  */
    {}
#line 2487 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 276 "parse.y" /* yacc.c:1646  */
    {}
#line 2493 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 277 "parse.y" /* yacc.c:1646  */
    {}
#line 2499 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 280 "parse.y" /* yacc.c:1646  */
    {}
#line 2505 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 283 "parse.y" /* yacc.c:1646  */
    {}
#line 2511 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 284 "parse.y" /* yacc.c:1646  */
    {}
#line 2517 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 287 "parse.y" /* yacc.c:1646  */
    {}
#line 2523 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 288 "parse.y" /* yacc.c:1646  */
    {}
#line 2529 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 291 "parse.y" /* yacc.c:1646  */
    {
                                            struct sym_node* struct_sym;
                                            if ((struct_sym = lookup((yyvsp[-1].ident_name),N_TAGS,1)) == NULL){
                                                (yyval.node) = ast_new_struct((yyvsp[-1].ident_name), I_STRUCT_TAG_NODE);
                                                (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,N_TAGS,(yyval.node),1);
                                            }else{
                                                printf("You are wrong!\n");
                                            }}
#line 2542 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 300 "parse.y" /* yacc.c:1646  */
    {}
#line 2548 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 301 "parse.y" /* yacc.c:1646  */
    {}
#line 2554 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 304 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct(NULL, I_STRUCT_TAG_NODE) ; 
                                             (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                             N_TAGS, (yyval.node), 1);
                                             if ((yyval.node) != NULL){
                                                enter_block((yyval.node), 1);
                                                (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                             
                                             }
                                             }
#line 2568 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 314 "parse.y" /* yacc.c:1646  */
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
#line 2588 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 331 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->ast_node.struct_tag_node.isComplete = 1;
                                             struct sym_node* node = curr_scope->sym_node;
                                             //print_debug_stmt($<node>0);
                                             curr_scope = curr_scope->prev_scope;
                                             }
#line 2598 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 337 "parse.y" /* yacc.c:1646  */
    {
                                         struct sym_node* struct_sym;
                                         if ((struct_sym = lookup((yyvsp[0].ident_name),N_TAGS,0)) != NULL){
                                            (yyval.node) = struct_sym->ast_node;
                                         }else{
                                            (yyval.node) = ast_new_struct((yyvsp[0].ident_name), I_STRUCT_TAG_NODE);
                                            (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                            N_TAGS,(yyval.node), 1);
                                         }}
#line 2612 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 348 "parse.y" /* yacc.c:1646  */
    {}
#line 2618 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 349 "parse.y" /* yacc.c:1646  */
    {}
#line 2624 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 352 "parse.y" /* yacc.c:1646  */
    {}
#line 2630 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 354 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[0].scalar_type));}
#line 2636 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 355 "parse.y" /* yacc.c:1646  */
    {}
#line 2642 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 357 "parse.y" /* yacc.c:1646  */
    {add_type_node((yyvsp[0].node),(yyvsp[-1].node));
                                                                             (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                                             N_MINIDEFS,(yyvsp[0].node),1);}
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 360 "parse.y" /* yacc.c:1646  */
    {add_type_node((yyvsp[0].node),(yyvsp[-3].node));
                                                                             (yyval.node) = insert_sym((yyvsp[0].node)->ast_node.common_node.name,
                                                                                             N_MINIDEFS,(yyvsp[0].node),1);}
#line 2658 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 365 "parse.y" /* yacc.c:1646  */
    {}
#line 2664 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 366 "parse.y" /* yacc.c:1646  */
    {}
#line 2670 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 370 "parse.y" /* yacc.c:1646  */
    {}
#line 2676 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 371 "parse.y" /* yacc.c:1646  */
    {}
#line 2682 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 374 "parse.y" /* yacc.c:1646  */
    {}
#line 2688 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 375 "parse.y" /* yacc.c:1646  */
    {}
#line 2694 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 378 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct(NULL, I_UNION_TAG_NODE) ; 
                                                         (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                                        N_TAGS, (yyval.node), 1);
                                                         if ((yyval.node) != NULL){
                                                            enter_block((yyval.node), 1);
                                                            (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                                        }}
#line 2706 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 386 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct((yyvsp[-1].ident_name), I_UNION_TAG_NODE);
                                                         (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                                         N_TAGS, (yyval.node),1);
                                                         if ((yyval.node) != NULL){
                                                            enter_block((yyval.node),1);
                                                            (yyval.node)->ast_node.struct_tag_node.sym_table = curr_scope;
                                                         }}
#line 2718 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 395 "parse.y" /* yacc.c:1646  */
    {struct sym_node* struct_sym;
                                     if ((struct_sym = lookup((yyvsp[0].ident_name),N_TAGS,0)) != NULL){
                                        (yyval.node) = struct_sym->ast_node;
                                     }else{
                                        (yyval.node) = ast_new_struct((yyvsp[0].ident_name), I_UNION_TAG_NODE);
                                        (yyval.node) = insert_sym((yyval.node)->ast_node.struct_tag_node.node.name,
                                                        N_TAGS,(yyval.node), 1);
                                     }}
#line 2731 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 404 "parse.y" /* yacc.c:1646  */
    {}
#line 2737 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 405 "parse.y" /* yacc.c:1646  */
    {}
#line 2743 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 406 "parse.y" /* yacc.c:1646  */
    {}
#line 2749 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 407 "parse.y" /* yacc.c:1646  */
    {}
#line 2755 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 408 "parse.y" /* yacc.c:1646  */
    {}
#line 2761 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 409 "parse.y" /* yacc.c:1646  */
    {}
#line 2767 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 410 "parse.y" /* yacc.c:1646  */
    {}
#line 2773 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 411 "parse.y" /* yacc.c:1646  */
    {}
#line 2779 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 412 "parse.y" /* yacc.c:1646  */
    {}
#line 2785 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 413 "parse.y" /* yacc.c:1646  */
    {}
#line 2791 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 414 "parse.y" /* yacc.c:1646  */
    {}
#line 2797 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 416 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2803 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 417 "parse.y" /* yacc.c:1646  */
    {
                                             if ((yyvsp[-2].node)->flag == ST_CASE){
                                                (yyvsp[-2].node)->ast_node.case_node.stmt = (yyvsp[0].node);
                                             }else if ((yyvsp[-2].node)->flag == ST_DEFAULT){
                                                (yyvsp[-2].node)->ast_node.default_node.stmt = (yyvsp[0].node);
                                             }else{
                                                (yyvsp[-2].node)->ast_node.stmt_label_node.stmt = (yyvsp[0].node);
                                             }
                                             (yyval.node) = (yyvsp[-2].node);}
#line 2817 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 426 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2823 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 427 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2829 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 428 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2835 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 429 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_switch((yyvsp[-2].node), (yyvsp[0].node)); 
                                             make_switch_map((yyval.node), (yyvsp[0].node));}
#line 2842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 431 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_stmt(ST_BREAK);}
#line 2848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 432 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_stmt(ST_CONTINUE);}
#line 2854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 433 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n;
                                             if ((n = lookup((yyvsp[-1].ident_name), N_LABELS, 0)) == NULL){
                                                (yyval.node) = ast_new_ident((yyvsp[-1].ident_name),I_STMT_LABEL_NODE);
                                                (yyval.node) = insert_sym((yyvsp[-1].ident_name),N_LABELS,(yyval.node),1);
                                            }else{
                                                (yyval.node) = n->ast_node;
                                            }
                                             (yyval.node) = ast_new_goto((yyval.node));}
#line 2867 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 441 "parse.y" /* yacc.c:1646  */
    {}
#line 2873 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 442 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2879 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 445 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_if((yyvsp[-1].node), NULL,NULL);}
#line 2885 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 445 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2891 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 448 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.if_node.action = (yyvsp[0].node);(yyval.node) = (yyvsp[-1].node);}
#line 2897 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 449 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-3].node)->ast_node.if_node.else_action = (yyvsp[0].node); (yyvsp[-3].node)->ast_node.if_node.action = (yyvsp[-2].node);(yyval.node) = (yyvsp[-3].node);}
#line 2903 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 451 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_do(NULL,NULL);}
#line 2909 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 451 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-6].node)->ast_node.do_node.cond = (yyvsp[-2].node);
                                                                                                 (yyvsp[-6].node)->ast_node.do_node.stmt = (yyvsp[-5].node);
                                                                                                 (yyval.node) = (yyvsp[-6].node);}
#line 2917 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 454 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_while((yyvsp[-1].node), NULL);}
#line 2923 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 454 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.while_node.action = (yyvsp[0].node);
                                                                                                  (yyval.node) = (yyvsp[-1].node);}
#line 2930 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 456 "parse.y" /* yacc.c:1646  */
    {(yyvsp[-1].node)->ast_node.for_node.stmt = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node);}
#line 2936 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 459 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n;
                                     if ((n = lookup((yyvsp[0].ident_name), N_LABELS, 0)) == NULL){
                                        (yyval.node) = ast_new_ident((yyvsp[0].ident_name),I_STMT_LABEL_NODE);
                                        (yyval.node) = insert_sym((yyvsp[0].ident_name),N_LABELS,(yyval.node),1);
                                    }else{
                                        (yyval.node) = n->ast_node;
                                    }}
#line 2948 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 466 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_case((yyvsp[0].node));}
#line 2954 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 467 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_case(NULL);}
#line 2960 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 471 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const((yyvsp[0].number).number);}
#line 2966 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 472 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const_char((yyvsp[0].char_lit).actual_char);}
#line 2972 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 475 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,NULL,NULL);}
#line 2978 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 476 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-3].node),NULL,NULL);}
#line 2984 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 477 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,(yyvsp[-2].node),NULL);}
#line 2990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 478 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,NULL,(yyvsp[-1].node));}
#line 2996 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 479 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-4].node),(yyvsp[-2].node),NULL);}
#line 3002 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 480 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-4].node),NULL,(yyvsp[-1].node));}
#line 3008 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 481 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for(NULL,(yyvsp[-3].node),(yyvsp[-1].node));}
#line 3014 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 482 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_for((yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node));}
#line 3020 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 485 "parse.y" /* yacc.c:1646  */
    {enter_block((yyvsp[-1].node), 0);}
#line 3026 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 485 "parse.y" /* yacc.c:1646  */
    { print_func_dump(0, (yyvsp[-1].node), (yyvsp[-4].node));
                                                                             if (curr_scope->scope_num == S_FUNCTION)
                                                                                fn_counter += 1;
                                                                             generate_quads((yyvsp[-1].node), curr_scope->scope_num);
                                                                             leave_block();
                                                                             (yyval.node) = (yyvsp[-1].node);}
#line 3037 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 491 "parse.y" /* yacc.c:1646  */
    {}
#line 3043 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 494 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_return((yyvsp[-1].node));}
#line 3049 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 495 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_return(NULL);}
#line 3055 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 498 "parse.y" /* yacc.c:1646  */
    {}
#line 3061 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 501 "parse.y" /* yacc.c:1646  */
    {struct sym_node* n = lookup((yyvsp[0].ident_name), N_OTHERS, 0);
                                     (yyval.node) = n->ast_node;}
#line 3068 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 503 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const((yyvsp[0].number).number);}
#line 3074 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 504 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 3080 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 507 "parse.y" /* yacc.c:1646  */
    {}
#line 3086 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 508 "parse.y" /* yacc.c:1646  */
    {}
#line 3092 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 509 "parse.y" /* yacc.c:1646  */
    {}
#line 3098 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 510 "parse.y" /* yacc.c:1646  */
    {}
#line 3104 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 511 "parse.y" /* yacc.c:1646  */
    {}
#line 3110 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 512 "parse.y" /* yacc.c:1646  */
    {}
#line 3116 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 515 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD,(yyvsp[-3].node),(yyvsp[-1].node));
                                                   (yyval.node) = ast_new_deref((yyval.node));}
#line 3123 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 519 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_fn_call((yyvsp[-1].node), (yyvsp[-3].node));}
#line 3129 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 520 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_fn_call(NULL,(yyvsp[-2].node));}
#line 3135 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 523 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_expr_arg(NULL,(yyvsp[0].node));}
#line 3141 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 524 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_expr_arg((yyvsp[-2].node), (yyvsp[0].node));}
#line 3147 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 527 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_indsel(E_DOT, (yyvsp[-2].node), (yyvsp[0].ident_name));}
#line 3153 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 528 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_indsel(E_INDSEL, (yyvsp[-2].node), (yyvsp[0].ident_name));}
#line 3159 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 531 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_POSTINC, (yyvsp[-1].node));}
#line 3165 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 533 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_POSTDEC, (yyvsp[-1].node));}
#line 3171 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 537 "parse.y" /* yacc.c:1646  */
    {}
#line 3177 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 538 "parse.y" /* yacc.c:1646  */
    {}
#line 3183 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 539 "parse.y" /* yacc.c:1646  */
    {}
#line 3189 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 542 "parse.y" /* yacc.c:1646  */
    {}
#line 3195 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 543 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_scalar_type((yyvsp[-1].scalar_type));
                                                                 (yyval.node) = ast_new_unary(E_SIZEOF, (yyval.node));}
#line 3202 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 545 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_SIZEOF, (yyvsp[0].node));}
#line 3208 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 546 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_UMINUS, (yyvsp[0].node));}
#line 3214 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 547 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_UPLUS, (yyvsp[0].node));}
#line 3220 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 548 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_LOGNOT, (yyvsp[0].node));}
#line 3226 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 549 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_BITNOT, (yyvsp[0].node));}
#line 3232 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 550 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary(E_ADDRESS, (yyvsp[0].node));}
#line 3238 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 551 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_deref((yyvsp[0].node));}
#line 3244 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 552 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const(1);
                                                                 (yyval.node) = ast_new_binop(E_ADD, (yyvsp[0].node), (yyval.node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[0].node), (yyval.node));}
#line 3252 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 555 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_const(1);
                                                                 (yyval.node) = ast_new_binop(E_MINUS, (yyvsp[0].node), (yyval.node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[0].node), (yyval.node));}
#line 3260 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 560 "parse.y" /* yacc.c:1646  */
    {}
#line 3266 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 561 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MUL,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3272 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 562 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_DIV,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 563 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MOD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3284 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 565 "parse.y" /* yacc.c:1646  */
    {}
#line 3290 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 566 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 567 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MINUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 570 "parse.y" /* yacc.c:1646  */
    {}
#line 3308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 571 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHL, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 572 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 576 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 577 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_GT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3332 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 578 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LTEQ, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 579 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_GTEQ, (yyvsp[-2].node),(yyvsp[0].node));}
#line 3344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 582 "parse.y" /* yacc.c:1646  */
    {}
#line 3350 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 583 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3356 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 584 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 3362 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 587 "parse.y" /* yacc.c:1646  */
    {}
#line 3368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 588 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_OR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 591 "parse.y" /* yacc.c:1646  */
    {}
#line 3380 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 592 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_XOR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3386 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 595 "parse.y" /* yacc.c:1646  */
    {}
#line 3392 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 596 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_AND,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3398 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 599 "parse.y" /* yacc.c:1646  */
    {}
#line 3404 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 600 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LOGOR,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3410 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 603 "parse.y" /* yacc.c:1646  */
    {}
#line 3416 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 604 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_LOGAND,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3422 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 607 "parse.y" /* yacc.c:1646  */
    {}
#line 3428 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 608 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ACTION,(yyvsp[-2].node),(yyvsp[0].node));
                                                                             (yyval.node) = ast_new_binop(E_COND,(yyvsp[-4].node),(yyval.node));}
#line 3435 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 612 "parse.y" /* yacc.c:1646  */
    {}
#line 3441 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 613 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_assign((yyvsp[-2].node), (yyvsp[0].node));}
#line 3447 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 614 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_ADD, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3454 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 616 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MINUS, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3461 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 618 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MUL, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 620 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_DIV, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3475 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 622 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_MOD, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3482 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 624 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHL, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3489 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 626 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_SHR, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3496 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 628 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_AND, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3503 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 630 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_OR, (yyvsp[-2].node), (yyvsp[0].node));  
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3510 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 632 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binop(E_XOR, (yyvsp[-2].node), (yyvsp[0].node));
                                                                 (yyval.node) = ast_new_assign((yyvsp[-2].node), (yyval.node));}
#line 3517 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 636 "parse.y" /* yacc.c:1646  */
    {}
#line 3523 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 637 "parse.y" /* yacc.c:1646  */
    {struct node* n = (yyvsp[-2].node);
                                                     while(n->next != NULL){n=n->next;}
                                                     n->next = (yyvsp[0].node);}
#line 3531 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 642 "parse.y" /* yacc.c:1646  */
    {}
#line 3537 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 645 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name), 0);}
#line 3543 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 646 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].ident_name), 0);}
#line 3549 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3553 "parse.tab.c" /* yacc.c:1646  */
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
#line 650 "parse.y" /* yacc.c:1906  */


int main(int argc, char* argv[]){
    yyin = fopen(argv[1],"r");
    list = (struct node*) malloc(sizeof(struct node));
    list->flag = LIST;
    do{
        yyparse();
    }while(!feof(yyin));
    return 0;
    // pointers and array pointers
}

void yyerror(char *s){
    fprintf(stderr , "syntax error: %s\n", s);
}
