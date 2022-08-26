#include <stdio.h>
#include <stdlib.h>

char mainMenu(void);


int main(void) {
	char op;
	do{
	op = mainMenu();
	}while(op < 48 || op > 53);
	return 0;
}


char mainMenu(void){
	char op;
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
	return op;
}
