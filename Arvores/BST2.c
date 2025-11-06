#include<stdlib.h>
#include<stdio.h>

typedef struct no{
    int dado;
    struct no* dir;
    struct no* esq;
    int altura;
}No;

typedef struct bst {
    No* raiz;
}BST;


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
            raizAtual->dir=novo;
        }
        else{
            inserirNo(raizAtual->dir, novo);
        }
    }
}

void imprimir(No* raizAtual){
    printf("Dado: %i\n", raizAtual->dado );
    if(raizAtual->esq!=NULL){
        imprimir(raizAtual->esq);
    }
    if(raizAtual->dir){
        imprimir(raizAtual->dir);
    }
}

int preencherDado(){
    printf("Digite o numero\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;
}

void inserir(BST* arvore){
    No* novo = malloc(sizeof(No));
    novo->dado = preencherDado();
    novo->dir = NULL;
    novo->esq=NULL;

    if(arvore->raiz ==NULL){
        arvore->raiz = novo;
    }
    else{
        inserirNo(arvore->raiz, novo);
    }
}

//busca iterativa

void buscai(No* raizAtual, int dado){
    if(raizAtual==NULL){
        return;
    }
    else{
        No* atual = raizAtual;
        while(atual!=NULL){
            if(atual->dado==dado){
                printf("Dado encontrado: %i\n", atual->dado);
                return;
            }
            else{
                if(dado<=atual->dado){
                    atual=atual->esq;
                }
                else{
                    atual=atual->dir;
                }
            }

        }
        printf("Dado nao encontrado\n");
    }
}


int calcAltura(No* raiz){
    if(raiz==NULL){
        return -1;
    }
    else{
         int esq = calcAltura(raiz->esq);
         int dir = calcAltura(raiz->dir);
         if(esq>dir){
            return esq+1;
         }
         else{
            return dir+1;
         }
    }
}

//Busca recursiva
void buscar(No* raizAtual, int dado){
    if(raizAtual==NULL){
        printf("O dado nao esta na arvore\n");
    }
    else if(raizAtual->dado==dado){
        printf("Dado encontrado: %i\n", raizAtual->dado);
    }
    else{
        if(dado<=raizAtual->dado){
            buscar(raizAtual->esq, dado);
        }
        else{
            buscar(raizAtual->dir, dado);
        }
    }
}

No* remover(No* raiz, int dado){
    if(raiz==NULL){
        printf("Dado nao encontrado\n");
        return NULL;
    }
    else{
        if(raiz->dado == dado){
            //caso no folha
            if(raiz->esq == NULL && raiz->dir ==NULL){
                printf("Removendo no folha: %i\n", raiz->dado);
                free(raiz);
                return NULL;
            }
            else{
                //no com dois filhos
                if(raiz->esq!=NULL && raiz->dir != NULL){
                    No* atual = raiz->esq;
                    while(atual->dir!=NULL){
                        atual = atual->dir;
                    }
                    int aux = atual->dado;
                    atual->dado = raiz->dado;
                    raiz->dado = aux;
                    raiz->esq = remover(raiz->esq, atual->dado);
                    return raiz;

                }
                //no com um filho
                else{
                    No* substituto;
                    if(raiz->esq!=NULL){
                         substituto= raiz->esq;

                    }
                    else{
                        substituto = raiz->dir;
                    }
                    printf("Removendo no com um filho: %i\n",raiz->dado);
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
                printf("A arvore esta vazia\n");
            }
            else{
                int dado = preencherDado();
                buscai(arvore.raiz, dado);
            }

        }
        else if(acao==4){
            int altura = calcAltura(arvore.raiz);
            if(altura==-1){
                printf("Avore esta vazia\n");
            }
            else{
                printf("Altura da arvore: %i\n", altura);
            }
        }
        else if(acao==5){
            int dado = preencherDado();
            remover(arvore.raiz, dado);
        }
    }
}
