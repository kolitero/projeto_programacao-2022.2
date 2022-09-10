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
	printTable("             menu profissionais");
	printline("  [0]voltar ao menu principal");
	printline("  [1]cadastar profissional ");
	printline("  [2]excluir profissional ");
	printline("  [3]editar profissiona; ");
	printline("  [4]buscar profissional ");
	printline("  [5]listar profissionais ");
	printcomplete(" ");
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

