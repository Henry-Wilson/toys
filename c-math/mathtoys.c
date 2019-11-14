/*
 * Some mathematical toys.
 */

//Simple recursive implementation of a fibonacci sequence.
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

//very efficient m_choose_n algorithm running in unsigned long space.
//Very efficient may be an exaggeration. Modulo function is quite slow.
unsigned long int m_choose_n(int m, int n){
    //Start with a result equal to identity.
    unsigned long int result = 1;

    // M Iterator
    int miter = m;
    // N Iterator
    int niter = n;

    //Multiply by each miter. Divide when possible.
    while ( miter > (m-n) ) {
        //Do we want to start smallest first or largest first?
        result = result * miter; //Largest first for now
        //Divide by niter as many times as possible.
        while ( niter > 1 ) {
            //If there's NOT a remainder
            //Modulus = A - B * (A / B)
            unsigned long int quotient = result / niter;
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

//This is a brute force algo written with doubles.
//While there are small rounding errors at the
//level of 60 choose 30, this is much faster.
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
 * in double space, eliminatingthe need for modulo
 * and speeding things up. It will also do piecewise
 * products and quotients.
 */
double hyb_m_choose_n( double m, double n ){
    int miter = m;
    int niter = n;
    int result = 1;

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
