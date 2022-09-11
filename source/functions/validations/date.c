#include <string.h>
#include "../../../header/validations.h"

int validatetime(int month,int day,int year);
int validateDateForm(char* date);

int validateDate(char* date){
    if(!validateDateForm(date)){
        return 0;
    }
    int day = ((int)date[0] - '0')*10 + (int)date[1] - '0';
    int month = ((int)date[3] - '0')*10 + (int)date[4] - '0';
    int year = ((int)date[6] - '0')*1000 +  ((int)date[7] - '0')*100 + ((int)date[8] - '0')*10 + (int)date[9] - '0';
    if(!validatetime(month,day,year)){
        return 0;
    }
    return 1;
}

int bis(int year){
    if(year%4 == 0 && year%100){
        return 1;
    }
    if(year%400 == 0){
        return 1;
    }
    return 0;
}

int validatetime(int month,int day,int year){
    int vyear = bis(year);
    if (month > 0 && month <= 12 && year > 0){
        if (month == 12 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 11 && day > 0 && day <= 30){
            return 1;
        }
        else if(month == 10 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 9 && day > 0 && day <= 30){
            return 1;
        }
        else if(month == 8 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 7 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 6 && day > 0 && day <= 30){
            return 1;
        }
        else if(month == 5 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 4 && day > 0 && day <= 30){
            return 1;
        }
        else if(month == 3 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 2 && day > 0 && day <= 28){
            return 1;
        }
        else if(month == 1 && day > 0 && day <= 31){
            return 1;
        }
        else if(month == 2 && day > 0 && day <= 29 && vyear){
            return 1;
        }
    }
  return 0;
}

int validateDateForm(char* date){
    char digits[] = "0123456789";
    int v;
    if(strlen(date) < 10){
        return 0;
    }
    if(date[2] != '/' || date[5] != '/'){
        return 0;
    }
    for(int x = 0;x < 2;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(date[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    for(int x = 3;x < 5;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(date[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    for(int x = 6;x < 10;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(date[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    return 1;
}