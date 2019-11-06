/*
 * Some mathematical toys.
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
