#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a new struct
typedef struct{ // in total, this struct take up 108 bytes of mem
    int age;
    char name[100];
    int height; // height in cm
} Person;

typedef struct{ // 16 bytes total (8 per mem address)
    char *make;
    char *model;
} Car;

void deleteCar(Car *theCar){
    free(theCar->make); // need to use arrow notation, working with mem address
    free(theCar->model);
}

int main(){
    printf("Hello World\n");

    Person aPerson; // on the stack

    aPerson.age = 37;
    strcpy(aPerson.name, "Troy");
    aPerson.height = 2000;

    printf("%s's age is %d\n", aPerson.name, aPerson.age);

    Person *personPtr;
    personPtr = malloc(sizeof(Person)); // on the heap, reserved 1 "Person" of space

    //int *x;
    //*x = 42;

    (*personPtr).age = 60; // annoying way to modify
    personPtr->height = 1000; // arrow method
    strcpy(personPtr->name, "Bob");

    
    free(personPtr);


    // make a car
    Car aCar; // on the stack
    // this goes on the heap, the pointer is just looking at it
    aCar.make = malloc(sizeof(char)*30); // reserving 30 bytes on heap
    aCar.model = malloc(sizeof(char)*20); // reserving 20 

    //free(aCar); // not a pointer, nothing to free

    // need to give the reference to the car
    deleteCar(&aCar);

    Car *ptrCar = malloc(sizeof(Car)*100); // array of 100 cars
    for (int i = 0; i < 100; i++){
        // treating it like an array, it follows the mem address at that position
        ptrCar[i].make = malloc(sizeof(char)* 30);
        ptrCar[i].model = malloc(sizeof(char)*20);
    }

    // time to free all the info
    for (int i = 0; i < 100; i++) deleteCar(&ptrCar[i]);
    free(ptrCar); // free the array of cars

    return 0;
}