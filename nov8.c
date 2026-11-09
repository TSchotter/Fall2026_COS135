#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int *numbers = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    
    numbers = NULL;

    return 0;
}