#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"


int main(){

    // opening the file to write
    // this returns a memory address
    FILE *fp = fopen("inClass.txt", "w");
    FILE *dummy = fp;

    // check if file was opened properly
    if (fp == NULL){ // memory issue, or you don't have permissions
        printf("Could not open file\n");
        return 1;
    }

    // fputs() can only handle strings
    fputs("Hello World\n", fp);
    fclose(fp); // always close file when you're done

    // open file to append (will crash if file doesn't exist)
    // since we're opening to append, we won't overwrite the old data
    fp = fopen("inClass.txt", "a");

    // fprintf() for outputing to the the file in a way like printf
    fprintf(fp, "My fav number is %d\n", 14811);
    fprintf(fp, "My fav number is %d\n", 14);
    fprintf(fp, "My fav number is %d\n", 11);
    fprintf(fp, "My fav number is %d\n", 4811);
    fprintf(fp, "My fav number is %d\n", 111);
    fprintf(fp, "My fav number is %d\n", 1);
    fprintf(fp, "My fav number is %d\n", 481);
    fclose(fp);

    // you can use fputs for other things
    fputs("Hi There\n", stdout);
    // you can do the same for fprintf
    fprintf(stderr, "THIS IS AN %d ERROR!\n", 404);

    // open the file one more time, to read
    fp = fopen("inClass.txt", "r");

    char buffer[200]; // storage for a single line
    int numLines = 0; // a counter to count the lines

    // goal, find out how many lines in the file
    // buffer: where are placing the line
    // sizeof(buffer): how much space can we afford to take
    // fp: where are pulling the data from
    // != NULL: continue grabbing lines, until the end of file
    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        // each loop iteration is one line stored in buffer.
        numLines++; // increment by one
    }
    // fp is at the end of the file, lets bring it back to the start

    // fseek() moves the file pointer
    // fp: the file pointer
    // 0: how far relative to the third parameter (in bytes)
    // SEEK_SET: starting point
    //      - SEEK_SET: start of file
    //      - SEEK_CUR: where the fp is currently
    //      - SEEK_END: end of file
    fseek(fp, 0, SEEK_SET);

    // fseek(fp, -20, SEEK_CUR);
    // an example of "go back 20 characters from current position"

    // storing the current position
    long int currentPosition = ftell(fp); // can use just "long"

    fseek(fp, -50, SEEK_END); // moved fp 50 bytes from end.
    // do stuff at this position...
    fseek(fp, currentPosition, SEEK_SET); // go back to that saved position

    // shortcut
    rewind(fp); //go to the start of the file

    printf("Count of the lines: %d\n", countFileLines(fp));

    return 0;
}