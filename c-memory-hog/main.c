/*
 * This is a VERY simple memory hog written in plain C. It will very quickly
 * cause big problems with most machines. Probably a bad idea to run this.
 */

/*
 * stdlib.h is needed for malloc.
 * Why is that? malloc seems fundamental.
 */
#include <stdlib.h>

/*
 * This is the number of bytes (chars) per allocation to use.
 * This has little effect on the speed of the crash: the system can only
 * allocate memory so fast.
 */
const int CHUNK_SIZE = 1;

int main(){

    /* Initialize pointer to null. We will use this many times. */
    char* test = 0;

    /* We will, FOREVER, allocate new memory to the pointer test. */
    while(1){
        test = (char*) malloc(CHUNK_SIZE);
    }

}
