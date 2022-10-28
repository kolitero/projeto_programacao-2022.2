#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"
#include "../../header/validations.h"


void readDate(char* data){
    char res = 'n';
    do{
        clear();
        printStart("       Digite a data abaixo em formato:");
        printcomplete("             00/00/0000");
        scanf("%10[^\n]",data);
        clearBuffer();
        clear();
        printline("        Digite a data abaixo em formato:");
        printcomplete("             DD/MM/AAAA");
        printcomplete(data);
        if(validateDate(data)){
            printcomplete("a data acima confere[S/N]");
            scanf("%c",&res);
        }else{
            printcomplete("Data invalida");
            printcomplete("PRESSIONE ENTER PARA PROSSEGUIR");
        }
        clearBuffer();
    }while(res != 'S');
}
