CC=cc
all: sexpr.o
	lex lisp.l
	yacc -d -b lisp lisp.y
	$(CC) lex.yy.c lisp.tab.c sexpr.o -o lisp
	
sexpr.o:
	$(CC) -c sexpr.c
clean:
	rm -f lex.yy.c lisp.tab.c lisp.tab.h sexpr.o lisp
