// In-class Exercise Nov 9th
/*
Create a program that asks the user for numbers until
they type in 's' for "STOP". Once told to stop 
the program adds these numbers together and outputs the sum of the numbers.

The catch, do it in the worst way possible with as many memory leaks as you can. 

The memory leaks need to be related to the task and the program should not crash. 

Hide your memory leaks so that they are hard to spot.

When getting input from the user, 
- use fgets
- check if first character was an 's'
- use atoi to convert the string to a number if it wasn't an 's'
*/
// valgrind, need to install so...
// sudo apt install valgrind
// valgrind --leak-check=full [name of executable]
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *buffer = malloc(sizeof(char)*100);
    int *sum = malloc(sizeof(int));

    // another example of a mem leak, lose sight of start of array.
    int *y = malloc(sizeof(int) *100);
    y++;

    while(1){
        buffer = malloc(sizeof(char)*100);
        printf("Enter a number, 's' to stop\n:");
        fgets(buffer,100, stdin);
        if (buffer[0] == 's'){
            printf("The sum is: %d\n", *sum);
            return 0;
        } else {
            int *x = malloc(sizeof(int));
            *x = atoi(buffer);
            *sum += *x;
        }
    }
}