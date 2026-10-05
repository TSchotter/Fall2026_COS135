#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// There are problems here that cause seg faults!

// practice narrowing down and tracking the problem with gdb



void print_greeting(char *name) {
    char greeting[20];
    // bug here, trying to copy a string to memory that hasn't been reserved
    strcpy(greeting, name);
    printf("Hello, %s!\n", greeting);
}

void process_scores(int *scores, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    printf("Total score: %d\n", total);
}

int main() {
    int num = 50;
    char *user_name = NULL;
    int *numbers = NULL;

    printf("Starting program...\n");

    print_greeting(user_name);

    // bug here, "numbers" hasn't been malloc'ed so there isn't a 
    // zero index to assign a number.
    numbers[0] = 8;
    process_scores(numbers, 1);

    return 0;
}