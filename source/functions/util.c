#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../header/util.h"

void clear(void){
    system("cls||clear");
}

void clearBuffer(void){
    while((getchar()) != '\n');
}

void printStart(char* string){
    printf(" __________________________________________________ \n");
    printline(string);
}

void printcomplete(char* string){
    printline(string);
    printf("|__________________________________________________|\n");
}

void printTable(char* string){
    printf(" __________________________________________________ \n");
    printcomplete(string);
}

void printline(char* string){
    putchar('|');
    printf("%s",string);
    for(int len  = strlen(string);len < 50;len++){
        putchar(' ');
    }
    putchar('|');
    putchar('\n');
}
