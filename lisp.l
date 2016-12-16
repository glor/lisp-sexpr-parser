%{
#include <stdio.h>
#include "lisp.tab.h"
#define YYSTYPE void*
extern YYSTYPE yylval;
%}
%%
\(						return BR_OPEN;
\)						return BR_CLOSE;
\"[^"]*\"				yylval=strdup(yytext); return STRING; /* string */;
[^ \n\t\(\)]+			yylval=strdup(yytext); return ID; /* identifier */;
\n						/* ignore end of line */;
[ \t]+					/* ignore whitespace */; /*<<EOF>>			return END;*/
%%
