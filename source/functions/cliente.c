#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/util.h"
#include "../../header/cliente.h"
#include "../../header/components.h"



void addCliente(void){
	Cliente client;
	readName(client.name);
	readCPF(client.cpf);
	readPhone(client.phone);
	readEmail(client.email);
	readBirth(client.birth);
	client.existence = 'y';
	FILE *file;
	file = fopen("Cliente.dat", "ab");
	fwrite(&client, 1, sizeof(Cliente), file);
	fclose(file);
}

void deleteCliente(void){
	FILE *file,*back;
	Cliente client;
	char nome[51];
	readName(nome);
	file = fopen("Cliente.dat", "rb");
	back = fopen("backCliente.dat","ab");
	while(fread(&client,sizeof(Cliente),1,file)){
		if(strcmp(client.name,nome)){
		fwrite(&client,1,sizeof(Cliente),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("Cliente.dat");
	rename("backCliente.dat","Cliente.dat");
}

void editCliente(void){
	FILE *file,*back;
	Cliente client;
	file = fopen("Cliente.dat", "rb");
	back = fopen("backCliente.dat","ab");
	char name[51];
	readName(name);
	while(fread(&client,sizeof(Cliente),1,file)){
		if(strcmp(client.name,name)){
		fwrite(&client,1,sizeof(Cliente),back);
		}
		else{
			clear();
			printTable("desejar trocar o nome:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readName(client.name);
			}else{
			    clearBuffer();
			}
			clear();
			printTable("desejar trocar o Email:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readEmail(client.email);
			}else{
			    clearBuffer();
			}
			clear();
			printTable("desejar trocar o telefone:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readPhone(client.phone);
			}else{
			    clearBuffer();
			}
			clear();
			fwrite(&client,1,sizeof(Cliente),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("Cliente.dat");
	rename("backCliente.dat","Cliente.dat");
}

void searchCliente(void){
	FILE *file;
	Cliente client;
	file = fopen("Cliente.dat", "rb");
	char name[51];
	readName(name);
	while(fread(&client,sizeof(Cliente),1,file)){
		if(!strcmp(client.name,name)){
			printTable(client.cpf);
			printcomplete("nome:");
			printcomplete(client.name);
			printcomplete("Email:");
			printcomplete(client.email);
			printcomplete("Data de nascimento:");
			printcomplete(client.birth);
			printcomplete("telefone:");
			printcomplete(client.phone);
			getchar();
		}
	}
	fclose(file);
}

void readCliente(void){
	FILE *file;
	Cliente client;
	file = fopen("Cliente.dat", "rb");
    if(file){
        while ((fread(&client, sizeof(Cliente), 1, file))) {
            putchar('\n');
            printTable(client.cpf);
            printcomplete("nome:");
            printcomplete(client.name);
            printcomplete("Email:");
            printcomplete(client.email);
            printcomplete("Data de nascimento:");
            printcomplete(client.birth);
            printcomplete("telefone:");
            printcomplete(client.phone);
        }
        fclose(file);
    }
}

