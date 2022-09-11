#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"
#include "../../header/validations.h"

void readBirth(char* data){
    char res = 'n';
    do{
        clear();
        printStart("Digite a data de nascimento abaixo em formato:");
        printcomplete("             00/00/0000");
        scanf("%10[^\n]",data);
        clearBuffer();
        clear();
        printline("Digite a data de nascimento abaixo em formato:");
        printcomplete("             DD/MM/AAAA");
        printcomplete(data);
        if(validateDate(data)){
            printcomplete("a data acima confere[S/N]");
            scanf("%c",&res);
        }else{
            printcomplete("CPF invalido");
            printcomplete("PRESSIONE ENTER PARA PROSSEGUIR");
        }
        clearBuffer();
    }while(res != 'S');
}
