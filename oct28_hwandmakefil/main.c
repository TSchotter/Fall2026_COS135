#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

// Ultimate goal, create a list of rooms and print them out.

// Sub-goals
// 0. Create a repository
// 1. Open a file, that was to via command line.
// 2. Be able to make *A* Room. (a function that takes 3 strings and gives back a Room pointer)
// 3. Be able to trim a string
// 4. How can we tell we're done reading a single room?
// 5. How can we tell we're at the "Room Name" line?
// 6. How many rooms exist in the file?
// 7. How can we trim the label of the line?
// 8. How can we create a structure from the data we're reading in (in a loop)?
// 9. How can we print the information from a single Room?
// 10. How can we print the info for all Rooms?


int main(){

    FILE *fp = fopen("dungeonRoomList_large.txt", "r");
    char sep[] = ":";

    char buffer[1024]; // recommendation, make big
    while(fgets(buffer, sizeof(buffer), fp)){
        //printf("||%s||", buffer);

        char *tp = strtok(buffer, sep);
        printf("|%s|\n", tp);
    }

    return 0;
}