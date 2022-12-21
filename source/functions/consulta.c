#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/util.h"
#include "../../header/consulta.h"
#include "../../header/components.h"

void addConsulta(void)
{
    Consulta consult;
    readName(consult.name);
    readCPF(consult.cpf);
    readPhone(consult.phone);
    readDate(consult.date);
    readCPF(consult.doctor);
    FILE *file;
    file = fopen("Consulta.dat", "ab");
    fwrite(&consult, 1, sizeof(Consulta), file);
    fclose(file);
}

void deleteConsulta(void)
{
    FILE *file, *back;
    Consulta consult;
    char nome[51];
    readName(nome);
    file = fopen("Consulta.dat", "rb");
    back = fopen("backConsulta.dat", "ab");
    while (fread(&consult, sizeof(Consulta), 1, file))
    {
        if (!strcmp(consult.name, nome))
        {
            fwrite(&consult, 1, sizeof(Consulta), back);
        }
    }
    fclose(file);
    fclose(back);
    remove("Consulta.dat");
    rename("backConsulta.dat", "Consulta.dat");
}

void editConsulta(void)
{
    FILE *file, *back;
    Consulta consult;
    file = fopen("Consulta.dat", "rb");
    back = fopen("backConsulta.dat", "ab");
    char name[51];
    readName(name);
    while (fread(&consult, sizeof(Consulta), 1, file))
    {
        if (!strcmp(consult.name, name))
        {
            fwrite(&consult, 1, sizeof(Consulta), back);
        }
        else
        {
            clear();
            printTable("desejar trocar a data:[S/N]");
            if (getchar() == 'S')
            {
                clearBuffer();
                readDate(consult.date);
            }
            else
            {
                clearBuffer();
            }
            clear();
            fwrite(&consult, 1, sizeof(Consulta), back);
        }
    }
    fclose(file);
    fclose(back);
    remove("Consulta.dat");
    rename("backConsulta.dat", "Consulta.dat");
}

void searchConsulta(void)
{
    FILE *file;
    Consulta consult;
    file = fopen("Consulta.dat", "rb");
    char name[51];
    readName(name);
    while (fread(&consult, sizeof(Consulta), 1, file))
    {
        if (!strcmp(consult.name, name))
        {
            printTable("nome:");
            printcomplete(consult.name);
            printcomplete("cpf do cliente:");
            printcomplete(consult.cpf);
            printcomplete("cpf do medico");
            printcomplete(consult.doctor);
            printcomplete("data da consulta:");
            printcomplete(consult.date);
            printcomplete("telefone:");
            printcomplete(consult.phone);
            getchar();
        }
    }
    fclose(file);
}

void readConsulta(void)
{
    FILE *file;
    Consulta consult;
    file = fopen("Consulta.dat", "rb");
    if(file){
        while (fread(&consult, sizeof(Consulta), 1, file)){
            putchar('\n');
            printTable(consult.cpf);
            printcomplete("nome do cliente:");
            printcomplete(consult.name);
            printcomplete("cpf do cliente");
            printcomplete(consult.cpf);
            printcomplete("Data da consulta:");
            printcomplete(consult.date);
            printcomplete("telefone de contato:");
            printcomplete(consult.phone);
            printcomplete("cpf do medico");
            printcomplete(consult.doctor);
        }
        fclose(file);
    }
}

void arquivarConsulta(void){
    FILE *file, *back, *pg;
    Consulta consult;
    Pagamento pag;
    char cpf[15];
    char date[11];
    char value[10];
    readCPF(cpf);
    readDate(date);
    readPrice(value);
    file = fopen("Consulta.dat", "rb");
    pg = fopen("pagamentos.dat", "ab");
    back = fopen("backConsulta.dat", "ab");0
    
    while (fread(&consult, sizeof(Consulta), 1, file))
    {
        if (!strcmp(consult.cpf, cpf) && !strcmp(consult.date, date))
        {
            strcpy(pag.cpf,consult.cpf);
            strcpy(pag.date , consult.date);
            strcpy(pag.doctor , consult.doctor);
            strcpy(pag.value , value);
            fwrite(&pag,1,sizeof(Pagamento),pg);
        }else{
            fwrite(&consult, 1, sizeof(Consulta), back);
        }
    }
    fclose(pg);
    fclose(file);
    fclose(back);
    remove("Consulta.dat");
    rename("backConsulta.dat", "Consulta.dat");
}