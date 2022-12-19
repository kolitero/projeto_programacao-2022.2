#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"
#include "../../header/rendimento.h"


void rendimnetoOptions(char op);

void menuRendimento(void){
	char op;
	do{
		clear();
		printTable("             menu relatorio");
		printline("  [0]voltar ao menu principal");
		printline("  [1]relatorio por cliente ");
		printline("  [2]relaotrio por profissional");
		printcomplete(" ");
		scanf("%c",&op);
		clearBuffer();
		clear();
		rendimnetoOptions(op);
	}while(op < 48 || op > 50);
	
}

void rendimnetoOptions(char op){
	if(op <= 48 || op > 50){
		return;
	}
	else if(op == '1'){
		rendimentocliente();
		getchar();
	}
	else{
		rendimentomedico();
		getchar();
	}
}
