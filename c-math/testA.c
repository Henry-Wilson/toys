#include <stdio.h>
#include <stdint.h>
#include "mathtoys.h"

const int M = 60;
const int N = 30;
const int FACT = 1000;

int main(){
    for(int i = 0; i < FACT; i++){
        for(int j = 0; j < FACT; j++){
            MNTYPE result = m_choose_n(M,N);
        }
    }
    return 0;
}
