#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"
#include "../../header/cliente.h"


void clientesOptions(char op);

void menuClientes(void){
	char op;
	do{
		clear();
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
		clientesOptions(op);
	}while(op != '0');
}

void clientesOptions(char op){
	if(op <= '0' || op > 53 ){
		return;
	}
	else if(op == '1'){
		//cadastrar cliente
		addCliente();
		getchar();
	}
	else if(op == '2'){
		//excluir cliente
		deleteCliente();
		getchar();
	}
	else if(op == '3'){
		//editar cliente
		editCliente();
		getchar();
	}
	else if(op == '4'){
		//buscar
		searchCliente();
		getchar();
	}
	else{
		//listar
		readCliente();
		getchar();
	}
}