#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"


void readBirth(char* data){
    char res;
    do{
        clear();
        printStart("Digite a data de nascimento abaixo em formato:");
        printcomplete("             00/00/0000");
        scanf("%10[^\n]",data);
        clearBuffer();
        clear();
        printline("Digite a data de nascimento abaixo em formato:");
        printcomplete("             00/00/0000");
        printcomplete(data);
        printcomplete("a data acima confere[S/N]");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}
