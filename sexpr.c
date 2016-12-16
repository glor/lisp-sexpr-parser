#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sexpr.h"

sexpr_t* make_nil() {
	sexpr_t* sexpr = malloc(sizeof(sexpr_t));
	sexpr->type = SEXPR_TYPE_NIL;
	return sexpr;
}

sexpr_t* make_atom(char* str) {
	sexpr_t* sexpr = malloc(sizeof(sexpr_t));
	sexpr->type = SEXPR_TYPE_ATOM;
	sexpr->str = strdup(str);
	return sexpr;
}

sexpr_t* make_sexpr(sexpr_t* a, sexpr_t* b) {
	sexpr_t* sexpr = malloc(sizeof(sexpr_t));
	sexpr->type = SEXPR_TYPE_SEXPR;
	sexpr->children[0] = a;
	sexpr->children[1] = b;
	return sexpr;
}

void print_sexpr(sexpr_t* sexpr) {
	switch(sexpr->type) {
		case SEXPR_TYPE_ATOM:
			printf("%s", sexpr->str);
			break;
		case SEXPR_TYPE_SEXPR:
			printf("(");
			print_sexpr(sexpr->children[0]);
			printf(" . ");
			print_sexpr(sexpr->children[1]);
			printf(")");
			break;
		case SEXPR_TYPE_UNEVAL_SEXPR:
			printf("'(");
			print_sexpr(sexpr->children[0]);
			printf(" . ");
			print_sexpr(sexpr->children[1]);
			printf(")");
			break;
		case SEXPR_TYPE_NIL:
			printf("NIL");
			break;
		default:
			fprintf(stderr, "error: unknown type in sexpr %d\n", sexpr->type);
	}
}

