#include <string.h>
#include "../../../header/validations.h"


int validateName(char* name){
    int x = 0;
    while(name[x]){
        x++;
        if(name[x] == -61){
            if (name[x++] < -69){
                x++;
            }
        } 
        else if((name[x] >= 65 && name[x] <= 90) || (name[x] >= 97 && name[x] <= 122) || name[x] == 32){
            x++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
