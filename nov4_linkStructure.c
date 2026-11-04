#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// there is a "Room" type structure, and we're going to call it "Room"
typedef struct Room Room;

// This is the definition of "Room" struct
struct Room{
    char code[3];
    char name[256];
    char desc[1024];
    Room* east, *west;
};

Room* createRoom(char* code, char* name, char* desc){
    Room *n = malloc(sizeof(Room));
    strcpy(n->code, code);
    strcpy(n->name, name);
    strcpy(n->desc, desc);
    n->east = NULL;
    n->west = NULL;
    return n;
}


int main(){
    Room *x1 = createRoom("GP", "Good Place", "Its a good place.");
    x1->east = createRoom("JE", "Jail Entrance", "Entrance to the jail");
    x1->east->west = x1;
    x1->west = createRoom("OS", "Office Space", "It's boring");
    x1->west->east = x1;

    x1 = x1->east;
    x1 = x1->west;
    
    Room *start = x1->east;
    Room *player = start;

    char buffer[100];
    while(1){
        // print the desc of where the player is
        printf("You are in the %s,\n%s\n:", player->name, (*player).desc);
        fgets(buffer, sizeof(buffer), stdin);
        // if they type east, attempt to "go east"
        // if they type west, attempt to "go west"
        // for the sake of lazy, just look at the character.

        // replacement for a giant if/elseif/else chain
        switch(buffer[0]){
            case 'e':
                if (player->east == NULL)
                    printf("Nope, there's a wall\n");
                else 
                    player = player->east;
                break; // get out of the switch statement, don't continue into 'w'.
            case 'w':
                if (player->west == NULL)
                    printf("Nope, there's a wall\n");
                else 
                    player = player->west;
                break;
            case 'q':
                return 0;
                break;
            default:
                printf("That's not a correct command!\n");
        }
    }

}