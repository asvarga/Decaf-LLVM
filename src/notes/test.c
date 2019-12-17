


// clang -S -emit-llvm -O2 test.c

#include <stdio.h>


int mod2(int x) {
    return x%2;
}

int f(int x) {
    return mod2(x);
}

int main() {
    // int x, y, z;
    // printf("x: ");
    // scanf("%d",&x);
    // printf("y: ");
    // scanf("%d",&y);
    // z = x+y;
    // printf("x + y = %d\n",z);
    // return 0;


    int x;
    scanf("%d",&x);
    // return x;

    // return x%2;
    return f(x);
}


