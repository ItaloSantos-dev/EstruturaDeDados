#include<stdio.h>
#include<stdlib.h>
#include "cabecalho.h"


int main(){
    int loop = 1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Fazer login\n");
        printf("2 - Cadastrar-se\n");
        printf("3 - Sair\n");
        int opcao;
        scanf("%i", &opcao);
        getchar();
        if(opcao==1){
            char* email = "Italo";
            char* senha = "1131";
            FazerLogin(email, senha);
            printf("Fazer login\n");

        }
        else if(opcao==2){
            printf("Cadastrar-se\n");
        }
        else if (opcao==3){
            printf("Saindo....\n");
            loop=0;
        }
        else{
            printf("Digite uma opcao valida\n");
        }
    }

}
