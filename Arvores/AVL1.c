#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no* dir, *esq;
    int altura;
}No;

typedef struct avl{
    No* raiz;
}AVL;

int preencherDado(){
    printf("Digite o numero\n");
    int dado;
    scanf("%i", &dado);
    getchar();
    return dado;
}

void inserirNo(No* raiz, No* novo){
    if(novo->dado<=raiz->dado){
        if(raiz->esq==NULL){
            raiz->esq = novo;
        }
        else{
            inserirNo(raiz->esq, novo);
        }
    }
    else{
        if(raiz->dir==NULL){
            raiz->dir = novo;
        }
        else{
            inserirNo(raiz->dir, novo);
        }
    }

}



No* novoNo(){
    No* novo = malloc(sizeof(No));
    if(novo){
        novo->dado = preencherDado();
        novo->dir = NULL;
        novo->esq = NULL;
        novo->altura = 0;
        return novo;
    }
    else{
        return NULL;
    }

}


void inserir(AVL* arvore){
    No* novo = novoNo();
    if(novo){
      if(arvore->raiz==NULL){
        arvore->raiz = novo;
        return;
      }
      else{
        inserirNo(arvore->raiz, novo);
      }
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

void buscar(No* raiz, int dado){
    if(raiz==NULL){
        printf("Dado nao encontrado\n");
    }
    else if(raiz->dado==dado){
        printf("Dado encontrado %i\n", raiz->dado);
    }
    else{
        if(dado<=raiz->dado){
            buscar(raiz->esq, dado);
        }
        else{
            buscar(raiz->dir, dado);
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



No* remover(No* raiz, int dado){
    //n achou o no
    if(raiz==NULL){
        printf("Dado nao encontrado\n");
        return NULL;
    }
    //no nao vazio
    else{
        //se achar o no
        if(raiz->dado==dado){
            //remover
            //no folha
            if(raiz->esq==NULL && raiz->dir ==NULL){
                printf("Liberando no: %i\n", raiz->dado);
                free(raiz);
                return NULL;
            }
            //no com pelo menos um filh
            else{
                //no com dois filhos
                if(raiz->esq !=NULL && raiz->dir!=NULL){
                    No* atual = raiz->esq;
                    while(atual->dir!=NULL){
                        atual = atual->dir;
                    }
                    raiz->dado = atual->dado;
                    atual->dado = dado;
                    raiz->esq = remover(raiz->esq, dado);
                    return raiz;
                }
                //no com um filho
                else{
                    No* substituto;
                    if(raiz->esq!=NULL){
                        substituto = raiz->esq;
                    }
                    else{
                        substituto = raiz->dir;
                    }
                    printf("Liberando no: %i\n", raiz->dado);
                    free(raiz);
                    return substituto;
                }
            }
        }
        //continua busca
        else{
            if(dado<= raiz->dado){
                raiz->esq = remover(raiz->esq, dado);
            }
            else{
                raiz->dir = remover(raiz->dir, dado);
            }
        }
    }

}




//                                                       partes da AVL

//retorna a maior subarvore
int maior (int a, int b){
    return(a>b)?a:b;
}

//retorna altura do no
int alturaNo(No* no){
    if(no==NULL){
        return -1;
    }
    else{
        return no->altura;
    }
}

//Fator de balanceamento FTB
int ftb(No* no){
    if(no){
        return (alturaNo(no->esq)- alturaNo(no->dir));
    }
    else{
        return 0;
    }
}

//rotação simples a esquerda(No esta desbalanceado para direita)
No* rotacaoSimplesEsquerda(No* a){
    No* aux1 = a->dir;//Guardadno no c
    No* aux2 = aux1->esq;//Guardando no b

    //Direita de A(raiz desbalanceada) recebe b
    a->dir = aux2;
    //Esquerda de C(filho direito do antigo A) recebe A
    aux1->esq = a;

    //Recalcula altura do no a e do no c
    a->altura = maior(alturaNo(a->esq), alturaNo(a->dir))+1;
    aux1->altura = maior(alturaNo(aux1->esq), alturaNo(aux1->dir))+1;

    //retorna a nova raiz, no caso C
    return aux1;



}

//rotação simples a direita(No esta desbalanceado para esquerda)
No* rotacaoSimplesDireita(No* a){
    No* aux1 = a->esq;
    No* aux2 = aux1->dir;

    aux1->dir = a;
    a->esq = aux2;

    a->altura = maior()
}



int main (){

    int loop=1;
    AVL arvore;
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
                buscar(arvore.raiz, dado);
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


