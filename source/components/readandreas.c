#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void printnAndreas(void);

void readAndreas(char* andreas){
    char res;
    do{
        clear();
        printnAndreas();
        scanf("%50[^\n]",andreas);
        clearBuffer();
        clear();
        printnAndreas();
        printcomplete(andreas);
        printf("|o endereco acima confere[S/N]                         |\n");
        printf("|__________________________________________________|\n");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}

void printnAndreas(){
    printf(" __________________________________________________ \n");
    printf("|Digite o endereco abaixo:                            |\n");
    printf("|__________________________________________________|\n");
}