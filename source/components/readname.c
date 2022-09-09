#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void printName(void);

void readName(char* name){
    char res;
    do{
        clear();
        printName();
        scanf("%50[^\n]",name);
        clearBuffer();
        clear();
        printName();
        printcomplete(name);
        printf("|o nome acima confere[S/N]                         |\n");
        printf("|__________________________________________________|\n");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}

void printName(){
    printf(" __________________________________________________ \n");
    printf("|Digite o nome abaixo:                             |\n");
    printf("|__________________________________________________|\n");
}