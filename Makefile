#Makefile
all: main

parse.tab.c parse.tab.h: parse.y
			 bison -d -v parse.y

lex.yy.c: lexer.l parse.tab.h
		flex lexer.l

main:	lex.yy.c parse.tab.c parse.tab.h ast.c sym_table.c flags.h quads.c quads.h
	gcc -g -o parse parse.tab.c parse.tab.h lex.yy.c ast.c sym_table.c quads.c flags.h

clean:
	rm -f *.o *~ main lex.yy.c parse.tab.c parse.tab.h core		
