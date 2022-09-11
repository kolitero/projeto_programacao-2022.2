#include <string.h>
#include "../../../header/validations.h"


int validateName(char* name){
    char chars[] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZÁÉÍÓÚÂÊÔÇÀÃÕ.záéíóúâêôçàãõ";
    int tam  = strlen(name);
    int v;
    int charlen = strlen(chars);
    for(int x = 0;x < tam;x++){
        v = 0;
        for(int y = 0;y < charlen;y++){
            if(name[x] == chars[y]){
                v++;
            }
        }
        if(v < 1){
                return 0;
        }
    }
    return 1;
}
