parser: parser.ypp lexer.l ast.h ast.cpp
	flex lexer.l
	bison -d parser.ypp


compiler:
	g++ -std=c++11 -o parser parser.tab.cpp lex.yy.c ast.cpp -ll -g -ldl -lfl `llvm-config --cppflags --libs --libfiles core --ldflags --system-libs`
