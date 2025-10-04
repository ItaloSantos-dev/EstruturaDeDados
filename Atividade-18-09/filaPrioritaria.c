#include <stdlib.h>n
#include<stdio.h>


typedef struct no{
    int dado;
    struct no* prox;
    int p;//prioridade, 1, 2 ou 3
}No;

int preencherdado(){
    printf("Digite o dado do novo no\n");
    int novoDado;
    scanf("%i", &novoDado);
    getchar();
    return novoDado;
}

int prioridade(){
    printf("Digite a prioridade do novo no\n");
    int prioridade;
    scanf("%i", &prioridade);
    getchar();
    while(prioridade>3 || prioridade<1){
        printf("Digite um numero valido\n");
        scanf("%i", &prioridade);
        getchar();
    }
    return prioridade;
}

void enfileirar(No* cabeca){
    No* novo = malloc(sizeof(No));
    novo->dado = preencherdado();
    novo->p = prioridade();
    No* atual = cabeca->prox;
    if(atual==NULL){//lista vazia
        novo->prox=NULL;
        cabeca->prox=novo;
    }
    else{
        No* ant = cabeca;
        while(novo->p>atual->p){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = novo;
        novo->prox=atual;
    }

}

void desenfileirar(No* cabeca){
    No* atual = cabeca->prox;
    if(atual==NULL){//Lista vazia
        printf("A lista esta vazia\n");
    }
    else{
        cabeca->prox = atual->prox;
        printf("Desenfileirando: %i\n", atual->dado);
        free(atual);
    }
}

void mostrar(No* cabeca){
    No* atual = cabeca->prox;
    if(atual==NULL){
        printf("A lista esta vazia\n");
    }
    else{
        while(atual!=NULL){
            printf("Dado: %i; Prioridade: %i\n", atual->dado, atual->p);
            atual=atual->prox;
        }
    }

}


int main(){
    int loop =1;
    No cabeca;
    cabeca.prox = NULL;
    while (loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Mostrar fila\n");
        int acao;
        scanf("%i", &acao);
        getchar();

        if (acao==1){
            enfileirar(&cabeca);
        }
        else if (acao==2){
            desenfileirar(&cabeca);
        }
        else if (acao==3){
            mostrar(&cabeca);
        }

    }

}
