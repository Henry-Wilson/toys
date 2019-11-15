#include <stdint.h>
#include "mathtoys.h"

/*
 * Some mathematical toys.
 */

/*
 * Somewhat ugly recursive fib func based on ptrs.
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
 */
int fib( int n ){
    if ( n <= 2 ) {
        return 1;
    }

    return (fib(n-1) + fib(n-2));
}

/*
 * very efficient m_choose_n algorithm running in unsigned long space.
 * Very efficient may be an exaggeration. Modulo function is quite slow.
 */
MNTYPE m_choose_n(int m, int n){
    //Start with a result equal to identity.
    MNTYPE result = 1;

    // M Iterator
    MNTYPE miter = m;
    // N Iterator
    MNTYPE niter = n;

    //Multiply by each miter. Divide when possible.
    while ( miter > (m-n) ) {
        //Do we want to start smallest first or largest first?
        result = result * miter; //Largest first for now
        //Divide by niter as many times as possible.
        while ( niter > 1 ) {
            //If there's NOT a remainder
            //Modulus = A - B * (A / B)
            MNTYPE quotient = result / niter;
            //if ( result % niter == 0) {
            if ( result - niter * quotient == 0) {
                result = quotient;
            }
            else{
                break;
            }
            niter--;
        }
        miter--;
    }

    return result;
}
/*
 * This is slow.
 * Let's see how we can make it more efficient.
 *
 * Do we do modulo to check division even when
 * there is no more n to divide by? no.
 *
 * Do we break the modulo function up into its
 * constituent parts and store the intermediates?
 * Yes. This saves some time.
 *
 * Do we use raw, unsigned variables for the sake
 * of speed? Yes. This saves time.
 *
 * Do we use C99 fast types? Yes, check definition
 * of MNTYPE in mathtoys.h
 */

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

/*
 * This is meant to be a hybrid method. It will run
 * in double space, eliminating the need for modulo
 * and speeding things up. It will also do piecewise
 * products and quotients.
 */
double hyb_m_choose_n( double m, double n ){
    double miter = m;
    double niter = n;
    double result = 1;

    //Multiply by each miter. Divide when possible.
    while ( miter > (m-n) || niter > 0) {
        if( miter > (m-n) ){
        result = result * miter;
        miter = miter - 1;
        }
        if( niter > 0 ){
        result = result / niter;
        niter = niter - 1;
        }
    }
    return result;
}
