// define a "header guard"
#ifndef TOOLS_H// "if not defined"
#define TOOLS_H // define the header variable

// a forward declaration
int addTwoNums(int x, int y);

int grabNumber();

void createPyramid(int n);
void createReversePyramid(int n);

// takes an array, and prints every number in it
void iterateArray(int numArray[], int count);


#endif // close the header guard