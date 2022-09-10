#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"


void readAndreas(char* andreas){
    char res;
    do{
        clear();
        printTable("Digite o endereco abaixo:");
        scanf("%50[^\n]",andreas);
        clearBuffer();
        clear();
        printTable("Digite o endereco abaixo:");
        printcomplete(andreas);
        printcomplete("o endereco acima confere[S/N]");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}