#include <stdlib.h>
#include <stdio.h>
#include "tombstone.h" // I want to be able to use Handler

// fully define tombstone
struct Tombstone{
    int* data;
};

// We give data, it gives back a Handler holding the
// Tombstone that's holding the data.
Handler tSet(int data){
    // create the pointer that will hold the data
    int *dataHolder;
    // Pointer that will hold the Tombstone
    Tombstone *tombHolder;

    // NOT a pointer for the Handler;
    Handler h;

    // make space for data
    dataHolder = malloc(sizeof(int));
    // fill the data into the space
    *dataHolder = data;

    // make space for Tombstone
    tombHolder = malloc(sizeof(Tombstone));
    
    // save the dataHolder into the Tombstone
    tombHolder->data = dataHolder;

    // save the Tombstone into Handler
    h.t = tombHolder;

    // return the handler
    return h;
}

int *tGet(Handler h){

    // this is true when either the Tombstone
    // or the data in Tombstone is gone
    if (h.t == NULL || h.t->data == NULL){
        return NULL;
    }
    // otherwise, give them the data
    return h.t->data;
}

// Designed to destroy the data (free the data)
void tDestroy(Handler h){
    if (h.t != NULL && h.t->data != NULL){
        free(h.t->data);
        h.t->data = NULL; // be safe, have addr point to nothing
    }
}
// Designed to free the Tombstone
void tFree(Handler *h){
    if (h->t != NULL){
        free(h->t);
        h->t = NULL;
    }
}