#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void clientesOptions(char op);

void menuClientes(void){
	char op;
	do{
		printTable("               menu clientes");
		printline("  [0]voltar ao menu principal");
		printline("  [1]cadastar cliente ");
		printline("  [2]excluir cliente ");
		printline("  [3]editar cliente ");
		printline("  [4]buscar cliente ");
		printline("  [5]listar cliente ");
		printcomplete(" ");
		scanf("%c",&op);
		clearBuffer();
		clear();
	}while(op < 48 || op > 53);
	clientesOptions(op);
}

void clientesOptions(char op){
	if(op == '0'){
		return;
	}
	else if(op == '1'){
		//cadastrar cliente
		printTable("em progesso");
		getchar();
	}
	else if(op == '2'){
		//excluir cliente
		printTable("em progesso");
		getchar();
	}
	else if(op == '3'){
		//editar cliente
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
	menuClientes();
}