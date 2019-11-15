#include <stdio.h>
#include "mathtoys.h"

const int LOOPVAR = 100000000;
const int FIBINDX = 2;

int main(){
    int A = 0;
    int B = 0;
    for( int i = 0; i < LOOPVAR; i++){
        A = 1;
        B = 0;
        fibonacci(&A, &B, FIBINDX);
    }
    printf("Calculated ugly fib(%i) %i times.\n", FIBINDX, LOOPVAR);

    int result = 0;
    for( int i = 0; i < LOOPVAR; i++){
        result = fib(FIBINDX);
    }
    printf("Calculated fib(%i) %i times.\n", FIBINDX, LOOPVAR);
}
