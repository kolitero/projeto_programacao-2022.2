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
    int x = 0;
    int v = 0;
    while(string[x]){
        putchar(string[x]);
        if(string[x] < 0){
            x++;
            putchar(string[x]);
        }
        v++;
        x++;
    }
    for(int len = v;len < 50;len++){
        putchar(' ');
    }
    putchar('|');
    putchar('\n');
}
