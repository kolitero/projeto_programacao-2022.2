#include <stdio.h>
#include <stdlib.h>
#include "../header/menus.h"
#include <locale.h>

int main(void) {
	setlocale(LC_ALL,"portuguese");
	mainMenu();
	return 0;
}

