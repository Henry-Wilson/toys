#ifndef mathtoys_h_INCLUDED
#define mathtoys_h_INCLUDED

/* Recursive pointer-based fibonacci implementation */
void fibonacci(int* pA, int* pB, int term);

/* iterative and efficient m_choose_n algorithm */
unsigned long long int m_choose_n(int m, int n);

/* 'bad' m_choose_n algorithm for comparison */
double bad_m_choose_n(double m, double n);

#endif // mathtoys_h_INCLUDED

