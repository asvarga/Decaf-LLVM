# Decaf

A compiler for Brown's [CS126](http://cs.brown.edu/courses/cs126/) by [Alex Varga](https://github.com/asvarga) and [Denizalp Goktas](https://github.com/denizalp).

## Contents of this README

- [Building the Compiler](#building-the-compiler)
- [Running a Program](#running-a-program)
- [Examples](#examples)
- [About](#about)

## Building the Compiler

```
$ cd [PathToDecaf]/src
$ make
```

## Running a Program

Once the compiler is `make`'d, the `decaf` python script will compile and run your program.

It takes the optional flags `-c`, `-l`, `-r` for restricting to compilation/linking/running respectively.

```
$ cd [PathToDecaf]
$ ./decaf [PathToProgram]
```

Alternatively, you can add `[PathToDecaf]` to your $PATH or add a symlink to the `decaf` python script like:

```
$ cd [PathToDecaf]
$ ln -s decaf /usr/local/bin/decaf
```

Then `.decaf` files with hashbangs can be run like:

```
$ cd [PathToDecaf]/src/test2
$ ./test0.decaf
```

## Examples

Given Examples:

```
$ ./test/fib.decaf
How many fibs? : 10
fib(1) = 1
fib(2) = 1
fib(3) = 2
fib(4) = 3
fib(5) = 5
fib(6) = 8
fib(7) = 13
fib(8) = 21
fib(9) = 34
fib(10) = 55

$ ./test/adder.decaf
Enter two integers: 
3
4
3 + 4 = 7

$ ./test/hello.decaf
Hello World!

$ ./test/short.decaf
144
```

More Examples:

```
$ ./test2/test0.decaf
x = 17
17 is odd

$ ./test2/test1.decaf
Enter ints, 0 to exit.
4
:)
7
:)
0
:(

$ ./test2/test2.decaf
Start the countdown at: 10
10
9
8
7
6
5
4
3
2
1
Happy New Year!

$ ./test2/test3.decaf
My name is Alex
Hello A-A-A-Alex

$ ./test2/test4.decaf
(1, 10)
(2, 10)
(3, 10)

```

## About

This compiler uses **flex** and **bison** for parsing, and **LLVM** for code generation. See the `Makefile` for details.

The AST and operations on it make heavy use of the visitor pattern. I've done my best to avoid uses of C++'s `dynamic_cast` and all `accept`/`visit` methods have `void` return types. I wouldn't recommend this approach, because it requires delegating all desired pattern matching to the parser, and storing information about variants in AST nodes in somewhat hacky ways. This might be extra performant but is a painful process.

Code generation targets LLVM's IR. A first pass Visitor (`Pass1V`) pins a hodgepodge of various information onto AST nodes, like class and method symbol tables, depth/index values, pointers to parents, etc. These are used by the main visitor (`CodeGenV`) which uses LLVM's `IRBuilder`.

The generated code uses lots of memory loads/stores instead of register operations. This is fine because LLVM provides `createPromoteMemoryToRegisterPass` which is self explanatory, and allows us to keep out code-generating code simpler.

Finally, the generated object files is linked against `decaffuntime.c` which calls the code's `_$DecafMain` method, which itself calls whichever `main` method is found in the decaf file. The generated code is made aware of the runtime's methods through explicit LLVM `declare` statements, rather than using `decaf_runtime.h`. See the `decaf` python script for details.


