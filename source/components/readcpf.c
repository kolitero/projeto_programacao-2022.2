#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"
#include "../../header/validations.h"

void readCPF(char* cpf){
    char res = 'n';
    do{
        clear();
        printTable("Digite o CPF abaixo em formato:[DDD.DDD.DDD-DD]");
        scanf("%14[^\n]",cpf);
        clearBuffer();
        clear();
        printTable("Digite o CPF abaixo em formato:[DDD.DDD.DDD-DD]");
        printcomplete(cpf);
        if(validateCPF(cpf)){
            printcomplete("o CPF acima confere[S/N]");
            scanf("%c",&res);
        }else{
            printcomplete("CPF invalido");
            printcomplete("PRESSIONE ENTER PARA PROSSEGUIR");
        }
        clearBuffer();
    }while(res != 'S');
}
