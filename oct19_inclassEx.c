#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char name[50];
    char code[3];
    char desc[512];
}Room;

void printRoom(Room *theRoom);

int main(){
    Room testRoom;
    strcpy(testRoom.name, "Classroom");
    strcpy(testRoom.code, "CR");
    strcpy(testRoom.desc, "It's square!");

    printRoom(&testRoom); // give address location of the room

}

void printRoom(Room *theRoom){
    printf("You entered the %s room\n", theRoom->name);
    printf("%s\n",theRoom->desc);
}