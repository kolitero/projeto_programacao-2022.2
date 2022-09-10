#include <string.h>
#include "../../../header/validations.h"


int validateNameChar(char ch);

int validateName(char* name){
    int tam  = strlen(name);
    for(int x = 0;x < tam-1;x++){
        if(!validateName2(name[x])){
            return 0;
        }
    }
    return 1;
}
int validateNameChar(char ch){
    if(ch >= 97 && ch <= 122){
        return 1;
    }
    if(ch >= 65 && ch <= 90){
        return 1;
    }
    if(ch >= 130 && ch <= 153){
        return 1;
    }
    if(ch >= 159 && ch <= 165){
        return 1;
    }
    if(ch == 128 || ch == 157 || ch == 169 || ch == 32){
        return 1;
    }
    return 0;
}