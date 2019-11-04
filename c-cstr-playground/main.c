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
  *(test+MAX_LEN) = 0;

  /* Set value with ascending */
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

    /* Test a bad string */
    printf("\n%s\n", "TEST STOI ON BAD STR");
    printf("STOI TEST: %d\n", mystoi(badintstr));
    printf("STRING TESTED: %s\n", badintstr);
    printf("LENGTH OF: %d\n", findLength(badintstr));

    /* Test a tricky string */
    printf("\n%s\n", "TEST STOI ON BAD STR");
    printf("STOI TEST: %d\n", mystoi(intstr));
    printf("STRING TESTED: %s\n", intstr);
    printf("LENGTH OF: %d\n", findLength(intstr));

    /* Test addition */
    char* strA = "123";
    char* strB = "246";
    printf("\nAddition of strings \"%s\" and \"%s\": %d\n", strA, strB, ( mystoi(strA) + mystoi(strB) ));
}
