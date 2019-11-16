#include <stdio.h>
#include <time.h>
#include "mathtoys.h"

const double M = 60.0;
const double N = 30.0;
const int FACT = 1000;

int main(){
    long start = clock();
    for(int i = 0; i < FACT; i++){
        for(int j = 0; j < FACT; j++){
            double result = bad_m_choose_n(M,N);
        }
    }
    long end = clock();
    printf("Clock cycles: %li\n", (end - start));
    return 0;
}
