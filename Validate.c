#include "Validate.h"

void    muttableFilterSpace(char str[]){
    int j = 0;
    for (int i = j = 0; str[i] != '\0'; ++i){
        if (str[i] != ' '){
            str[j] = str[i];
            ++j;
        }
    str[j] = '\0';
    }
}

char*   immutableFilterSpace(const char* str){
    int j = 0;
    char* end = malloc(strlen(str) * sizeof(char));
    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] != ' ') {
            end[j] = str[i];
            ++j;
        }
    }
    end = realloc(end, (1 + j) * sizeof(char));
    end[j] = '\0';
    return end;
}

void    muttableFilter(char str[]){
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == ' ' || str[i] >= 'a' && str[i] <= 'z' 
        || str[i] >= 'A' && str[i] <= 'Z' 
        || str[i] >= '0' && str[i] <= '9'){
            str[j] = str[i];
            ++j;
        }
   }

   str[j] = '\0';
}

char*   immutableFilter(const char* str){
    int j = 0;
    char* end = malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < strlen(str); ++i){
        if(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') 
                                                            || (str[i] >= 'a' && str[i] <= 'z')){
            end[j] = str[i];
            ++j;
        }
    }
    end = realloc(end, (1 + j) * sizeof(char));
    end[j] = '\0';
    return end;
}

void    muttableUpper(char* str){
    while (*str){
        if ('a' <= *str && *str <= 'z'){
            *str += 'A' - 'a';
        }
        ++str;
    }
}

char*   immutableUpper(const char* str){
    char* end = malloc((strlen(str) + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i <= strlen(str); ++i){
        if ('a' <= str[i] && str[i] <= 'z') {
            end[i] = str[i] + 'A' - 'a';
        }
        else {
            end[i] = str[i];
        }
    }
    return end;
}