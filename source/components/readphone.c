#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"


void readPhone(char* phone){
    char res;
    do{
        clear();
        printTable("Digite o telefone abaixo:");
        scanf("%50[^\n]",phone);
        clearBuffer();
        clear();
        printTable("Digite o telefone abaixo:");
        printcomplete(phone);
        printcomplete("o telefone acima confere[S/N]");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}