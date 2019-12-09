
parser: parser.ypp lexer.l
	flex lexer.l
	bison -d parser.ypp

compiler: parser
	g++ -std=c++11 -Wfatal-errors -o parser parser.tab.cpp lex.yy.c -ll -g -ldl `llvm-config --cppflags --libs all --libfiles core --ldflags --system-libs`

# TESTS #
adder: compiler
	./parser test/adder.decaf
	clang decafruntime.c main.o -o main
	./main
empty: compiler
	./parser test2/emptyClasses.decaf
	clang decafruntime.c main.o -o main
	./main
hello: compiler
	./parser test2/helloWorld.decaf
	clang decafruntime.c main.o -o main
	./main
test0: compiler
	./parser test2/test0.decaf
	clang decafruntime.c main.o -o main
	./main

.PHONY: clean

clean:
	rm *.o parser.tab.cpp parser.tab.hpp lex.yy.c
