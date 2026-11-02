#include <stdlib.h>
#include <stdio.h>

// Example one of a dangling pointer.
// A pointer that is looking at a memory address that has since been "free"'ed 
// or dereferenced.

void causeProblem(int *n){
    // printing the value stored at memory address
    printf("The number is: %d\n", *n);
    free(n); // free the value and mark it as available memory.
    return;
}

int main(){
    int *number = malloc(sizeof(int));
    *number = 7;
    printf("%d\n", *number + 5);

    causeProblem(number);
    free(number); // can't free what's alredy been freed
}