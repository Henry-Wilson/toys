#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "mathtoys.h"

const int M = 60;
const int N = 30;
const int FACT = 1000000;

int main(){

    long start = clock();

    for(int i = 0; i < FACT; i++){
        MNTYPE result = best_choose(M,N);
    }

    long end = clock();
    printf("Clock cycles: %li\n", (end - start));

    return 0;
}
