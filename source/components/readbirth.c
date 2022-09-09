#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void printBirth(void);

void readBirth(char* data){
    char res;
    do{
        clear();
        printBirth();
        scanf("%10[^\n]",data);
        clearBuffer();
        clear();
        printBirth();
        printcomplete(data);
        printf("|a data de nascimento acima confere[S/N]           |\n");
        printf("|__________________________________________________|\n");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}

void printBirth(void){
    printf(" __________________________________________________ \n");
    printf("|Digite a data de nascimento abaixo em formato:    |\n");
    printf("|                [00/00/0000]                      |\n");
    printf("|__________________________________________________|\n");
}