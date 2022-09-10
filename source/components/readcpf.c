#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"


void readCPF(char* cpf){
    char res;
    do{
        clear();
        printTable("Digite o CPF abaixo em formato:[DDD.DDD.DDD-DD]");
        scanf("%14[^\n]",cpf);
        clearBuffer();
        clear();
        printTable("Digite o CPF abaixo em formato:[DDD.DDD.DDD-DD]");
        printcomplete(cpf);
        printcomplete("o CPF acima confere[S/N]");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}
