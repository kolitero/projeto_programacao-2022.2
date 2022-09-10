#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"
#include "../../header/validations.h"



void readName(char* name){
    char res = 'n';
    do{
        clear();
        printTable("Digite o nome abaixo:");
        scanf("%50[^\n]",name);
        clear();
        clearBuffer();
        printTable("Digite o nome abaixo:");
        printcomplete(name);
        if(validateName(name)){
            printcomplete("o nome acima confere[S/N]");
            scanf("%c",&res);
        }else{
            printcomplete("nome invalido");
            printcomplete("PRESSIONE ENTER PARA PROSSEGUIR");
        }
        clearBuffer();
    }while(res != 'S');
}
