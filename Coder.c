#include "Coder.h"

void    muttableCaesar(char* str, int pass){
    char dec;
    for (int i = 0; str[i] != '\0'; ++i){
        dec = str[i];
        if(dec >= 'a' && dec <= 'z'){
            if (dec + pass < 'z'){
                dec = dec + pass;
            }
            else if (dec + pass > 'z'){
                dec = 'a' + (dec + pass) % ('z' - 'a' + 1);
            }
            else if (dec + pass < 'a'){
                dec = 'z' - ('a' % dec) + 1;
            }
        }
        str[i] = dec;
    }
}

char*   immutableCaesar(const char* str, int pass){
    char* end = malloc((strlen(str) + 1) * sizeof(char));
    char dec;
    for(int i = 0; str[i] != '\0'; ++i){
        dec = str[i];
        if(dec >= 'a' && dec <= 'z'){ 
            if (dec + pass < 'z'){
                dec = dec + pass;
            }
            else if (dec + pass > 'z'){
                 dec = 'a' + (dec + pass) % ('z' - 'a' + 1);
            }
            else if (dec + pass < 'a'){
                dec = 'z' - ('a' % dec) + 1;
            }
        }
        end[i] = dec;
    }
	return end;
}

char*   immutableXor(const char* str, char* pass){
	char* end = malloc((strlen(str) + 1) * sizeof(char));
	int i = 0;
	for (i = 0; i <= strlen(str); ++i){
		end[i] = str[i] ^ pass[i % strlen(pass)];
	}
	end[i] = '\0';
    return end;
}

void	muttableXor(char* str, char* pass){
	for (int i = 0; i < strlen(str); ++i){
		str[i] = str[i] ^ pass[i % strlen(pass)];
    }
}

void    muttableLower(char* str){
    while (*str){
        if ('A' <= *str && *str <= 'Z'){
            *str += 'a' - 'A';
        }
        ++str;
    }
}

char*   immuttableLower(const char* str){
    char* end = malloc((strlen(str) + 1) * sizeof(char));
    for (int i = 0; i <= strlen(str); ++i){
        if ('A' <= str[i] && str[i] <= 'Z'){
            end[i] = str[i] + 'a' - 'A';
        }
        else{
            end[i] = str[i];
        }
    }
    return end;
}

void    muttableLastSpace(char str[]){
    int nachalo = 0;
    int konec = strlen(str) - 1;
    while(str[nachalo] == ' '){
        ++nachalo;
    }
    while(str[konec] == ' '){
        --konec;
    }
    int len = konec - nachalo + 1;
    for (int i = 0; i <= len; ++i){
        str[i] = str[i + nachalo];
    }
    str[len] = '\0';
}

char*   immutableLastSpace(const char* str){
    char* end = malloc(strlen(str) * sizeof(char));
    int j = 0;

    for (int i = 0; i < strlen(str); ++i){

        if (str[i] != ' '){
            end[j] = str[i];
            ++j;
        }

        else{
            continue;
        }
    }

    end[j] = '\0';
    return end;
}

void    muttableFilter(char str[]){
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == ' ' || str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' 
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
        if(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9') 
        || (str[i] >= 'A' && str[i] <= 'Z') 
        || (str[i] >= 'a' && str[i] <= 'z')){
            end[j] = str[i];
            ++j;
        }
    }
    end = realloc(end, (1 + j) * sizeof(char));
    end[j] = '\0';
    return end;
}

int     ifLetter(char* str){
    int check;
    while (*str){
        if (*str >= 'A' && *str <= 'Z' || *str >= 'a' && *str <= 'z' || *str == ' '){
            check = 1;
        }
        else{
            check = 0;
            return check;
        }
        ++str;
    }
    return check;
}

int     ifNumber(char* str){
    int check;
    while (*str){
        if (*str >= '0' && *str <= '9' || str[0] == '-'){
            check = 1;
        }
        else{
            check = 0;
            return check;
        }
            ++str;
    }
    return check;
}