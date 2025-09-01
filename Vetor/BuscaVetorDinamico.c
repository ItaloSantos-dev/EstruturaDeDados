#include<stdlib.h>
#include<stdio.h>

void empilhar (int *pilha, int *topo){

    printf("Digite o numero a ser adicionado\n");
    int x;
    scanf("%i", &x);
    getchar();

    if(topo!=0){

        pilha = realloc(pilha, (*topo+1)*sizeof(int));
    }
    pilha[*topo]=x;
    (*topo)++;

}

void desempilhar (int *pilha, int *topo){
    (*topo)--;
    pilha = realloc(pilha, *topo*sizeof(int));
    printf("Foi retirado um item da pilha \n");

}

int main(){
    //criando o menu
    int loop=1;
    int *pilha = malloc(1*sizeof(int));
    int topo = 0;
    while(loop){
            printf("----------------------------------------------------------------\n");
        printf("Digite o que deseja executar na pilha\n");
        printf("1 PUSH\n");
        printf("2 POP\n");
        printf("3 EXIBIR\n");
        printf("0 SAIR\n");

        int dec;
        scanf("%i", &dec);
        getchar();

        if(dec==1){
            empilhar(pilha, &topo);
        }
        else if(dec==2){
            desempilhar(pilha, &topo);
        }
        else if(dec==3){
            printf("TOPO: %i\n", topo);
            for(int i=topo-1; i>=0; i--){
                printf("P%i: %i \n",i, pilha[i]);
            }
        }
        else if(dec==0){
            free(pilha);
            loop=0;
        }
    }
}
