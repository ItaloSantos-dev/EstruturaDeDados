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



int preencherDado(){
    printf("Digite o numero a ser inserido\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;
}





void imprimir(No* raizAtual){
    if(raizAtual==NULL){
        printf("Arvore esta vazia\n");
    }
    else{
        printf("Dado: %i\n", raizAtual->dado);
        if(raizAtual->esq!=NULL){
            imprimir(raizAtual->esq);
        }
        if(raizAtual->dir!=NULL){
            imprimir(raizAtual->dir);
        }
    }

}



void inserirNo(No* raizatual, No* novo){
    if(novo->dado<=raizatual->dado){
        if(raizatual->esq==NULL){
            raizatual->esq = novo;
        }
        else{
            inserirNo(raizatual->esq, novo);
        }
    }
    else{
        if(raizatual->dir==NULL){
            raizatual->dir=novo;
        }
        else{
            inserirNo(raizatual->dir, novo);
        }
    }

}


void inserir(BST* arvore){
    No* novo = malloc(sizeof(No));
    novo->dado = preencherDado();
    novo->dir = NULL;
    novo->esq = NULL;
    if(arvore->raiz==NULL){
        arvore->raiz = novo;
    }
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

/*void remover(No* raizAtual, int dado){
    if(raizAtual==NULL){
        printf("O dado a ser removido não existe na arvore\n");
    }
    else if(raizAtual->dado==dado){
        //Se o no a ser removido nao tiver filhos
        if(raizAtual->esq==NULL && raizAtual->dir==NULL){
            free(raizAtual);
        }
        else{
            //Se tiver filho esq
        }
    }
}*/



int main(){
    BST arvore;
    arvore.raiz=NULL;
    int loop=1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Inserir um dado\n");
        printf("2 - Buscar um dado\n");
        printf("3 - Imprimir arvore\n");
        printf("4 - Remover um nó\n");
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
        else if(acao==3){
            imprimir(arvore.raiz);
        }
        else if (acao==4){
            printf("Digite qual dado deseja remover da arvore\n");
            /*int dadoRemover;
            scanf("%i", &dadoRemover);
            getchar();
            remover(arvore.raiz, dadoRemover);*/

        }
    }


}
