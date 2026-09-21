#include <stdio.h>

// forward declare factorialMake

int factorialMake(int bacon); // declaration to the function
void doStuff(int x);
void modifyArray(int x[], int z);
int main();


// no return type for the function = void return type
void doStuff(int x){  // need the data type for parameters
    // scope of x is this function.

    x += 10;
    printf("The number is.... %d\n", x);
    return; // if you want the function to end on your terms
}

void modifyArray(int x[], int sizeofX){ // safe practice, send the size of the array with the array.

    //change first value of array
    x[0] += 1;

    printf("First value of array x is... %d\n", x[0]);
    printf("Second Value of array x is... %d\n", x[1]);
    printf("Too far value x...  %d\n", x[3]); // we print a value outside the range of the array,
        // this could be anything. Old data from some previous program.
}


// int <- return type.
int main(){ // Entry point for the program

    // call function, hand it the number 5
    doStuff(5);

    int x = 10;
    doStuff(x); // make a copy of x, send that copy
    doStuff(x); // still prints (20)

    int y[3]; // declare array with 3 int spots. Zero out the spots.
    y[0] = 3;
    modifyArray(y, 3);
    modifyArray(y, 3);

    int h = factorialMake(5); // don't *need* to catch the return value

    printf("Factorial of 5 %d\n", h);


    char buffer[100];

    // scanf <- grabbing input from the console
    // advantage: automatically convert what you want. If you grab an int, you can assign to int.
    // can be used to grab multiple things.
    // disadvantage: can leave things behind in the input buffer, which scanf's will find.


    // fgets <- get input from input stream. 
    // advantage: grabs entire line of input from the user.
    // also used for file input.
    // disadvantage: you need to parse the string yourself.
    // need buffer to be big enough to handle expected input.

    int z;
    // give it the *memory address* of z
    scanf("%d", &z);

    
    printf("We grabbed z and it's %d\n", z);


    scanf("%s", buffer);
    printf("The buffer contains %s\n", buffer);

    return 0;
}

// need to know this exists before here
int factorialMake(int x){
    int result = 1;

    for(;x>1;x--){ // continue so long as x > 1, every iteration decrease x
        result *= x;
    }

    return result;
}