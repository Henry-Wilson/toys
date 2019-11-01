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

const int FAIL = -1;
const int MAX_LEN = 36;

int findLength(char* pStart);

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

  //Find length
  int length = 0;
  length = findLength(test);

  //print our result to stdout
  printf("%s\n", test);
  printf("%s%d\n", "LENTGH OF STRING: ", length);

  //free our memory slice.
  free(test);

}

/*
  The idea: find the length of a string.
  One problem: will crash if there's no terminating 0.
  This is because it will then go look at memory that is not allowed.
*/
int findLength(char* pStart){

  //Fail on null
  if (pStart == NULL){
    return FAIL;
  }

  /*
    Iterate until we find a zero.
  */
  char* pEnd = pStart;
  while (*pEnd != 0){
    pEnd++;
  }

  /*
    However far we got, that's the length of the string.
  */
  int len = pEnd - pStart;
  return len;

}
