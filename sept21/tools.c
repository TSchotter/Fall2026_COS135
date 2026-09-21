// contains useful tools
#include <stdio.h>

int addTwoNums(int x, int y){

    return x+y;
}

int grabNumber(){
    printf("Please enter a number:\n");

    //int x;
    //scanf("%d", &x); // the memory addr of x

    // fgets method
    char buffer[100]; // need a buffer
    // we know the size of the buffer.
    printf("Enter a number");
    fgets(buffer, sizeof(buffer), stdin);
    // if we didn't know the size
    int sizeOfBuffer = 100;
    // sizeof(buffer[0]) is effectively asking...
    // the memory size of a single element of this array.
    fgets(buffer, sizeOfBuffer * sizeof(buffer[0]), stdin);

    return 10;
}

void createPyramid(int n){
    return;
}
void createReversePyramid(int n){
    return;
}

// takes an array, and prints every number in it
void iterateArray(int numArray[], int count){
    //for( init step ; condition ; iteration step )
    for(int i = 0; i < count; i++){
        printf("[%d]", numArray[i]);
    }

    // pointer method of iteration
    int *p; // an integer pointer.
    p = numArray;

    printf("The first number was %d\n", *p); //follow the memory address to the location
    p++; // move 1 integer worth of memory forward
    printf("The next number is %d\n", *p++);

    p = numArray; // move pointer back to start
    for(int i = 0; i < count; i++){
        printf("[%d]", *p++); // print value pointer is looking at, then move it to next
    }

    p = numArray;
    //for( init step ; condition ; iteration step )
    for(int i = 0; i < count; i++){
        printf("[%d]", p[i]); // just as accurate
    }

    // lets change a number
    //p = 6; // problem. this would change the memory addr

    p = numArray;
    *p = 9; // changing the value the mem addr is looking at.
    *(p+1) = 4; // changing the value the mem addr + (another int mem size) to another number;

    int x = 7;
    //p = x; // nope, this would try to assign the number 7 to the mem variable

    p = &x; // assign our pointer to the mem addr of x
}