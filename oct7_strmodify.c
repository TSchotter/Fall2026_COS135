#include <stdio.h>
#include <stdlib.h> // Allows malloc
#include <string.h> // string length
#include <ctype.h> // check individual characters for certain properties

char* trim(char *strToTrim){
    int strSize = strlen(strToTrim); // \0 not considered part of the str

    printf("Character: [%c]\n", strToTrim[strSize-1]);

    char *endPtr = strToTrim + strSize - 1;

    // give the character that endPtr is looking at
    while(isspace(*endPtr)){
        endPtr--; // move the end backwards
    }
    // two line method
    //endPtr++;
    //*endPtr = '\0'; // say the string ends here
    *(endPtr+1) = '\0'; // one line method

    printf("New String trimmed on right = [%s]\n", strToTrim);

    // time to find new start of string
    char *start = strToTrim;

    // move start to first non-space character
    while(isspace(*start)){
        start++; // found a space, move right
    }
    // by this point, start is looking at the first character of the actual string we want

    // reserve memory dynamically, of perfect size for our string.
    char *finalVersion = malloc(sizeof(char) * strlen(start)+1);

    // copy the string into new storage spot
    strcpy(finalVersion, start);
    printf("Final trimmed version = [%s]\n", finalVersion);
    // placeholder
    return finalVersion;
}



int main() {


    // immutable string, can't modify it (read-only)
    char *first = "Hello";

    // mutable string (can modify it), and creates a perfect length buffer.
    char second[] = "World";

    // mutable string, size 100 characters. ['T', 'a', 'd', 'a', '!', '\0', ?, ?, ....]
    char third[100] = "Tada!";

    // change '!' to a '?'
    third[4] = '?';
    printf("%s\n", third);

    // change 'W' to 'w'
    // follow the memory address, and change the value of what it's pointing at
    *second = 'w';
    printf("%s\n", second);

    // try to change something about first
    //first[2] = 'c';
    //printf("%s\n", first);

    // get some input from the user.
    char buffer[100];
    // takes the destination of the string,
    // the size of the destination
    // from where are you getting the information
    // "stdin" = standard input, this is input from the terminal
    fgets(buffer, sizeof(buffer), stdin);
    printf("You typed... [%s]\n", buffer);
    // hand the buffer to our trim function
    char *trimmedString = trim(buffer); // set pointer to look at new returned character array space.

    // we malloc'ed data, we need to free it when we're finished
    free(trimmedString);

    return 0;
}