// Sept 30: Pointers and getting user input from command line, and random numbers.

#include <stdio.h>

// atoi
// rand(), srand()
#include <stdlib.h>

// time()
#include <time.h>



// grab input from command line

// argc: how many arguments we sent to the program
// argv: array of strings (array of an array of characters)
int main(int argc, char **argv){
    printf("Hello World\n");

    printf("You have %d arguments\n", argc);

    printf("The first argument (name of the program) is... %s\n", argv[0]);

    // check if valid number of arguments (2)
    if (argc != 3){
        printf("You need two arguments\n");
        return 1;
    }

    // grab the first and second argument (not including the program name)

    // atoi (argument to integer).
    // problems with this function:
    //      if this fails, it just gives back a 0.
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]); // grab the second number


    // Generate a random number.
    // set the seed based on time
    srand(time(NULL));

    int rNumber = rand() % 100; // set the limit of the random to 0-99 (inclusive)
    printf("The random number is... %d\n", rNumber);

    rNumber = 50 + rand() % 50 ; // I want between 50 and 99


    // Pointers

    // malloc = memory allocation

    // reserve an "int" of memory, and have the ptr hold the memory address of this space
    int *ptr = malloc(sizeof(int)); // not automatically freed.

    int x = 4; // automatically freed when out of scope, it's staticly declared.

    *ptr = 30;  // follow the address and assign 30 to it
    free(ptr); // frees the memory

    //*ptr = 2; // unsafe, a potential seg fault.

    // reserving an array.
    // reserve 'x' size array.
    int *numArray = malloc(sizeof(int)*x);
    numArray[0] = 9; // *numArray = 9;  <- just as accurate of a statement
    numArray[1] = 2;
    numArray[2] = 3;
    numArray[3] = 7;

    ptr = numArray; // set ptr to look at the same memory as numArray.
    ptr++; // this is okay, ptr is not what reserved memory.
    free(numArray);
    numArray = NULL;
    ptr = NULL;

    // make a 2d array of numbers. 10 x 8 of numbers
    int **gridOfNumbers;
    gridOfNumbers = malloc(sizeof(int*) * 10); // an array of int pointers

    for(int i = 0; i < 10; i++){ // reserve space for each memory address of the gridOfNumbers
        gridOfNumbers[i] = malloc(sizeof(int) * 8); // each "row" contains space for 8 integers.
    }

    gridOfNumbers[2][4] = 9; // accurate

    // every "malloc" you have, you will need to "free". This only frees the top layer.
    //free(gridOfNumbers);

    // first, free all the inner mallocs.
    for(int i = 0; i < 10; i++){
        free(gridOfNumbers[i]); // frees that one row.
    }
    // now that all rows have been freed, free the outer layer
    free(gridOfNumbers);

    return 0;
}