#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no *dir;
    struct no *esq;

}No;

typedef struct bst{
    No* raiz;
}BST;
;


int preencherDado(){
    printf("Digite o numero a ser inserido\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;
}


void inserirNo(No* raizAtual, No* novo){
    if(novo->dado<=raizAtual->dado){
        if(raizAtual->esq==NULL){
            raizAtual->esq = novo;
        }
        else{
            inserirNo(raizAtual->esq, novo);
        }
    }
    else{
        if(raizAtual->dir==NULL){
            raizAtual->dir = novo;
        }
        else{
            inserirNo(raizAtual->dir, novo);
        }
    }

}



void inserir(BST* arvore){
    No* novo = (No*)malloc(sizeof(No));
    novo->dir=NULL;
    novo->esq=NULL;
    novo->dado=preencherDado();

    //Se a arvore estiver vazia
    if(arvore->raiz==NULL){
        arvore->raiz=novo;
        return;
    }
    //Arvore nao esta vazia
    else{
        inserirNo(arvore->raiz, novo);
    }

}

void buscar(No* raizAtual, int dadoBuscado){
    if(raizAtual==NULL){
        printf("O dado buscado não se encontra na arvore\n");
    }
    else if(raizAtual->dado==dadoBuscado){
        printf("Dado encontrado: %i\n", raizAtual->dado);
    }
    else{
        //se for menor ou igual a raiz, procura na subarvore esquerda
        if(dadoBuscado<=raizAtual->dado){
            buscar(raizAtual->esq, dadoBuscado);
        }
        //se for maior, passa subarvore da direita
        else{
            buscar(raizAtual->dir, dadoBuscado);
        }
    }
}

int main(){
    BST arvore;
    arvore.raiz=NULL;
    int loop=1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Inserir um dado\n");
        printf("2 - Buscar um dado\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        if(acao==1){
            inserir(&arvore);
        }
        else if (acao==2){
            printf("Digite o dado que você busca\n");
            int dadoBuscado;
            scanf("%i", &dadoBuscado);
            getchar();
            buscar(arvore.raiz, dadoBuscado);
        }
    }


}
