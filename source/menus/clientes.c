#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void menuClientes(void){
	printTable("               menu clientes");
	printline("  [0]voltar ao menu principal");
	printline("  [1]cadastar cliente ");
	printline("  [2]excluir cliente ");
	printline("  [3]editar cliente ");
	printline("  [4]buscar cliente ");
	printline("  [5]listar cliente ");
	printcomplete(" ");
}