#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Coder.h"
#include "Validate.h"

int main(int argc, char* argv[]){
    if (argc == 4) {
    char* cipher = argv[1];
    char* str = argv[2];
    char* pass = argv[3];
    if (strcmp(cipher, "--caesar") == 0){
        if (ifNumber(pass)){
            int pass = atoi(pass) * (-1);
            muttableCaesar(str, pass);
            printf("%s\n", str);
        }
        else{
            printf("Ключ должен быть числом.\n");
        }
    }
    else if (strcmp(cipher, "--xor") == 0){
        if (ifLetter(pass)){
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
    }
    else {
        printf("Неправильное количество аргументов.\n");
    }
    return 0;
}
