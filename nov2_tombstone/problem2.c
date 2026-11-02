#include <stdlib.h>
#include <stdio.h>

// Example two of a dangling pointer.
// A pointer that is looking at a memory address that has since been "free"'ed 
// or dereferenced.

int* causeProblem(){
    int n = 5;
    int *nPoint = &n;
    printf("The number is (inside of the function): %d\n", *nPoint);
    return nPoint;
}

int main(){
    int *x = causeProblem();
    int y = 10;
    printf("The number is: %d\n", *x);
    free(x); // doesn't work, memory on the stack
}