/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "parse.y" /* yacc.c:1909  */

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

#line 151 "parse.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
