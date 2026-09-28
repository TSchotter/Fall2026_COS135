// other libraries

// printf
// scanf
// fgets
#include <stdio.h> 

// access to 'bool' data type
#include <stdbool.h>

// character functions
// isdigit
// isalpha
// isalnum
// tolower
// toupper
#include <ctype.h>

// string functions
// strlen  (string length)
// strcpy  (string copy)
// strcmp  (string compare)
#include <string.h>

// check if a password is valid function
// things to check:
// 1. length requirement
// 2. at least one capital letter
// 3. at least one number
// 4. at least one lowercase letter

// check if length requirement good (lowerbound)
bool lengthOK(char *password, int requirement){
    if (strlen(password) >= requirement)
        return true;
    return false;
}

// check if at least one capital letter
bool capOK(char *password){

    for(int i = 0; i < strlen(password); i++)
        if (isalpha(password[i]) && isupper(password[i])) return true;

        
    return false;
}

// check if at least one lower letter
bool lowOK(char *password){

    for(int i = 0; i < strlen(password); i++)
        if (isalpha(password[i]) && islower(password[i])) return true;

        
    return false;
}
