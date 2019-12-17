
compiler: parser
	g++ -std=c++11 -Wfatal-errors -o ../build/parser parser.tab.cpp lex.yy.c -ll -g -ldl `llvm-config --cppflags --libs all --libfiles core --ldflags --system-libs`

parser: parser.ypp lexer.l
	flex lexer.l
	bison -d parser.ypp

# TESTS #
adder: compiler
	../decaf test/adder
empty: compiler
	../decaf test2/emptyClasses
hello: compiler
	../decaf test2/helloWorld
test0: compiler
	../decaf test2/test0
test1: compiler
	../decaf test2/test1
test2: compiler
	../decaf test2/test2
test3: compiler
	../decaf test2/test3
test4: compiler
	../decaf test2/test4

.PHONY: clean

clean:
	rm *.o parser.tab.cpp parser.tab.hpp lex.yy.c
