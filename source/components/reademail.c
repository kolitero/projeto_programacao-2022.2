#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void printEmail(void);

void readEmail(char* email){
    char res;
    do{
        clear();
        printEmail();
        scanf("%50[^\n]",email);
        clearBuffer();
        clear();
        printEmail();
        printcomplete(email);
        printf("|o Email acima confere[S/N]                        |\n");
        printf("|__________________________________________________|\n");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}

void printEmail(){
    printf(" __________________________________________________ \n");
    printf("|Digite o Email abaixo:                            |\n");
    printf("|__________________________________________________|\n");
}