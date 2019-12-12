# Decaf

A compiler for Brown's [CS126](http://cs.brown.edu/courses/cs126/) by [Alex Varga](https://github.com/asvarga) and [Denizalp Goktas](https://github.com/denizalp).

## Building the Compiler

```
$ cd [PathToDecaf]/src
$ make compiler
```

## Running a Program

Once the compiler is `make`'d, the `decaf` python script will compile and run your program.

It takes the optional flags `-c`, `-l`, `-r` for restricting to compilation/linking/running respectively.

```
$ cd [PathToDecaf]
$ ./decaf [PathToProgram]
```

Alternatively, you can add `[PathToDecaf]` to your $PATH or add a symlink to the `decaf` python script.

Then `.decaf` files with hashbangs can be run like:

```
$ cd [PathToDecaf]/src/test2
$ ./test0.decaf
```
