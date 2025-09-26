#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//GPT puro aqui pra fazer um temporizador pra simular tempo de execucao
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void esperar(int ms) {
    #ifdef _WIN32
        Sleep(ms);
    #else
        usleep(ms * 1000); // converte ms para microsegundos
    #endif
}
//aqui acaba gpt




typedef struct instrucao{
    char acao[101];
}Inst;


typedef struct no{
   Inst ins;
   struct no* prox;

}No;

Inst lerInstrucao(){
    Inst inst;
    printf("Digite a instrucao que deseja executar\n");
    fgets(inst.acao, sizeof(inst.acao), stdin);
    inst.acao[strcspn(inst.acao,"\n")]='\0';
    return inst;
}

No* empilhar(No* topo){
    No* novo = malloc(sizeof(No));
    novo->ins=lerInstrucao();

    if(topo==NULL){
        novo->prox=NULL;
        return novo;
    }
    else{
        novo->prox=topo;
        return novo;
    }

}

No* desempilhar(No* topo){
    if(topo ==NULL){
        printf("A pilha de funcao esta vazia\n");
        return NULL;
    }
    No* liberar=topo;
    topo=topo->prox;
    free(liberar);

    return topo;

}

void lerTodasInstrucoes(No* topo){
    No* atual = topo;
    if(atual==NULL){
        printf("A pilha de funcao esta vazia\n");
    }
    else{
        printf("Topo ");
        while(atual!=NULL){
            printf("}<- %s ", atual->ins.acao );
            atual=atual->prox;
        }
        printf("<-Primeira funcao\n");
    }


}


void limparPilha(No* topo){
    No* atual = topo;
    if(atual==NULL){
        printf("A pilha esta vazia\n");
    }
    else{
        No* liberar;
        while(atual!=NULL){
            liberar= atual;
            atual=atual->prox;
            free(liberar);
        }
        printf("A pilha foi esvaziada\n");
    }

}

No* executarInstrucoes(No* topo){
    No* atual = topo;
    if(atual==NULL){
        printf("A pilha de funcao esta vazia\n");
        return NULL;
    }
    else{
        No* proximo;
        while(atual!=NULL){
            printf("Executando e liberando: %s \n", atual->ins.acao );
            proximo = atual->prox;
            free(atual);
            esperar(1000);
            atual=proximo;

        }
        printf("Fim da pilha de execucao\n");
        topo =NULL;
        return topo;
    }


}
void buscarFuncao(No* topo){
    printf("Digite exatamente o nome da funcao que voce busca\n");
    char funcaobuscada[51] ;
    fgets(funcaobuscada, sizeof(funcaobuscada), stdin);
    funcaobuscada[strcspn(funcaobuscada,"\n")]='\0';

    if(topo==NULL){
        printf("A pilha esta vazia\n");
    }
    else{
        No* atual = topo;
        while (atual!=NULL && strcmp(funcaobuscada, atual->ins.acao)!=0){
            atual=atual->prox;
        }
        if(atual==NULL){
            printf("A funcao nao esta no escopo\n");
        }
        else{
            printf("Funcao: %s encontrada\n", atual->ins.acao);
        }
    }

}

int main(){
    int loop =1;
    No* topo=NULL;
    printf("-------Simulando chamada de funcao dentro de outra funcao-------\n");
    while(loop){
        printf("--------------------------------------------------------------------------1\n");
        printf("Digite o que deseja fazer\n");
        printf("1 - Adicionar uma nova funcoes\n");
        printf("2 - Remover a ultima funcoes\n");
        printf("3 - Ver todas funcoes\n");
        printf("4 - Buscar uma funcao\n");
        printf("5 - Executar\n");
        printf("0 - Sair\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        if(acao==1){
            topo=empilhar(topo);
        }
        else if(acao==2){
            topo=desempilhar(topo);
        }
        else if(acao==3){
            lerTodasInstrucoes(topo);
        }
        else if(acao==4){
            buscarFuncao(topo);

        }
        else if(acao==5){
            topo = executarInstrucoes(topo);
        }
        else if(acao==0){
            limparPilha(topo);
            loop=0;
        }

    }

}

