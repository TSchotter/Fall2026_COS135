// Single Responsibility Principle and 'static'

// every function and every file has one job, goal, task.
// adv: 
// - easier to identify problems (you know which module is the cause)
// - following the principle of solving the big by solving the small
// - portability, the ability to reuse code.


#include <stdio.h>
// your files you use quotes for the filename
#include "sept28_calcLetter.h"

#define NUM_GRADE 75


int main(){
    // call the print grade
    printGrade(NUM_GRADE);
    
    char grade = calcLetterGrade(80);

    return 0;
}

