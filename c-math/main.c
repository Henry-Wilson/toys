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

    int m = 60;
    int n = 30;
    unsigned long long int result = m_choose_n(m,n); // Expect 20 for 6,3
    printf("%d choose %d : %llu\n", m, n, result);

    double bad_m = 60.0;
    double bad_n = 30.0;
    double bad_result = bad_m_choose_n(bad_m, bad_n);
    printf("BAD %lf choose %lf: %lf\n", bad_m, bad_n, bad_result);
}
