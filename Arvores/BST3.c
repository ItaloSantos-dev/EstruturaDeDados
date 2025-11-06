#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no* dir;
    struct no* esq;
}No;

int preencherDado(){
    printf("Digite o numero\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;
}

typedef struct bst{
    No* raiz;
}BST;

void inserirNo(No* raiz, No* novo){
    if(novo->dado<=raiz->dado){
        if(raiz->esq==NULL){
            raiz->esq=novo;
        }
        else{
            inserirNo(raiz->esq, novo);
        }
    }
    else{
        if(raiz->dir==NULL){
            raiz->dir=novo;
        }
        else{
            inserirNo(raiz->dir, novo);
        }
    }

}

//Inserir Recursivo
void inserir(BST* arvore){
    No* novo = malloc(sizeof(No));
    novo->dado = preencherDado();
    novo->dir = NULL;
    novo->esq = NULL;
    if(arvore->raiz==NULL){
        arvore->raiz = novo;
        return;
    }
    else{
        inserirNo(arvore->raiz, novo);
    }
}
void imprimir(No* raiz){
    printf("Dado: %i\n", raiz->dado);
    if(raiz->esq!=NULL){
        imprimir(raiz->esq);
    }
    if(raiz->dir!=NULL){
        imprimir(raiz->dir);
    }
}

void busca(No* raiz, int dado){
    if(raiz==NULL){
        printf("Dado nao encontrado\n");
    }
    else if(raiz->dado==dado){
        printf("Dado encontrado: %i\n", raiz->dado);
    }
    else{
        if (dado<=raiz->dado){
            busca(raiz->esq, dado);
        }
        else{
            busca(raiz->dir, dado);
        }
    }
}

int calcAltura(No* raiz){
    if(raiz==NULL){
        return -1;
    }
    else{
        int dir = calcAltura(raiz->dir);
        int esq = calcAltura(raiz->esq);
        if(esq>dir){
            return esq +1;
        }
        else{
            return dir +1;
        }
    }
}

No* remover(No*raiz, int dado){
    if(raiz==NULL){
        printf("Dado nao encontrado\n");
    }
    else{
        if(raiz->dado==dado){
            //no sem filho
            if(raiz->dir ==NULL && raiz->esq ==NULL){
                printf("Liberando no: %i\n", raiz->dado);
                free(raiz);
                return NULL;
            }
            //no com filho
            else{
                //no com dois filhos
                if(raiz->esq!=NULL && raiz->dir!=NULL){
                    No* atual = raiz->esq;
                    while(atual->dir!=NULL){
                        atual = atual->dir;
                    }
                    raiz->dado = atual->dado;
                    atual->dado = dado;
                    raiz->esq = remover(raiz->esq,atual->dado);
                    return raiz;
                }
                //no com um filho
                else{
                    No* substituto;
                    //se for na direita
                    if(raiz->dir !=NULL){
                        substituto = raiz->dir;
                    }
                    //se for o da esquerda
                    else{
                        substituto = raiz->esq;
                    }
                    printf("liberando no: %i\n", raiz->dado);
                    free(raiz);
                    return substituto;
                }


            }

        }
        else{
            if(dado<=raiz->dado){
                raiz->esq = remover(raiz->esq, dado);
            }
            else{
                raiz->dir = remover(raiz->dir, dado);
            }
            return raiz;
        }
    }
}

int main(){
    int loop=1;
    BST arvore;
    arvore.raiz=NULL;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Inserir\n");
        printf("2 - Imprimir\n");
        printf("3 - Buscar\n");
        printf("4 - Ver altura\n");
        printf("5 - Remover um no\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        if(acao==1){
            inserir(&arvore);
        }
        else if(acao==2){
            if(arvore.raiz==NULL){
                printf("A arvore esta vazia\n");
            }
            else{
                imprimir(arvore.raiz);
            }
        }
        else if(acao==3){
            if(arvore.raiz==NULL){
                printf("A arvore esta vaazia\n");
            }
            else{
                int dado = preencherDado();
                busca(arvore.raiz, dado);
            }
        }
        else if(acao==4){
            int altura = calcAltura(arvore.raiz);
            if(altura==-1){
                printf("A arvore esta vazia\n");
            }
            else{
                printf("Altura da BST: %i\n", altura);
            }
        }
        else if(acao==5){
            int dado = preencherDado();
            arvore.raiz = remover(arvore.raiz, dado);
        }
    }
}

