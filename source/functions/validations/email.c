#include <string.h>
#include "../../../header/validations.h"


int valid_email(char* email){ 
    int x = 0;
    int valid = 0;
    while(email[x]){
        if(email[x] == '@' && !valid){
            valid++;
        }
        else if(email[x] == '.' && valid > 1){
            valid++;
        }
    }
    if(valid > 1){
        return 1;
    }
    return 0;
}