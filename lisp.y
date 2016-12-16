%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sexpr.h"

#define YYSTYPE void*
int yydebug=0;

void yyerror(const char *str) {
	fprintf(stderr,"error: %s\n",str);
}

int yywrap() {
	return 1;
}

int main(void) {
	yyparse();
}

%}

%token BR_OPEN BR_CLOSE ID STRING

%%
start: sexpr						{print_sexpr($1);}
	;
sexprlist:							{$$ = make_nil();}
	| sexpr sexprlist				{$$ = make_sexpr($1, $2);}
	;
sexpr: atom							{$$ = $1;}
	| BR_OPEN sexprlist BR_CLOSE	{$$ = $2;}
	;
atom: ID							{$$ = make_atom($1);}
	| STRING						{$$ = make_atom($1);}
	;




