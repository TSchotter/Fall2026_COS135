#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    // reserve space for 100 integers in an array
    int *numArray;

    // mem space of a memory address is 8 bytes
    printf("Mem space of variable: %ld\n", sizeof(numArray));

    // allocate memory for 100 numbers
    numArray = malloc(sizeof(int)*100);

    // reserve space for 100 numbers AND zero them out.
    int *filledNumArray = calloc(100, sizeof(int));

    // uh oh, not enough space for my numbers in the array, what do I do?

    // time to reallocate the space
    // first parameter: original array location
    // second parameter: new size
    numArray = realloc(numArray, sizeof(int) * 200);

    // danger, this could fail.
    // realloc could return NULL if it fails to find a spot for the new size array.

    // instead do this:
    int *tempArray = realloc(numArray, sizeof(int) * 200);
    if (tempArray == NULL){ // could not reserve space
        free(numArray); // free used memory
        printf("Could not reallocate memory"); // tell them what went wrong
        return 1; //end program
    }
    numArray = tempArray; // can safely have old pointer point to new location


    // comparing strings

    // reserve the perfect number of character spaces and place string in it
    char string1[] = "Hello World";
    char string2[] = "Hello world";

    // string compare.
    // when == 0, strings are equal
    // when negative == string 2 is lower on the ascii table
    // when positive == string 1 is lower on the ascii table
    printf("String compare result %d\n", strcmp(string1, string2));
    if (strcmp(string1, string2) == 0){
        printf("These two strings are the same!\n");
    } else {
        printf("These two strings are different");
    }

    return 0;

    // good programming practice:
    // double the size of the array every time you need more space.
}