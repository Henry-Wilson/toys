//My custom string functions

#ifndef STRFC_H
#define STRFC_H

/* Crashes if no terminating \0 */
int findLength(char* pStart);

/* Sets all bytes in incrementing order. 1,2,3,...,255,1,2,3,... */
int setBytesAscending(char* pStart, int len);

/* Transforms a numeral character to an integer */
int mychartoi(char c);

/* Raises 10 to the power of exp */
int mypow10(int exp);

/* Transforms a CLEAN string to an integer */
int mystoi(char* pStart);

#endif //STRFC_H
