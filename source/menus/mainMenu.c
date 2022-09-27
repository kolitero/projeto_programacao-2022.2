#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void mainOptions(char op);

void mainMenu(void){
	char op;
	clear();
	do{
		printTable("                    sig-clinic");
		printline("  [0]fechar programa");
		printline("  [1]gerenciamento de profissionais");
		printline("  [2]gerenciamento de clientes ");
		printline("  [3]gerenciamento de consultas");
		printline("  [4]relatorio de vendas");
		printline("  [5]creditos");
		printline(" ");
		printcomplete(" ");
		scanf("%c",&op);
		clearBuffer();
		clear();
		mainOptions(op);
	}while(op != '0');
}

void mainOptions(char op){
	if(op <= '0' || op > 53){
		return;
	}
	else if(op == '1'){
		menuProfissionais();
	}
	else if(op == '2'){
		menuClientes();
	}
	else if(op == '3'){
		menuConsultas();
	}
	else if(op == '4'){
		menuRendimento();
	}
	else{
		creditos();
		getchar();
	}
}