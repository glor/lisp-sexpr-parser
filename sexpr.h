#define SEXPR_TYPE_ATOM 1
#define SEXPR_TYPE_SEXPR 2
#define SEXPR_TYPE_NIL 3
#define SEXPR_TYPE_UNEVAL_SEXPR 4

typedef struct sexpr_s {
	short type;
	union {
		struct sexpr_s* children[2];
		char* str;
	};
} sexpr_t;

sexpr_t* make_nil();
sexpr_t* make_atom(char* str);
sexpr_t* make_sexpr(sexpr_t* a, sexpr_t* b);
void print_sexpr(sexpr_t* sexpr);
