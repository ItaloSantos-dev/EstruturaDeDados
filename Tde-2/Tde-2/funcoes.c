#include <stdio.h>
#include <string.h>
#include "cabecalho.h"

void IniciarSistema()
{
    U usuarios [10];
}



int ValidarEmail(char* _email){
    return 1;
}

int ValidarSenha(char* _senha){
    return 1;
}








void FazerLogin (char* _email, char* _senha){
    int validouEmail = ValidarEmail(_email);

    if(validouEmail==1){
        int validouSenha = ValidarSenha(_senha);

        if(validouSenha==1){
            printf("Login feito\n");
        }

        else{
            printf("Senha invalida\n");
        }

    }
    else{
        printf("Email invalido\n");
    }

}
