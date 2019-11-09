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

//very efficient m_choose_n algorithm running in unsigned long long space.
unsigned long long int m_choose_n(int m, int n){
    //Start with a result equal to identity.
    unsigned long long int result = 1;

    /*
     * range to multiply by: [m to (m-n))
     * range to divide by: [n to 1)
     * 
     * We ought to check before division if
     * we are properly divisible. Does modular
     * arithmetic work in C natively? One must
     * imagine so, given that it follows
     * naturally from the addition functions of
     * all common ALUs.
     */

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
            unsigned long long int quotient = result / niter;
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

//Just for comparison. This is the bad function.
//We'll try a speed comparison some time.
//Even without a speed comparison, it is seen that
//rounding errors are present here.
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
