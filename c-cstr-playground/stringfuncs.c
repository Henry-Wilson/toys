#include "stringfuncs.h"
#include "constants.h"

/*
 * The idea: find the length of a string.
 * One problem: will crash if there's no terminating 0.
 * This is because it will then go look at memory that is not allowed.
 */
int findLength(char* pStart){

  /* Fail on null */
  if (pStart == 0){
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
 * The idea: set each byte one more than the last.
 * Set none of them to zero.
 * This will give us a bunch of data to play with.
 * use full 8 bits. 255-1 values.
 */
int setBytesAscending(char* pStart, int len){

  /* Fail on null */
  if (pStart == 0){
    return FAIL;
  }

  /*
   * While iterating up to length,
   * use our iterator also as a value to set.
   * Modulo 255 to make sure we don't overflow.
   */
  int iterator = 0;
  while (iterator < len){
    *(pStart + iterator) = (iterator % (FULL_BYTE-1))+1;
    iterator++;
  }

  /* We've done our work. Return success. */
  return SUCCESS;
}

/* Return the integer represented by a NUMERAL CHARACTER */
int mychartoi(char c){
    switch(c){
        case '0' : return    0;
        case '1' : return    1;
        case '2' : return    2;
        case '3' : return    3;
        case '4' : return    4;
        case '5' : return    5;
        case '6' : return    6;
        case '7' : return    7;
        case '8' : return    8;
        case '9' : return    9;
        default  : return FAIL;
    }
}

/*
 * Return 10 to the power of exp
 */
int mypow10(int exp){
    int result = 1;
    int i = 0;
    for(i; i < exp; i++){
        result *= 10;
    }
    return result;
}

/*
 * Return the integer value represented
 * by a CLEANLY FORMATTED string.
 * Note: cleanly formatted implies nonnegative.
 */
int mystoi(char* pStart, int* pint){
    int length = findLength(pStart);
    /*
     * Fail if we couldn't find a length
     * This handles the null case for us.
     */
    if(length == FAIL){
        return FAIL;
    }

    /*
     * Now that we have a length, we simply have to
     * add up all the digits multiplied by the appropriate
     * power of ten.
     */
    int result = 0;
    int coeff = mypow10(length-1); /* -1 because we digit 3 is 100 not 1000 */

    /*
     * For each char:
     * transform to int
     * exponentiate appropriately
     * add to result var
     */
    for(int i = 0; i < length; i++){
        int charval = mychartoi( *(pStart + i) );
        /* 
         * If we ever have a bad character, fail altogether.
         * Don't treat it as -1*10^n
         */
        if (charval == FAIL){
            return FAIL;
        }
	result += charval * coeff; 
	coeff /= 10;
    }

    *pint = result;
    return SUCCESS;
}

/*
 * Like the former function
 * but will correctly parse negative numbers as well.
 * What should FAIL be???
 * Ah, we need to re-do these. Pass int ref.
 */
int mystoi_negative_en(char* pStart, int* value){
    if ( *pStart == '-' ){
        int iret = mystoi(pStart+1, value);
        *value *= -1;
        return iret;
    }
    return mystoi(pStart, value);
}
