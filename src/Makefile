
parser: parser.ypp lexer.l
	flex lexer.l
	bison -d parser.ypp

compiler: parser 
	g++ -std=c++11 -o parser parser.tab.cpp lex.yy.c -ll -g -ldl `llvm-config --cppflags --libs --libfiles core --ldflags --system-libs` 

# TESTS #
adder: compiler
	./parser test/adder.decaf
empty: compiler
	./parser test2/emptyClasses.decaf
test0: compiler
	./parser test2/test0.decaf
test1: compiler
	./parser test/adder.decaf

.PHONY: clean

clean:
	rm *.o parser.tab.cpp parser.tab.hpp lex.yy.c
