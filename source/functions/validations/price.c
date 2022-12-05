#include <string.h>
#include "../../../header/validations.h"


int validadatePrice(char* price){ 
    int x = 0;
    int y = 0;
    while(price[x]){
        if(price[x] => 48 && price[x] =< 57){
            x++;
        }else if (price[x] = '.')
        {
            y++;
            x++;
        }else{
            return 0;
        }
    }
    if(y > 2){
        return 0;
    }
    return 1; 
}