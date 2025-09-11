#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct pessoa{
    char nome[21];
    int idade;
    char sexo;
}Pessoa;



typedef struct no{
    Pessoa p;
    struct no* prox;
}No;

Pessoa cad(){
    Pessoa p;
    printf("Digite o nome\n");
    scanf("%s", p.nome);
    getchar();

    printf("Digite a idade\n");
    scanf("%i", &p.idade);
    getchar();

    printf("Digite o sexo\n");
    scanf("%c", &p.sexo);
    getchar();
    return p;

}

void addnofinal(No *cabeca){
    //criando o novo no
    No* novo = malloc(sizeof(No));
    //preenchendo os dados do novo no
    novo->p = cad();
    novo ->prox=NULL;

    //guarda a posição da cabeca/head
    No* atual = cabeca;

    //itera sobr os nos até achar o no rabo que aponta para null
    while(atual->prox!=NULL){
        atual = atual->prox;
    }
    //o no rabo agora aponta para o novo no, tornando o novo no o no rabo
    atual->prox = novo;
    printf("Cadastro feito com sucesso\n");
}


void apagarPorNome(No* cabeca){
    printf("Digite o nome da pessoa cujo você deseja apagar o cadastro\n");
    char nomeA [21];
    scanf("%s", nomeA);
    getchar();
    //guarda o no que head aponta, ou seja, o primeiro no com dados
    No* atual = cabeca->prox;
    //guarda o no antecessor para que depois ele aponte para o sucessor do no apagado
    No* antecessor = cabeca;
    //itera enquanto o no atual não for null e até achar o nome digitado
    while(atual!=NULL && strcmp(nomeA, atual->p.nome)!=0){
        //guarda o no antecessor
        antecessor = atual;
    //avança para o proximo no
        atual = atual->prox;
        }
    //verifica se ja cehgou ao fim da lista sem achar o nome
    if(atual==NULL){
        printf("Cadastro não encontrado\n");

    }
    //o antecessor do no apagado agora aponta para o sucessor do no no apagado
    antecessor->prox = atual->prox;
    //libera e apaga o no
    free(atual);
    printf("Cadastro excluido com sucesso\n");




}

void imprimirCads(No* cabeca){
    //guar a posicao do primeiro no com dados
    No* atual = cabeca->prox;
    //itera ate a o no cauda
    while(atual!=NULL){
        printf("Nome: %s\n", atual->p.nome);
        printf("Idade: %i\n", atual->p.idade);
        printf("Sexo: %c\n", atual->p.sexo);
        //avanca p proximo no
        atual = atual->prox;
    }


}

void liberandomemoria(No* cabeca){
    //pega o primeiro no com dados
    No* atual = cabeca->prox;
    No* liberar;
    //itera enquanto o no atual tiver dados
    while(atual!=NULL){
        //guarda o no atual
        liberar=atual;
        //guarda o proximo no
        atual = atual->prox;
        //liberar o no guardado
        free(liberar);
    }
    printf("Memoria liberada com sucesso\n");




}

int main(){
    int loop =1;
    No cabeca;
    cabeca.prox=NULL;
    while (loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Cadastrar uma pessoa\n");
        printf("2 - Excluir cadastro\n");
        printf("3 - Imprimir cadastros\n");
        printf("0 - Imprimir cadastros\n");
        int acao;
        scanf("%i", &acao);
        getchar();

        if (acao==1){
            addnofinal(&cabeca);
        }
        else if (acao==2){
            apagarPorNome(&cabeca);
        }
        else if(acao==3){
            imprimirCads(&cabeca);
        }
        else if (acao==0){
            liberandomemoria(&cabeca);
        }

    }


}
