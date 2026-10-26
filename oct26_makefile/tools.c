#include <stdio.h>


// countFileLines
// takes a file pointer
// returns number of lines in the file

int countFileLines(FILE *fp){
    char buffer[100]; // don't care to actually remember the lines
    int counter = 0; // needs to start at 0
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        counter++;
        printf("test\n");
    }
    rewind(fp);
    return counter;
}