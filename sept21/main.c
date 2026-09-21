// Split every file into a header and a c file.

#include <stdio.h> // standard input library
#include "tools.h" // include other header file

int main(){ // entry point for c

    // use that function we're including
    int z = addTwoNums(5, 10);
    //int z;  <- this would cause a crash, can't
    // define what is already defined.
    printf("Number is %d\n", z);
    int y[2];
    y[0] = 10;
    y[1] = 2;
    int x[5] = {4,8,1,9,2}; // initize and fill an array
    iterateArray(x, 5);

    return 0;
}