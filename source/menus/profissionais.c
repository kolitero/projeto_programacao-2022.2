#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/menus.h"
#include "../../header/util.h"
#include "../../header/profissional.h"


void profissionaisOptions(char op);

void menuProfissionais(void){
	char op;
	do{
	clear();
	printf(" __________________________________________________ \n");
	printf("|                menu profissionais                |\n");
	printf("|__________________________________________________|\n");
	printf("|    [0]voltar ao menu principal                   |\n");
	printf("|    [1]cadastar profissional                      |\n");
	printf("|    [2]excluir profissional                       |\n");
	printf("|    [3]editar profissional                        |\n");
	printf("|    [4]procurar profissional                      |\n");
	printf("|    [5]listar profissionais                       |\n");
	printf("|                                                  |\n");
	printf("|                                                  |\n");
	printf("|__________________________________________________|\n");
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
		addProfissional();
	}
	else if(op == '2'){
		deleteProfissional();
	}
	else if(op == '3'){
		editProfissional();
	}
	else if(op == '4'){
		searchProfissional();
	}
	else{
		readProfissional();
		getchar();
	}
	menuProfissionais();
}

