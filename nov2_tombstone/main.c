#include <stdio.h>
#include "tombstone.h"

int main(){


    Handler box = tSet(5);
    printf("The number stored is %d\n", *tGet(box));

    // clean up, free the data
    tDestroy(box);
    tFree(&box);
    

    tFree(&box); // safe, since we have an if statement
    tDestroy(box); // also safe
    return 0;
}