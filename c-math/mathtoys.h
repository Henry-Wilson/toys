#ifndef mathtoys_h_INCLUDED
#define mathtoys_h_INCLUDED
#include <stdint.h>

#define MNTYPE uint_fast32_t

/* Recursive pointer-based fibonacci implementation */
void fibonacci(int* pA, int* pB, int term);

/* elegant fibonacci function */
int fib(int n);

/* Better function. Does not rely on modulo */
MNTYPE best_choose(int m, int n);

/* 'bad' m_choose_n algorithm for comparison */
double bad_m_choose_n(double m, double n);

#endif // mathtoys_h_INCLUDED

