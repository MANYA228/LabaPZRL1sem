#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Coder.h"

int main(int argc, char* argv[]){
    char* cipher = argv[1];
    char* str = argv[2];
    char* pass = argv[3];
    if (strcmp(cipher, "--caesar") == 0){
        if (ifNumber(pass)){
            muttableLastSpace(str);
            muttableLower(str);
            muttableCaesar(str, atoi(pass));
            printf("%s\n", str);
        }
        else{
            printf("Ключ должен быть числом.\n");
        }
    }
    else if (strcmp(cipher, "--xor") == 0){
        if (ifLetter(pass)){
            muttableLastSpace(str);
            muttableLower(str);
            muttableXor(str, pass);
            printf("%s\n", str);
        }
        else{
            printf("Ключ должен состоять только из букв.\n");
        }
    }
    else{
        printf("Неправильный ввод шифра.\n");
    }
    return 0;
}
