// If statements

#include <stdio.h>

int main(){

    // if statement example.

    int x = 5;

    if (x > 3){
        // inside the if statement executes if condition is true.
    }

    if (x > 0 && x < 10){// the "and"
        printf("inside the and\n");
    }

    if (x < 0  ||  x > 10){ // the "or"
        printf("inside the or\n");
    }

    if(x){ // any positive number is considered "true"

    }

    int *ptr; // declare an int pointer.
    // manually set the ptr to "nothing"
    ptr = NULL;

    int *ptr2 = NULL; // create and set

    if (ptr == NULL){
        // we now know that the ptr isn't looking at anything important
    }

    if (ptr != NULL){ // the *not* equal to condition
        // now we know it *is* looking at something important.
    }

    if (!(x > 0 && x < 10)){// the ! can be used to reverse a condition

    }

    if (x == 2){
        // things happen
    } else { // the "else" will happen if the if condition fails.

    }

    // if else if chain
    if (x == 2){
        int y = 0;
        while(x == 2){
            // y exists here as well
        }
    } else if (x == 3){
        // y is out of scope here
    } else if (x == 4){

    } else {

    }
    // y is out of scope here as well

    return 0;
}