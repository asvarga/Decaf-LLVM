
parser: parser.ypp lexer.l
	flex lexer.l
	bison -d parser.ypp

compiler: parser
	g++ -std=c++11 -Wfatal-errors -o ../build/parser parser.tab.cpp lex.yy.c -ll -g -ldl `llvm-config --cppflags --libs all --libfiles core --ldflags --system-libs`

# TESTS #
adder: compiler
	../build/parser test/adder.decaf
	clang decafruntime.c ../build/main.o -o ../build/main
	../build/main
empty: compiler
	../build/parser test2/emptyClasses.decaf
	clang decafruntime.c ../build/main.o -o ../build/main
	../build/main
hello: compiler
	../build/parser test2/helloWorld.decaf
	clang decafruntime.c ../build/main.o -o ../build/main
	../build/main
test0: compiler
	../build/parser test2/test0.decaf
	clang decafruntime.c ../build/main.o -o ../build/main
	../build/main	# enter an int...

.PHONY: clean

clean:
	rm *.o parser.tab.cpp parser.tab.hpp lex.yy.c
