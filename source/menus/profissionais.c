#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/menus.h"
#include "../../header/util.h"



//estrutura pra os dados //
//dos profissionais      //

typedef struct{
	char name[81];
	char cpf[15];
	int idade;
}Profissional;

// assinatura das funcoes //

void profissionaisOptions(char op);
void adicionarProfissional(void);
void deleteProfissional(void);
void editProfissional(void);
void readProfissional(void);

void menuProfissionais(void){
	char op;
	do{
    printf(" _______________________________________________ \n");
    printf("|               menu profissionais              |\n");
    printf("|_______________________________________________|\n");
	printf("|    [0]voltar ao menu principal                |\n");
	printf("|    [1]cadastar profissional                   |\n");
	printf("|    [2]excluir profissional                    |\n");
	printf("|    [3]editar profissional                     |\n");
	printf("|    [4]procurar profissional                   |\n");
	printf("|    [5]listar profissionais                    |\n");
	printf("|                                               |\n");
	printf("|                                               |\n");
    printf("|_______________________________________________|\n");
	scanf("%c",&op);
	clearBuffer();
	clear();
	}while(op < 48 || op > 53);
	profissionaisOptions(op);
	
}

void profissionaisOptions(char op){
	if(op == '0'){
		return;
	}
	else if(op == '1'){
		adicionarProfissional();
	}
	else if(op == '2'){
		deleteProfissional();
	}
	else if(op == '3'){
		editProfissional();
	}
	else if(op == '4'){
		//porcurar
	}
	else{
		read();
		getchar();
	}
	menuProfissionais();
}

void adicionarProfissional(void){
	Profissional func;
	char validname;
	scanf("%80[^\n]",func.name);
	clearBuffer();
	printf("%s\n",func.name);
	char validcpf;
	scanf("%14[^\n]",func.cpf);
	clearBuffer();
	printf("%s\n",func.cpf);
	char valididade;
	scanf("%d",&func.idade);
	clearBuffer();
	printf("%d\n",func.idade);
	FILE *file;
	file = fopen("profissional.dat", "ab");
	fwrite(&func, 1, sizeof(Profissional), file);
	fclose(file);
}

void deleteProfissional(void){
	FILE *file,*back;
	Profissional func;
	file = fopen("profissional.dat", "rb");
	back = fopen("backprofissional.dat","ab");
	char nome[81];
	scanf("%80[^\n]", nome);
	clearBuffer();
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
	char nome[81];
	scanf("%80[^\n]", nome);
	clearBuffer();
	while(fread(&func,sizeof(Profissional),1,file)){
		if(strcmp(func.name,nome)){
		fwrite(&func,1,sizeof(Profissional),back);
		}
		else{
			Profissional func;
			char validname;
			scanf("%80[^\n]",func.name);
			clearBuffer();
			printf("%s\n",func.name);
			char validcpf;
			scanf("%14[^\n]",func.cpf);
			clearBuffer();
			printf("%s\n",func.cpf);
			char valididade;
			scanf("%d",&func.idade);
			clearBuffer();
			printf("%d\n",func.idade);
			fwrite(&func,1,sizeof(Profissional),back);
		}
	}
	fclose(file);
	fclose(back);
	remove("profissional.dat");
	rename("backprofissional.dat","profissional.dat");
}


void readProfissional(void){
	FILE *file;
	Profissional func;
	file = fopen("profissional.dat", "rb");
	while (1) {
		if (fread(&func, sizeof(Profissional), 1, file)) {
			printf("%s\n", func.name);
			printf("%d\n", func.idade);
			printf("%s\n", func.cpf);
		} else {
			break;
		}
	}
	fclose(file);
}