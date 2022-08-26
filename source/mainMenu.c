#include <stdio.h>
#include <stdlib.h>
#include "../header/mainMenu.h"
#include "../header/util.h"

void mainOptions(char op);

void mainMenu(void){
	char op;
	do{
	printf("---------------------------------------\n");
	printf("|             sig-clinic              |\n");
	printf("|-------------------------------------|\n");
	printf("|  [0]fechar programa                 |\n");
	printf("|  [1]gerenciamento de profissionais  |\n");
	printf("|  [2]gerenciamento de clientes       |\n");
	printf("|  [3]gerenciamento de consultas      |\n");
	printf("|  [4]relatorio de vendas             |\n");
	printf("|  [5]creditos                        |\n");
	printf("|                                     |\n");
	printf("|                                     |\n");
	printf("---------------------------------------\n");
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
		//[1]gerenciamento de profissionais
	}
	else if(op == '2'){
		//[2]gerenciamento de clientes
	}
	else if(op == '3'){
		//[3]gerenciamento de consultas
	}
	else if(op == '4'){
		//[4]relatorio de vendas
	}
	else{
		//[5]creditos   
	}
}