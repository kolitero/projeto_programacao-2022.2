#include <stdio.h>
#include <stdlib.h>
#include "../../header/menus.h"
#include "../../header/util.h"

void menuConsultas(void){
	printTable("               menu consultas");
	printline("  [0]voltar ao menu principal");
	printline("  [1]cadastar consulta ");
	printline("  [2]excluir consulta ");
	printline("  [3]editar consulta ");
	printline("  [4]buscar consulta ");
	printline("  [5]listar consulta ");
	printcomplete(" ");
}