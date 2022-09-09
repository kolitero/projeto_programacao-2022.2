#include <stdio.h>
#include "../../header/components.h"
#include "../../header/util.h"

void printcpf(void);

void readCPF(char* cpf){
    char res;
    do{
        clear();
        printcpf();
        scanf("%14[^\n]",cpf);
        clearBuffer();
        clear();
        printcpf();
        printcomplete(cpf);
        printf("|o CPF acima confere[S/N]                          |\n");
        printf("|__________________________________________________|\n");
        scanf("%c",&res);
        clearBuffer();
    }while(res != 'S');
}

void printcpf(void){
    printf(" __________________________________________________ \n");
    printf("|Digite o CPF abaixo em formato:[DDD.DDD.DDD-DD]   |\n");
    printf("|__________________________________________________|\n");
}