#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void mainOptions(char op);

void mainMenu(void){
	char op;
	do{
	printf(" _______________________________________________ \n");
	printf("|                  sig-clinic                   |\n");
	printf("|_______________________________________________|\n");
	printf("|  [0]fechar programa                           |\n");
	printf("|  [1]gerenciamento de profissionais            |\n");
	printf("|  [2]gerenciamento de clientes                 |\n");
	printf("|  [3]gerenciamento de consultas                |\n");
	printf("|  [4]relatorio de vendas                       |\n");
	printf("|  [5]creditos                                  |\n");
	printf("|                                               |\n");
	printf("|                                               |\n");
	printf("|_______________________________________________|\n");
	scanf("%c",&op);
	clearBuffer();
	clear();
	}while(op < 48 || op > 53);
	mainOptions(op);
}

void mainOptions(char op){
	if(op == '0'){
		return;
	}
	else if(op == '1'){
		menuProfissionais();
	}
	else if(op == '2'){
		menuClientes();
		getchar();
	}
	else if(op == '3'){
		menuConsultas();
		getchar();
	}
	else if(op == '4'){
		rendimento();
		getchar();
	}
	else{
		creditos();
		getchar();
	}
	mainMenu();
}