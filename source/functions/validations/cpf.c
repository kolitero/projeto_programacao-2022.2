#include <string.h>
#include "../../../header/validations.h"

int validateCPFform(char* cpf);
int CPFdigit1(char* cpf);
int CPFdigit2(char* cpf);

int validateCPF(char* cpf){
    if(!validateCPFform(cpf)){
        return 0;
    }
    if(!CPFdigit1(cpf)){
        return 0;
    }
    if(!CPFdigit2(cpf)){
        return 0;
    }
    return 1;
}

int validateCPFform(char* cpf){
    char digits[] = "0123456789";
    int v;
    if(strlen(cpf) < 14){
        return 0;
    }
    if(cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
        return 0;
    }
    for(int x = 0;x < 3;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(cpf[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    for(int x = 4;x < 7;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(cpf[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    for(int x = 8;x < 11;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(cpf[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    for(int x = 12;x < 14;x++){
        v = 0; 
        for(int y = 0;y < 10;y++){
            if(cpf[x] == digits[y]){
                v++;
            }
        }
        if(!v){
            return 0;
        }
    }
    return 1;
}

int CPFdigit1(char* cpf){
    int numcpf[] = {
        (int)cpf[0]-'0',(int)cpf[1]-'0',(int)cpf[2]-'0',(int)cpf[4] - '0',
        (int)cpf[5]-'0',(int)cpf[6]-'0',(int)cpf[8]-'0',(int)cpf[9] - '0',
        (int)cpf[10]-'0',(int)cpf[12]-'0',
    };
    int y = 10;
    int digit1 = 0;
    for(int x = 0; x < 9;x++){
        digit1 += (numcpf[x]*y);
        y--;
    }
    digit1 = digit1*10 % 11;
    if(digit1 == 10){
        digit1 = 0;
    }
    if(digit1 == numcpf[9]){
        return 1;
    }
    return 0;
}

int CPFdigit2(char* cpf){
    int numcpf[] = {
        (int)cpf[0]-'0',(int)cpf[1]-'0',(int)cpf[2]-'0',(int)cpf[4] - '0',
        (int)cpf[5]-'0',(int)cpf[6]-'0',(int)cpf[8]-'0',(int)cpf[9] - '0',
        (int)cpf[10]-'0',(int)cpf[12]-'0',(int)cpf[13]-'0'
    };
    int y = 11;
    int digit2 = 0;
    for(int x = 0; x < 10;x++){
        digit2 += (numcpf[x]*y);
        y--;
    }
    digit2 = digit2*10 % 11;
    if(digit2 == 10){
        digit2 = 0;
    }
    if(digit2 == numcpf[10]){
        return 1;
    }
    return 0;
}