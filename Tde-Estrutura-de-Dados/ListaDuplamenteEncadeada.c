#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Simular um navegador

typedef struct pagina{
    char nome[51];

}Pag;

typedef struct no{
    Pag pag;
    struct no* prox;
    struct no* ante;
}No;



No* acessarPag(No* cabeca){
    No* novaPag = malloc(sizeof(No));
    printf("Digite o nome da pagina que voce deseja acessar\n");
    fgets(novaPag->pag.nome, sizeof(novaPag->pag.nome), stdin);
    novaPag->pag.nome[strcspn(novaPag->pag.nome, "\n")]='\0';

    No* atual = cabeca->prox;
    novaPag->prox=NULL;
    if(atual==NULL){
       cabeca->prox=novaPag;
       novaPag->ante=cabeca;
    }
    else{
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novaPag;
        novaPag->ante=atual;
    }
    return novaPag;
}

No* voltarSite(No* pagAtual){
    No* atual = pagAtual;
    if(atual->ante!=NULL){
        atual = atual->ante;
    }

    return atual;
}

No* proxSite(No* pagAtual ){
    No* atual = pagAtual;
    if(atual->prox==NULL){
        printf("Voce ja esta no ultimo site acessado\n");
    }
    else{
        atual = atual->prox;
    }
    return atual;

}

void limparHistorico(No* cabeca){
    No* atual = cabeca->prox;
    while(atual!=NULL){
        No* liberar = atual;
        free(liberar);
        atual = atual->prox;
    }
    printf("Historico apagado\n");
}

No* apagarUltimaPag(No* cabeca){
    No* pagAtual = cabeca;
    No* atual = cabeca->prox;
    if(atual==NULL){
        free(atual);
    }
    else{
        while(atual->prox!=NULL){
            pagAtual = atual;
            atual=atual->prox;
        }

        pagAtual->prox=NULL;
        free(atual);

    }
    return pagAtual;


}

int main(){
    No cabeca;
    cabeca.ante =NULL;
    cabeca.prox=NULL;
    No* pagatual=&cabeca;


    int loop =1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Acessar uma nova pag\n");
        printf("2 - Apagar ultima pagina \n");
        printf("3 - Voltar para pagina anterior\n");
        printf("4 - Avancar para proxima pagina \n");
        printf("0 - Sair \n");
        int acao;
        scanf("%i", &acao);
        getchar();
        if(acao==1){
            pagatual = acessarPag(&cabeca);
            printf("Voce esta na pagina %s\n", pagatual->pag.nome);
            printf("---------------------------------------\n");
        }
        else if(acao==2){
            pagatual = apagarUltimaPag(&cabeca);
            if(pagatual->ante!=NULL){
                printf("Voce esta na pagina %s\n", pagatual->pag.nome);
            }
            else{
                printf("Voce esta no menu principal\n");
            }
            printf("---------------------------------------\n");
        }
        else if(acao==3){
            pagatual=voltarSite(pagatual);
            if(pagatual->ante!=NULL){
                printf("Voce esta na pagina %s\n", pagatual->pag.nome);
            }
            else{
                printf("Voce esta no menu principal\n");
            }
            printf("---------------------------------------\n");
        }
        else if(acao==4){
            pagatual = proxSite(pagatual);
            printf("Voce esta na pagina %s\n", pagatual->pag.nome);
            printf("---------------------------------------\n");
        }
        else if(acao==0){
            limparHistorico(&cabeca);
            loop = 0;
        }
    }



}
