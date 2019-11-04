/*
 * This is a little test bed to build my facility with C memory managment.
 * Focus on cstrings, as they are easily visible.
 */

/*
 * printf def'd in stdio.h
 * malloc and free def'd in stdlib.h
 * memset def'd in string.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringfuncs.h"

const int MAX_LEN = 36;

/* My little playground. */
int main(){
    /*
     * Allocate memory,
     * set all to 'a' so we have some content,
     * then add a terminating 0.
     */
    char* test = (char*) malloc(MAX_LEN);
    memset(test, 'a', MAX_LEN);
    *(test+MAX_LEN-1) = 0;

    /* Find length */
    int length = findLength(test);
    printf("Length of string '%s': %d\n", test, length);

    /* Set value with ascending */
    printf("\nSet all chars ascending\nRESULT: ");
    setBytesAscending(test, MAX_LEN);


    /* print our result to stdout */
    for(int i = 0; i < MAX_LEN; i++){
        printf("%d ",test[i]);
    }
    printf("\n");

    /* free our memory slice. */
    free(test);

    /*
     * Now let's try something more complicated:
     * We'll be making an stoi function.
     */
    char* intstr = "023";
    char* badintstr = "o23";
    char* negintstr = "-23";
    int ival = 0;
    int* pival = &ival;

    /* Test a bad string */
    printf("\n%s\n", "TEST STOI ON BAD STR");
    printf("STRING TESTED: '%s'\n", badintstr);
    printf("LENGTH OF: %d\n", findLength(badintstr));
    if(mystoi(badintstr, pival)){
        printf("FAIL\n");
    }
    printf("STOI TEST: %d\n", ival);


    /* Test a tricky string */
    printf("\n%s\n", "TEST STOI ON TRICKY STR");
    printf("STRING TESTED: '%s'\n", intstr);
    printf("LENGTH OF: %d\n", findLength(intstr));
    if(mystoi(intstr, pival)){
        printf("FAIL\n");
    };
    printf("STOI TEST: %d\n", ival);


    /* Test a negative string */
    printf("\n%s\n", "TEST STOI ON NEGATIVE STR");
    printf("STRING TESTED: '%s'\n", negintstr);
    printf("LENGTH OF: %d\n", findLength(negintstr));
    if(mystoi_negative_en(negintstr, pival)){
        printf("FAIL\n");
    }
    printf("STOI TEST: %d\n", ival);

    /* Test addition */
    char* strA = "123";
    char* strB = "246";
    int valA = 0;
    int* ptrA = &valA;
    int valB = 0;
    int* ptrB = &valB;

    mystoi(strA, ptrA);
    mystoi(strB, ptrB);
    printf("\nSUM OF '%s' and '%s' is: %d\n", strA, strB, valA+valB);
}
