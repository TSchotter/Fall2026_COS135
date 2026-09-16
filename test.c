#include <stdio.h>
// printf(" %d ", valuetoprint);
int main(){
    int n = 5;
    for(int i = 0; i < n; i++){

        for(int j = 0; j <= i; j++){
            printf("x");
        }
        printf("\n");
    }


    for(int i = 0; i < n; i++){

        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < n-i; j++){
            printf("x");
        }
        printf("\n");


    }
    return 0;
}