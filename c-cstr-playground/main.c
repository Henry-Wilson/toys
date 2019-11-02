/*
  This is a little test bed to build my facility with C memory managment.
  Focus on cstrings, as they are easily visible.
*/

/*
  printf def'd in stdio.h
  malloc and free def'd in stdlib.h
  memset def'd in string.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SUCCESS = 0;
const int FAIL = -1;
const int MAX_LEN = 36; /* Length of our 'string' */
const int FULL_BYTE = 256; /* Length of a byte. This should NEVER be edited. */

int findLength(char* pStart);
int setBytesAscending(char* pStart, int len);

/*
  My little playground.
*/
int main(){

  /*
    Allocate memory,
    set all to 'a' so we have some content,
    then add a terminating 0.
  */
  char* test = (char*) malloc(MAX_LEN);
  memset(test, 'a', MAX_LEN);
  *(test+MAX_LEN) = 0;

/*
  //Find length
  int length = 0;
  length = findLength(test);
*/

  /* Set value with ascending */
  setBytesAscending(test, MAX_LEN);

  /* print our result to stdout */
  for(int i = 0; i < MAX_LEN; i++){
    printf("%d ",test[i]);
  }
  printf("\n");

  /* free our memory slice. */
  free(test);

}

/*
  The idea: find the length of a string.
  One problem: will crash if there's no terminating 0.
  This is because it will then go look at memory that is not allowed.
*/
int findLength(char* pStart){

  /* Fail on null */
  if (pStart == NULL){
    return FAIL;
  }

  /* Iterate until we find a zero. */
  char* pEnd = pStart;
  while (*pEnd != 0){
    pEnd++;
  }

  /* However far we got, that's the length of the string. */
  int len = pEnd - pStart;
  return len;

}

/*
  The idea: set each byte one more than the last.
  Set none of them to zero.
  This will give us a bunch of data to play with.
  use full 8 bits. 255-1 values.
*/
int setBytesAscending(char* pStart, int len){

  /* Fail on null */
  if (pStart == NULL){
    return FAIL;
  }

  /*
    While iterating up to length,
    use our iterator also as a value to set.
    Modulo 255 to make sure we don't overflow.
  */
  int iterator = 0;
  while (iterator < len){
    *(pStart + iterator) = (iterator % (FULL_BYTE-1))+1;
    iterator++;
  }

  /* We've done our work. Return success. */
  return SUCCESS;
}
