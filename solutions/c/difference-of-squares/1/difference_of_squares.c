#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number){
    unsigned int numToSquare = 0;
    for(unsigned int i = 1; i <= number; i++){
        numToSquare += i;
    }
    return numToSquare * numToSquare;
}

unsigned int sum_of_squares(unsigned int number){
    unsigned int runningTotal = 0;
    for(unsigned int i = 1; i <= number; i++){
        runningTotal += (i*i);
    }
    return runningTotal;
}

unsigned int difference_of_squares(unsigned int number){
    unsigned int i = sum_of_squares(number);
    unsigned int j = square_of_sum(number);
    return j - i;
}