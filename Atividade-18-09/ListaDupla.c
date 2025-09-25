#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no* prox;
    struct no* ante;
}No;

int lerDado(){
    printf("Digite o dado a ser guardado no no\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;

}

void inserirInicio(No* cabeca){
    No* novo = malloc(sizeof(No));
    novo->dado = lerDado();
    novo->ante=cabeca;
    No* atual = cabeca->prox;

    if(atual==NULL){

        cabeca->prox=novo;
        novo->prox=NULL;

    }
    else{

       atual->ante=novo;
       novo->prox=atual;
       cabeca->prox=novo;
    }



}


void inseriFim(No* cabeca){
    No* novo = malloc(sizeof(No));
    novo->dado=lerDado();
    novo->prox=NULL;
    No* atual = cabeca->prox;
    if(atual==NULL){
        cabeca->prox=novo;
        novo->ante=cabeca;
    }
    else{
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novo;
        novo->ante=atual;
    }

}


void verLista(No* cabeca){
    No* atual = cabeca->prox;
    if(atual==NULL){
        printf("A lista esta vazia\n");
    }
    else{
        int i=1;
        while(atual!=NULL){
            printf("No %i: %i\n", i++, atual->dado);
            atual= atual->prox;
        }
    }

}

int main(){
    No cabeca;
    cabeca.prox=NULL;
    cabeca.ante=NULL;
    int loop=1;

    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - inserir no inicio\n");
        printf("2 - inserir no fim\n");
        printf("3 - ver lista\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        if(acao==1){
            inserirInicio(&cabeca);
        }
        else if(acao==2){
            inseriFim(&cabeca);
        }
        else if(acao==3){
            verLista(&cabeca);
        }


    }


}
