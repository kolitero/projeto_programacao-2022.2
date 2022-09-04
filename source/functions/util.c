#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../header/util.h"



void clear(void){
    system("cls||clear");
}

void clearBuffer(void){
    while((getchar()) != '\n');
}

