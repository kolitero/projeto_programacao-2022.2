#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"




void rendimnetoOptions(char op);

void menuRendimento(void){
	char op;
	do{
		clear();
		printTable("             menu profissionais");
		printline("  [0]voltar ao menu principal");
		printline("  [1]relatorio por data");
		printline("  [2]relatorio por cliente ");
		printline("  [3]relaotrio por profissional");
		printcomplete(" ");
		scanf("%c",&op);
		clearBuffer();
		clear();
		rendimnetoOptions(op);
	}while(op < 48 || op > 51);
	
}

void rendimnetoOptions(char op){
	if(op <= 48 || op > 51){
		return;
	}
	else if(op == '1'){
		printTable("em progesso");
		getchar();
	}
	else if(op == '2'){
		printTable("em progesso");
		getchar();
	}
	else{
		printTable("em progesso");
		getchar();
	}
}
