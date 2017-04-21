%option noyywrap

%{
    // DEFINITIONS
    #include "parse.tab.h"
    #include <stdlib.h>
    #define YY_DECL int yylex()
    #define OCT_OUT_OF_RANGE 1
    int line_num;
    int char_size;
    char *fname;
    char *char_ind;
    char char_buffer[4096];
    YYSTYPE yylval;

enum constants_numberspec{
    C_REAL = 0,
    C_INTEGER,
};

enum constants_sizespec{
    C_FLOAT = 1,
    C_DOUBLE,
    C_LONGDOUBLE,
    C_INT,
    C_LONG,
    C_LONGLONG,
};

char* tokens_names[60] = {"INDSEL","PLUSPLUS","MINUSMINUS","SHL","SHR","LTEQ","GTEQ","EQEQ",
                          "NOTEQ","LOGAND","LOGOR","ELLIPSIS","TIMESEQ","DIVEQ","MODEQ","PLUSEQ",
                          "MINUSEQ","SHLEQ","SHREQ","ANDEQ","OREQ","XOREQ","PDPD","AUTO",
                          "BREAK","CASE","CHAR","CONST","CONTINUE","DEFAULT","DO","DOUBLE",
                          "ELSE","ENUM","EXTERN","FLOAT","FOR","GOTO","IF","INLINE","INT",
                          "LONG","REGISTER","RESTRICT","RETURN","SHORT","SIGNED","SIZEOF",
                          "STATIC","STRUCT","SWITCH","TYPEDEF","UNION","UNSIGNED","VOID",
                          "VOLATILE","WHILE","_BOOL","_COMPLEX","_IMAGINARY"};
%}

DIGIT       [0-9]
OCTALDIGIT  [0-7]
HEXDIGIT    [0-9A-Fa-f]
NONDIGIT    [A-Za-z_]
ESCAPESEQ   [abfnrtv'\"\?\\]
CHARSET_CHAR     [a-zA-Z0-9_\{\}\[\]#\(\)<>%:/\.\?\*\+\-\^&\|~!=,\"]
%x BEGIN_CHAR
%x BEGIN_STR
%%
%{
    // RULES
%}
[ \t]+ {}
%{
    // KEYWORDS
%}
auto        {return AUTO;}
break       {return BREAK;}
case        {return CASE;}
char        {return CHAR;}
const       {return CONST;}
continue    {return CONTINUE;}
default     {return DEFAULT;}
do          {return DO;}
double      {return DOUBLE;}
else        {return ELSE;}
enum        {return ENUM;}
extern      {return EXTERN;}
float       {return FLOAT;}
for         {return FOR;}
goto        {return GOTO;}
if          {return IF;}
inline      {return INLINE;}
int         {return INT;}
long        {return LONG;}
register    {return REGISTER;}
restrict    {return RESTRICT;}
return      {return RETURN;}
short       {return SHORT;}
signed      {return SIGNED;}
sizeof      {return SIZEOF;}
static      {return STATIC;}
struct      {return STRUCT;}
switch      {return SWITCH;}
typedef     {return TYPEDEF;}
union       {return UNION;}
unsigned    {return UNSIGNED;}
void        {return VOID;}
volatile    {return VOLATILE;}
while       {return WHILE;}
_Bool       {return _BOOL;}
_Complex    {return _COMPLEX;}
_Imaginary  {return _IMAGINARY;}

%{
    // IDENTIFIERS
%}

[A-Za-z_][A-Za-z0-9_]* {yylval.ident_name = (char*) malloc(sizeof(yytext)+1); 
                        strcpy(yylval.ident_name, yytext);
                        return IDENT;}

%{
    // NUMERICAL CONSTANTS
%}

[1-9][0-9]*            {yylval.number.number=  strtol(yytext, NULL, 10);
                        yylval.number.num_numberspec = C_INTEGER; 
                        yylval.number.num_sizespec = C_INT;
                        yylval.number.num_unsigned = 0;
                        return NUMBER;}

[1-9][0-9]*[uU]      {yylval.number.number = strtol(yytext, NULL, 10);
                      yylval.number.num_numberspec = C_INTEGER;
                      yylval.number.num_sizespec = C_INT;
                      yylval.number.num_unsigned = 1;
                      return NUMBER;}

[1-9][0-9]*[lL]     {yylval.number.number = strtol(yytext, NULL, 10);
                     yylval.number.num_numberspec = C_INTEGER;
                     yylval.number.num_sizespec = C_LONG;
                     yylval.number.num_unsigned = 0;
                     return NUMBER;}

[1-9][0-9]*((ll)|(LL))     {yylval.number.number = strtol(yytext, NULL, 10);
                            yylval.number.num_numberspec = C_INTEGER;
                            yylval.number.num_sizespec = C_LONGLONG;
                            yylval.number.num_unsigned = 0;
                            return NUMBER;}

[1-9][0-9]*(([uU][lL])|([lL][uU]))     {yylval.number.number = strtol(yytext, NULL, 10);
                                        yylval.number.num_numberspec = C_INTEGER;
                                        yylval.number.num_sizespec = C_LONG;
                                        yylval.number.num_unsigned = 1;
                                        return NUMBER;}

[1-9][0-9]*(([uU]((ll)|(LL)))|(((ll)|(LL))[uU]))     {yylval.number.number = strtol(yytext, NULL, 10);
                                                     yylval.number.num_numberspec = C_INTEGER;
                                                     yylval.number.num_sizespec = C_LONGLONG;
                                                     yylval.number.num_unsigned = 1;
                                                     return NUMBER;}

0[xX][0-9a-fA-F]*            {yylval.number.number=  strtol(yytext, NULL, 16);
                              yylval.number.num_numberspec = C_INTEGER; 
                              yylval.number.num_sizespec = C_INT;
                              yylval.number.num_unsigned = 0;
                              return NUMBER;}

0[xX][0-9a-fA-F]*[uU]      {yylval.number.number = strtol(yytext, NULL, 16);
                            yylval.number.num_numberspec = C_INTEGER;
                            yylval.number.num_sizespec = C_INT;
                            yylval.number.num_unsigned = 1;
                            return NUMBER;}

0[xX][0-9a-fA-F]*[lL]     {yylval.number.number = strtol(yytext, NULL, 16);
                           yylval.number.num_numberspec = C_INTEGER;
                           yylval.number.num_sizespec = C_LONG;
                           yylval.number.num_unsigned = 0;
                           return NUMBER;}

0[xX][0-9a-fA-F]*((ll)|(LL))     {yylval.number.number = strtol(yytext, NULL, 16);
                                  yylval.number.num_numberspec = C_INTEGER;
                                  yylval.number.num_sizespec = C_LONGLONG;
                                  yylval.number.num_unsigned = 0;
                                  return NUMBER;}

0[xX][0-9a-fA-F]*(([uU][lL])|([lL][uU]))     {yylval.number.number = strtol(yytext, NULL, 16);
                                              yylval.number.num_numberspec = C_INTEGER;
                                              yylval.number.num_sizespec = C_LONG;
                                              yylval.number.num_unsigned = 1;
                                              return NUMBER;}

0[xX][0-9a-fA-F]*(([uU]((ll)|(LL)))|(((ll)|(LL))[uU]))     {yylval.number.number = strtol(yytext, NULL, 16);
                                                           yylval.number.num_numberspec = C_INTEGER;
                                                           yylval.number.num_sizespec = C_LONGLONG;
                                                           yylval.number.num_unsigned = 1;
                                                           return NUMBER;}

0[0-7]*            {yylval.number.number=  strtol(yytext, NULL, 8);
                    yylval.number.num_numberspec = C_INTEGER; 
                    yylval.number.num_sizespec = C_INT;
                    yylval.number.num_unsigned = 0;
                    return NUMBER;}

0[0-7]*[uU]      {yylval.number.number = strtol(yytext, NULL, 8);
                  yylval.number.num_numberspec = C_INTEGER;
                  yylval.number.num_sizespec = C_INT;
                  yylval.number.num_unsigned = 1;
                  return NUMBER;}

0[0-7]*[lL]     {yylval.number.number = strtol(yytext, NULL, 8);
                 yylval.number.num_numberspec = C_INTEGER;
                 yylval.number.num_sizespec = C_LONG;
                 yylval.number.num_unsigned = 0;
                 return NUMBER;}

0[0-7]*((ll)|(LL))     {yylval.number.number = strtol(yytext, NULL, 8);
                        yylval.number.num_numberspec = C_INTEGER;
                        yylval.number.num_sizespec = C_LONGLONG;
                        yylval.number.num_unsigned = 0;
                        return NUMBER;}

0[0-7]*(([uU][lL])|([lL][uU]))     {yylval.number.number = strtol(yytext, NULL, 8);
                                    yylval.number.num_numberspec = C_INTEGER;
                                    yylval.number.num_sizespec = C_LONG;
                                    yylval.number.num_unsigned = 1;
                                    return NUMBER;}

0[0-7]*(([uU]((ll)|(LL)))|(((ll)|(LL))[uU]))     {yylval.number.number = strtol(yytext, NULL, 8);
                                                 yylval.number.num_numberspec = C_INTEGER;
                                                 yylval.number.num_sizespec = C_LONGLONG;
                                                 yylval.number.num_unsigned = 1;
                                                 return NUMBER;}

(([0-9]*\.[0-9]+)|([0-9]+\.))([eE][\+\-]?[0-9]+)? {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                   yylval.number.num_numberspec = C_REAL; 
                                                   yylval.number.num_sizespec = C_DOUBLE;
                                                   return NUMBER;}

(([0-9]*\.[0-9]+)|([0-9]+\.))([eE][\+\-]?[0-9]+)?[fF] {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                       yylval.number.num_numberspec = C_REAL; 
                                                       yylval.number.num_sizespec = C_FLOAT;
                                                       return NUMBER;}

(([0-9]*\.[0-9]+)|([0-9]+\.))([eE][\+\-]?[0-9]+)?[lL] {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                       yylval.number.num_numberspec = C_REAL; 
                                                       yylval.number.num_sizespec = C_LONGDOUBLE;
                                                       return NUMBER;}

[0-9]+[eE][\+\-]?[0-9]+  {sscanf(yytext,"%Lf", &yylval.number.doub_number);
                          yylval.number.num_numberspec = C_REAL;
                          yylval.number.num_sizespec = C_DOUBLE;
                          return NUMBER;}

[0-9]+[eE][\+\-]?[0-9]+[fF]  {sscanf(yytext,"%Lf", &yylval.number.doub_number);
                              yylval.number.num_numberspec = C_REAL;
                              yylval.number.num_sizespec = C_FLOAT;
                              return NUMBER;}

[0-9]+[eE][\+\-]?[0-9]+[lL]  {sscanf(yytext,"%Lf", &yylval.number.doub_number);
                              yylval.number.num_numberspec = C_REAL;
                              yylval.number.num_sizespec = C_LONGDOUBLE;
                              return NUMBER;}

0[xX](([0-9a-fA-F]+\.)|([0-9a-fA-F]\.[0-9a-fA-F]))p[\+\-]?[0-9]+    {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                                     yylval.number.num_numberspec = C_REAL;
                                                                     yylval.number.num_sizespec = C_DOUBLE;
                                                                     return NUMBER;}

0[xX](([0-9a-fA-F]+\.)|([0-9a-fA-F]\.[0-9a-fA-F]))p[\+\-]?[0-9]+[fF]    {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                                         yylval.number.num_numberspec = C_REAL;
                                                                         yylval.number.num_sizespec = C_FLOAT;
                                                                         return NUMBER;}

0[xX](([0-9a-fA-F]+\.)|([0-9a-fA-F]\.[0-9a-fA-F]))p[\+\-]?[0-9]+[lL]    {sscanf(yytext,"%Lf",&yylval.number.doub_number);
                                                                         yylval.number.num_numberspec = C_REAL;
                                                                         yylval.number.num_sizespec = C_LONGDOUBLE;
                                                                         return NUMBER;}

0[xX][0-9a-fA-F]+p[\+\-]?[0-9]+ {sscanf(yytext, "%Lf", &yylval.number.doub_number);
                                 yylval.number.num_numberspec = C_REAL;
                                 yylval.number.num_sizespec = C_DOUBLE;
                                 return NUMBER;}

0[xX][0-9a-fA-F]+p[\+\-]?[0-9]+[fF] {sscanf(yytext, "%Lf", &yylval.number.doub_number);
                                     yylval.number.num_numberspec = C_REAL;
                                     yylval.number.num_sizespec = C_FLOAT;
                                     return NUMBER;}

0[xX][0-9a-fA-F]+p[\+\-]?[0-9]+[lL] {sscanf(yytext, "%Lf", &yylval.number.doub_number);
                                     yylval.number.num_numberspec = C_REAL;
                                     yylval.number.num_sizespec = C_DOUBLE;
                                     return NUMBER;}
%{
    // CHARACTER LITERALS / CONSTANTS
%}
\'  {BEGIN(BEGIN_CHAR); char_size = 0; char_ind = char_buffer;}
<BEGIN_CHAR>{
    \'  {BEGIN(INITIAL);
         if (char_size == 0){
            yylval.char_lit.actual_char = '\0';
         }else{
            if (char_size > 1){
                fprintf(stderr,"%s:%d:Warning:Unsupported multibyte character literal truncated to first byte\n", fname, line_num);
            }
            yylval.char_lit.actual_char = char_buffer[0];   
         }
         return CHARLIT;}
    \\0  {*char_ind = '\0'; char_size++; char_ind++;}
    \\a  {*char_ind = '\a'; char_size++; char_ind++;}
    \\b  {*char_ind = '\b'; char_size++; char_ind++;}
    \\f  {*char_ind = '\f'; char_size++; char_ind++;}
    \\n  {*char_ind = '\n'; char_size++; char_ind++;}
    \\r  {*char_ind = '\r'; char_size++; char_ind++;}
    \\t  {*char_ind = '\t'; char_size++; char_ind++;}
    \\v  {*char_ind = '\v'; char_size++; char_ind++;}
    \\'  {*char_ind = '\''; char_size++; char_ind++;}
    \\\" {*char_ind = '"'; char_size++; char_ind++;}
    \\   {*char_ind = '\\'; char_size++; char_ind++;}
    \\\?  {*char_ind = '?';  char_size++; char_ind++;}
    \\{OCTALDIGIT}+ {
                        unsigned int oct_num = (unsigned int)strtol(yytext+1, &yytext+sizeof(yytext),8);
                        if (oct_num> 0xff){
                            fprintf(stderr,"%s:%d:Warning:Oct escape sequence \\%03o out of range\n", fname, line_num, oct_num);
                        }
                        *char_ind = (char) oct_num;
                        char_size++;
                        char_ind++;
                    }

    \\x{HEXDIGIT}+  {
                        unsigned int hex_num = (unsigned int) strtol(yytext+2, &yytext+sizeof(yytext),16);
                        if (hex_num > 0xff){
                            fprintf(stderr,"%s:%d:Warning:Hex escape sequence \\x%02x out of range\n",fname, line_num, hex_num);
                        }
                        *char_ind = (char) hex_num;
                        char_size++;
                        char_ind++;
                    }
    ({CHARSET_CHAR}|[ ]) {*char_ind = yytext[0];char_ind++;char_size++;}
}

%{
    // STRING LITERALS
%}
\" {BEGIN(BEGIN_STR); char_ind = char_buffer; yylval.string_lit.string_size = 0;}

<BEGIN_STR>{
    \"  {BEGIN(INITIAL);
         yylval.string_lit.string_literal = (char*) malloc(yylval.string_lit.string_size+1);
         memcpy(yylval.string_lit.string_literal, char_buffer, yylval.string_lit.string_size);
         return STRING;
        }
    \\0  {*char_ind = '\0'; yylval.string_lit.string_size++; char_ind++;}
    \\a  {*char_ind = '\a'; yylval.string_lit.string_size++; char_ind++;}
    \\b  {*char_ind = '\b'; yylval.string_lit.string_size++; char_ind++;}
    \\f  {*char_ind = '\f'; yylval.string_lit.string_size++; char_ind++;}
    \\n  {*char_ind = '\n'; yylval.string_lit.string_size++; char_ind++;}
    \\r  {*char_ind = '\r'; yylval.string_lit.string_size++; char_ind++;}
    \\t  {*char_ind = '\t'; yylval.string_lit.string_size++; char_ind++;}
    \\v  {*char_ind = '\v'; yylval.string_lit.string_size++; char_ind++;}
    \\'  {*char_ind = '\''; yylval.string_lit.string_size++; char_ind++;}
    \\\" {*char_ind = '"' ; yylval.string_lit.string_size++; char_ind++;}
    \\   {*char_ind = '\\'; yylval.string_lit.string_size++; char_ind++;}
    \\\? {*char_ind = '?';  yylval.string_lit.string_size++; char_ind++;}
    \\{OCTALDIGIT}+ {
                        unsigned int oct_num = (unsigned int)strtol(yytext+1, &yytext+sizeof(yytext),8);
                        if (oct_num> 0xff){
                            fprintf(stderr,"%s:%d:Warning:Oct escape sequence \\%03o out of range\n", fname, line_num, oct_num);
                            oct_num = 0xff;
                        }
                        *char_ind = (char) oct_num;
                        char_ind++;
                        yylval.string_lit.string_size++;
                    }

    \\x{HEXDIGIT}+  {
                        unsigned int hex_num = (unsigned int) strtol(yytext+2, &yytext+sizeof(yytext),16);
                        if (hex_num > 0xff){
                            fprintf(stderr,"%s:%d:Warning:Hex escape sequence \\x%02x out of range\n",fname, line_num, hex_num);
                            hex_num = 0xff;
                        }
                        *char_ind =  (char) hex_num;
                        char_ind++;
                        yylval.string_lit.string_size++;
                    }
    ({CHARSET_CHAR}|[ ]) {*char_ind = (char)yytext[0];char_ind++; yylval.string_lit.string_size++;}

    
}

%{
    // OPERATORS
%}

\+  {return '+';}
\-  {return '-';}
\{  {return '{';}
\}  {return '}';}
\(  {return '(';}
\)  {return ')';}
\.  {return '.';}
\]  {return ']';}
\&  {return '&';}
\*  {return '*';}
~   {return '~';}
!   {return '!';}
\/  {return '/';}
%   {return '%';}
\<  {return '<';}
>   {return '>';}
\^  {return '^';}
\|  {return '|';}
\?  {return '?';}
:   {return ':';}
;   {return ';';}
=   {return '=';}
,   {return ',';}
#   {return '#';}
\->     {return INDSEL;}
\+\+    {return PLUSPLUS;}
\-\-    {return MINUSMINUS;}
\<\<    {return SHL;}
>>      {return SHR;}
\<=     {return LTEQ;}
>=      {return GTEQ;}
==      {return EQEQ;}
!=      {return NOTEQ;}
\&\&    {return LOGAND;}
\|\|    {return LOGOR;}
\.\.\.  {return ELLIPSIS;}
\*=     {return TIMESEQ;}
\/=     {return DIVEQ;}
%=      {return MODEQ;}
\+=     {return PLUSEQ;}
\-=     {return MINUSEQ;}
\<\<=   {return SHLEQ;}
>>=     {return SHREQ;}
\&=     {return ANDEQ;}
\|=     {return OREQ;}
\^=     {return XOREQ;}

\[  {return '[';}
^#[ ]+[0-9]+[ ].+ {strtok(yytext," \"");
                   line_num = atoi(strtok(NULL, " \"")) -1; 
                   char* temp=strtok(NULL," \""); 
                   fname = realloc(fname, strlen(temp)+1);
                   strncpy(fname,temp, strlen(temp)+1);}  
\\.*    {} 
\n {line_num++;}
.       {fprintf(stderr, "%s:%d: Error: unrecognized character '%s'\n", fname, line_num,yytext);exit(-1);}
%%

void printChar(char ch){
    switch(ch){
        case '\0':
            fprintf(stdout,"\\0");
            break;
        case '\a':
            fprintf(stdout,"\\a");
            break;
        case '\b':
            fprintf(stdout,"\\b");
            break;
        case '\f':
            fprintf(stdout, "\\f");
            break;
        case '\n':
            fprintf(stdout,"\\n");
            break;
        case '\r':
            fprintf(stdout,"\\r");
            break;
        case '\t':
            fprintf(stdout,"\\t");
            break;
        case '\v':
            fprintf(stdout,"\\v");
            break;
        case '\'':
            fprintf(stdout,"\\\'");
            break;
        case '\"':
            fprintf(stdout,"\\\"");
            break;
        case '\\':
            fprintf(stdout,"\\");
            break;
        default:
            if (ch < 177 && ch > 31){
                fprintf(stdout,"%c",ch);
            }else{
                fprintf(stdout,"\\%03o", (unsigned char)ch);
            }
            break;
    }
}

/*int main(int argc, char *argv[]){
    int t;
    FILE *fd;
    char *ptr;
    ssize_t ret;
    char * line = NULL;
    size_t len = 0;
    int str_size;
    fd = fopen(argv[1], "r");
    yyin = fd;
    while (t = yylex()){
        if (t < 257 && t > 0){
            fprintf(stdout, "%s\t%d\t%c\t\n", fname, line_num, t);
            
        }else if (t == IDENT){      // 257
            fprintf(stdout, "%s\t%d\tIDENT\t%s\n", fname, line_num, yylval.ident_name);
            free(yylval.ident_name);
        }else if (t == CHARLIT){    // 258
            fprintf(stdout,"%s\t%d\tCHARLIT\t",fname, line_num);
            printChar(yylval.actual_char);
            fprintf(stdout,"\n");
        }else if (t == STRING){     // 259
            fprintf(stdout,"%s\t%d\tSTRING\t", fname, line_num);
            ptr = yylval.string_literal;
            str_size = 0;
            while (str_size < yylval.string_size){
                printChar(*ptr);
                ptr++;
                str_size++;
            }
            printf("\n");
            free(yylval.string_literal);
        }else if (t == NUMBER){     // 260
            fprintf(stdout, "%s\t%d\tNUMBER\t", fname, line_num);
            if (yylval.num_numberspec == C_INTEGER){
                fprintf(stdout,"INTEGER\t%llu\t", yylval.number);
                if (yylval.num_unsigned == 1){
                    fprintf(stdout,"UNSIGNED,");
                }
                if (yylval.num_sizespec == C_INT){
                    fprintf(stdout,"INT\n");
                }else if (yylval.num_sizespec == C_LONGLONG){
                    fprintf(stdout,"LONGLONG\n");
                }else{
                    fprintf(stdout,"LONG\n");
                }
            }else{
                fprintf(stdout,"REAL\t%Lg\t", yylval.doub_number);
                if(yylval.num_sizespec == C_DOUBLE){
                    fprintf(stdout,"DOUBLE\n");
                }else if (yylval.num_sizespec == C_LONGDOUBLE){
                    fprintf(stdout, "LONGDOUBLE\n");
                }else{
                    fprintf(stdout, "FLOAT\n");
                }
            }
        }else if (t >= INDSEL && t <= _IMAGINARY){//261 - 321
            fprintf(stdout,"%s\t%d\t%s\t\n",fname, line_num, tokens_names[t-261]);
        }else if (t == TOKEOF){
            fprintf(stdout, "%s\t%d\tTOKEOF\t\n",fname, line_num);
        }
    }

}*/
