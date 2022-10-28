#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/util.h"
#include "../../header/profissional.h"
#include "../../header/components.h"



void addProfissional(void){
	Profissional func;
	readName(func.name);
	readCPF(func.cpf);
	readAndreas(func.andreas);
	readEmail(func.email);
	readBirth(func.birth);
	FILE *file;
	file = fopen("profissional.dat", "ab");
	fwrite(&func, 1, sizeof(Profissional), file);
	fclose(file);
}

void deleteProfissional(void){
	FILE *file,*back;
	Profissional func;
	char nome[51];
	readName(nome);
	file = fopen("profissional.dat", "rb");
	back = fopen("backprofissional.dat","ab");
	while(fread(&func,sizeof(Profissional),1,file)){
		if(strcmp(func.name,nome)){
		fwrite(&func,1,sizeof(Profissional),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("profissional.dat");
	rename("backprofissional.dat","profissional.dat");
}

void editProfissional(void){
	FILE *file,*back;
	Profissional func;
	file = fopen("profissional.dat", "rb");
	back = fopen("backprofissional.dat","ab");
	char name[51];
	readName(name);
	while(fread(&func,sizeof(Profissional),1,file)){
		if(strcmp(func.name,name)){
		fwrite(&func,1,sizeof(Profissional),back);
		}
		else{
			clear();
			printTable("desejar trocar o nome:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readName(func.name);
			}else{
			    clearBuffer();
			}
			clear();
			printTable("desejar trocar o Email:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readEmail(func.email);
			}else{
			    clearBuffer();
			}
			clear();
			printTable("desejar trocar o endereco:[S/N]");
			if(getchar() == 'S'){
				clearBuffer();
				readAndreas(func.andreas);
			}else{
			    clearBuffer();
			}
			clear();
			fwrite(&func,1,sizeof(Profissional),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("profissional.dat");
	rename("backprofissional.dat","profissional.dat");
}

void searchProfissional(void){
	FILE *file;
	Profissional func;
	file = fopen("profissional.dat", "rb");
	char name[51];
	readName(name);
	while(fread(&func,sizeof(Profissional),1,file)){
		if(!strcmp(func.name,name)){
			printTable(func.cpf);
			printcomplete("nome:");
			printcomplete(func.name);
			printcomplete("Email:");
			printcomplete(func.email);
			printcomplete("Data de nascimento:");
			printcomplete(func.birth);
			printcomplete("endereco:");
			printcomplete(func.andreas);
			getchar();
		}
	}
	fclose(file);
}

void readProfissional(void){
	FILE *file;
	Profissional func;
	file = fopen("profissional.dat", "rb");
	if(file){
		while (fread(&func, sizeof(Profissional), 1, file)) {
			putchar('\n');
			printTable(func.cpf);
			printcomplete("nome:");
			printcomplete(func.name);
			printcomplete("Email:");
			printcomplete(func.email);
			printcomplete("Data de nascimento:");
			printcomplete(func.birth);
			printcomplete("endereco:");
			printcomplete(func.andreas);
		}
		fclose(file);
	}
}

