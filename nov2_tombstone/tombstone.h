#ifndef TOMBSTONE_H
#define TOMBSTONE_H


// typedef [basic struct "struct Tombstone"] as "Tombstone"
typedef struct Tombstone Tombstone;

typedef struct{
    Tombstone *t;
}Handler;

Handler tSet(int data);
int* tGet(Handler h);
void tDestroy(Handler h);
void tFree(Handler *h);


#endif