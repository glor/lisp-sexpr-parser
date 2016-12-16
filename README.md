# lisp syntax s-expression parser
## dependencies
	- yacc (i used yacc 1.9 on BSD (byacc); GNU bison would need small changes)  
	- lex  
	- make  
	- lua for testing  
## how to run
	run `make` and then do `./lisp` and e.g. put in `(+ 1 2 3)` or `(+ 1 2 (* 3 4) 5)`  
## overview
	- lisp.l contains the lexer code  
	- lisp.y contains the parser code  
	- sexpr.c contains sexpression implementation  
