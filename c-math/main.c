/* For test of math toys */

#include <stdio.h>
#include "mathtoys.h"

int main(){
    int A = 1;
    int B = 0;
    int* pA = &A;
    int* pB = &B;
    int term = 13;
    fibonacci(pA, pB, term);
    printf("Fib. Number %d = %d\n", term, B); 
}
