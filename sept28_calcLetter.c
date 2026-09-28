#include <stdio.h> // includes should be in c files.

// function to calculate letter grade

// 'static' means only exists in this file
static char calcLetterGrade(int num){
    char grade;
    // step 1: calculate letter grade and store it into 'grade'.
    if (num >= 90)        grade = 'A';
    else if (num >= 80)   grade = 'B';
    else if (num >= 70)   grade = 'C';
    else if (num >= 60)   grade = 'D';
    else                  grade = 'F';

    return grade;
}

// function, take a number and print off the letter grade
void printGrade(int num){
    char grade = calcLetterGrade(num);

    printf("Your %d is a %c letter grade\n", num, grade); // multiple variables in a print
}