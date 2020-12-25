#include <string.h>
#include <stdlib.h>
void    muttableCaesar(char* str, int pass);
char*   immutableCaesar(const char* str, int pass);
char*   immutableXor(const char* str, char* pass);
void	muttableXor(char* str, char* pass);
void    muttableLower(char* str);
char*   immuttableLower(const char* str);
void    muttableLastSpace(char str[]);
char*   immutableLastSpace(const char* str);
int     ifLetter(char* str);
int     ifNumber(char* str);
char*   immutableFilter(const char* str);
void    mutableFilter(char str[]);