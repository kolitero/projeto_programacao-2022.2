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
void excluirProfissional(void);
void excluirProfissional(void);
void deletarProfissional(const char* name);
int lenSizeProfissional(void);

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
		//excluir
	}
	else if(op == '3'){
		//editar
	}
	else if(op == '4'){
		//porcurar
	}
	else{
		//listar
	}
}

void adicionarProfissional(void){
	
}

void excluirProfissional(void){
	
}

void editarProfissional(void){
    
}

void deletarProfissional(const char* name){
	
}

int lenSizeProfissional(void){
    
}