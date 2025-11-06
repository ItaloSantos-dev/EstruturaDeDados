#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    int loop = 1;
    while(loop){
        printf("Deseja fazer login? S/N\n");
        char opcao;
        scanf("%c", &opcao);
        getchar();
        opcao = toupper(opcao);
        if(opcao=='S'){
            printf("Fazer login\n");
        }
        else{
            printf("Saindo....\n");
            loop=0;
        }
    }

}
