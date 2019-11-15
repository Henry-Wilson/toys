#include <stdio.h>
#include "mathtoys.h"

const int LOOPVAR = 1000000;
const int FIBINDX = 13;

int main(){

    int result = 0;
    for( int i = 0; i < LOOPVAR; i++){
        result = fib(FIBINDX);
    }
    printf("Calculated fib(%i) %i times.\n", FIBINDX, LOOPVAR);

    for( int i = 0; i < LOOPVAR; i++){
        int A = 1;
        int B = 0;
        fibonacci(&A, &B, FIBINDX);
    }
    printf("Calculated ugly fib(%i) %i times.\n", FIBINDX, LOOPVAR);
}
