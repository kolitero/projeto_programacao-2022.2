#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void readEmail(char* email){
    char res;
    do{
        clear();
        printTable("Digite o Email abaixo:");
        scanf("%50[^\n]",email);
        clearBuffer();
        clear();
        printTable("Digite o Email abaixo:");
        printcomplete(email);
        printcomplete("o nome acima confere[S/N]");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}