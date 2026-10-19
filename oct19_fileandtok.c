#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// String tokenizer
// same as the string "split" of python, used to seperate a string based on a character

int main(){

    // string to split = buffer,
    // deli = what is seperating our data
    char buffer[] = "Troy,37,Computer Science";
    char deli[] = ",";

    char *tok = strtok(buffer, deli); // first tokenizer run

    

    while (tok != NULL){ // tokenizer will be NULL when it hits the end of the string
        printf("String part = %s\n", tok);
        // if we want to pick a different deliminator, we can
        tok = strtok(NULL, deli); // subsequent runs, use "NULL" for the input buffer.
    }

    // open the file to *read*
    // first parameter: file name (relative path)

    // second parameter: how are you opening? 
    // (r = read, w = write, a = append, r+ read and write, w+ write and read)
    // w will create the file if it doesn't exist
    // r+ will error if the file does not exist.
    // w+ will create the file if it doesn't exist
    FILE *fp = fopen("test.txt", "r");

    char fileBuffer[50]; // reserve some space for reading a file.
    // fgets takes three things
    // 1. buffer
    // 2. size of the buffer
    // 3. where are we reading from
    /* This was the manual way, reading one line at a time
    fgets(fileBuffer, sizeof(fileBuffer), fp); // grabs one line of info
    printf("one line: %s\n", fileBuffer);
    fgets(fileBuffer, sizeof(fileBuffer), fp); // grab next line of info
    printf("one line: %s\n", fileBuffer);
    fgets(fileBuffer, sizeof(fileBuffer), fp); // grabs one line of info
    printf("one line: %s\n", fileBuffer);
    fgets(fileBuffer, sizeof(fileBuffer), fp); // grab next line of info
    printf("one line: %s\n", fileBuffer);
    */
    // continue getting one line so long as the fgets does not give "NULL"
    // fgets gives "NULL" when there are no more lines.
    while (fgets(fileBuffer, sizeof(fileBuffer), fp) != NULL){
        printf("one line: %s\n", fileBuffer);
    }

    fclose(fp); // always close files when done
    return 0;

}