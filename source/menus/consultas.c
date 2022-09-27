#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void consultasOptions(char op);

void menuConsultas(void){
	char op;
	do{
		clear();
		printTable("               menu consultas");
		printline("  [0]voltar ao menu principal");
		printline("  [1]cadastar consulta ");
		printline("  [2]excluir consulta ");
		printline("  [3]editar consulta ");
		printline("  [4]buscar consulta ");
		printline("  [5]listar consulta ");
		printcomplete(" ");
		scanf("%c",&op);
		clearBuffer();
		clear();
		consultasOptions(op);
	}while(op != '0');
}

void consultasOptions(char op){
	if(op <= '0' || op > 53 ){
		return;
	}
	else if(op == '1'){
		//cadastrar
		printTable("em progesso");
		getchar();
	}
	else if(op == '2'){
		//excluir 
		printTable("em progesso");
		getchar();
	}
	else if(op == '3'){
		//editar 
		printTable("em progesso");
		getchar();
	}
	else if(op == '4'){
		//buscar
		printTable("em progesso");
		getchar();
	}
	else{
		//listar
		printTable("em progesso");
		getchar();
	}
}