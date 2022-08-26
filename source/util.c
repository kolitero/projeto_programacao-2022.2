#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clear(void){
    #ifdef _Win32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void clearBuffer(void){
    while((getchar()) != '\n');
}

void readname(char* str){
  char aux;
  scanf("%s", str);
  while ((getchar()) != 10) {
    strcat(str, " ");
    char extra[100];
    scanf("%s", extra);
    int tam1 = strlen(str);
    int tam2 = strlen(extra);
    if ((tam1 + tam2 + 1) < 100) {
      strcat(str, extra);
    }
  }
}