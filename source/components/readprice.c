#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"
#include "../../header/validations.h"

void readPrice(char* value){
    char res = 'n';
    do{
        clear();
        printTable("Digite o preco abaixo");
        scanf("%9[^\n]",value);
        clearBuffer();
        clear();
        printTable("Digite o preco abaixo");
        printcomplete(value);
        if(validatePrice(value)){
            printcomplete("o preco acima confere[S/N]");
            scanf("%c",&res);
        }else{
            printcomplete("valor invalido");
            printcomplete("PRESSIONE ENTER PARA PROSSEGUIR");
        }
        clearBuffer();
    }while(res != 'S');
}