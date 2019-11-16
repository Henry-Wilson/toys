#include <stdint.h>
#include "mathtoys.h"

/*
 * Some mathematical toys.
 */

/*
 * Somewhat ugly recursive fib func based on ptrs.
 * Slower for low order calculations because of
 * many operators, faster for high order calculations
 * because of only one recursive call.
 */
void fibonacci(int* pA, int* pB, int term){
    //We ought to terminate on Zero.
    if(!term){
        return;
    }
    int temp = *pA;
    *pA = *pA + *pB;
    *pB = temp;
    fibonacci(pA, pB, term - 1);
    return;
}

/*
 * While this is more elengant, it is much slower.
 * This is slower for high order calculations because
 * it makes two recursive calls, faster for low order
 * because it uses two operators only.
 */
int fib( int n ){
    if ( n <= 2 ) {
        return 1;
    }

    return (fib(n-1) + fib(n-2));
}

/*
 * Better M choose N function.
 * We don't have to check divisibility.
 * M to M-N and N to 0 are the same length range.
 * We simply alternate.
 */
MNTYPE best_choose(int m, int n){
    MNTYPE result = m;
    int miter     = m - 1;
    int niter     = 2;
    int mid       = (m - n);

    /*
     * These repeated divisions are three
     * fourths of the cost of this function.
     * In float world, we just do one division
     * because we don't overflow for a long
     * time.
     */
    while ( miter > mid ){
        result = result * miter;
        result = result / niter;
        miter  = miter - 1;
        niter  = niter + 1;
    }

    return result;
}

/*
 * This is a brute force algo written with doubles.
 * While there are small rounding errors at the
 * level of 60 choose 30, this is much faster.
 */
double bad_m_choose_n( double m, double n ){
    double fm = 1;
    double fmn = 1;
    double fn = 1;

    for(int i = 2; i <= m; i++){
        fm = fm * i;
    }
    for(int i = 2; i <= n; i++){
        fn = fn * i;
    }
    for(int i = 2; i <= (m-n); i++){
        fmn = fmn * i;
    }

    double result = fm / (fmn * fn);
    return result; 
}
