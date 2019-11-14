/* For test of math toys */

#include <stdio.h>
#include <stdint.h>
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
    MNTYPE result = m_choose_n(m,n); // Expect 20 for 6,3
    printf("%d choose %d : %llu\n", m, n, result);

    double bad_m = 60.0;
    double bad_n = 30.0;
    double bad_result = bad_m_choose_n(bad_m, bad_n);
    printf("BAD %lf choose %lf: %lf\n", bad_m, bad_n, bad_result);

    double hyb_m = 60.0;
    double hyb_n = 30.0;
    double hyb_result = hyb_m_choose_n(hyb_m, hyb_n);
    printf("HYB %lf choose %lf: %lf\n", hyb_m, hyb_n, hyb_result);
    printf("HYB %lf choose %lf: %X\n", hyb_m, hyb_n, hyb_result);
}
