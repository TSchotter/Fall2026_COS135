// run the following apt install to get access to gcc
//
// sudo apt install build-essential

// single line comments
/*
Block comment
*/

// .h typically means a header file, 
#include <stdio.h> // Almost always included (standard input/output)

// Entry point for the program 
int main(){
    // common print statement
    // MUST use double quotes for strings.
    printf("Hello World\n"); // new line is not included by default, you have to add it

    int x; // declare x, and reserve space for it.

    float y = 1.5; // declare and assign.
    x = 5; // assign to x, do not redeclare

    // if statement, everything in the {} will execute if condition is true
    if (x == 5){
        int z = 12; // scope of 'z' is this if statement.
    }
    int z = 2; // free to redeclare z because old one is gone.

    // declare and fill a character array
    // ['H', 'e', 'l', 'l', 'o', '\0', garbage, garbage, garbage, ...]
    char buffer[20] = "Hello";

    // loops

    // while loop
    int c = 0;
    while(c < 20){
        c++; // increment value by one. c+= 1 or c = c + 1

        printf("C is %d\n", c); // placeholder. %d is for a digit.
    }

    printf("Character a is %d\n", 'a');

    // for loop
    // combines three aspects. Init, condition; incrementation

    for (int counter = 0; counter < 5; counter++){ // scope of counter is the loop
        printf("counter is %d\n", counter);
    }
    int n = 5;
    for(int i = 0; i < n; i++){

        for(int j = 0; j <= i; j++){
            
        }
    }



    // all statements end with a ;
    return 0;
}