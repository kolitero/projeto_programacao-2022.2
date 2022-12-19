#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/util.h"
#include "../../header/components.h"
#include "../../header/consulta.h"
#include "../../header/rendimento.h"

void rendimentocliente(void){
    char cpf[15];
    Pagamento pag;
    FILE *file;
    readCPF(cpf);
    file = fopen("pagamentos.dat","rb");
    while (fread(&pag,sizeof(pag),1,file))
    {
        if(!strcmp(pag.cpf,cpf)){
            printTable("meidco resposanvel:");
            printcomplete(pag.doctor);
            printcomplete("data da consulta:");
            printcomplete(pag.date);
            printcomplete("valor pago:");
            printcomplete(pag.value);
        }
    }
    
}

void rendimentomedico(void){
    char cpf[15];
    Pagamento pag;
    FILE *file;
    readCPF(cpf);
    file = fopen("pagamentos.dat","rb");
    while (fread(&pag,sizeof(pag),1,file))
    {
        if(!strcmp(pag.cpf,cpf)){
            printTable("cliente atendido:");
            printcomplete(pag.cpf);
            printcomplete("data da consulta:");
            printcomplete(pag.date);
            printcomplete("valor pago:");
            printcomplete(pag.value);
        }
    }
    
}