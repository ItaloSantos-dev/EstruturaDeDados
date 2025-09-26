#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//GPT puro aqui pra fazer um temporizador pra simular tocando  uma música
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

//Sistema de playlist de música que so toca para frente

typedef struct musica{
    char nome[51];
    char autor[21];
    char genero[21];
    int ano_lancamento;
}Musica;

typedef struct no {
    Musica mu;
    struct no* prox;
}No;


void limparPlaylist(No* cabeca){
    No* atual = cabeca->prox;
    No* apagar;
    while(atual!=NULL){
        apagar=atual;
        atual=atual->prox;
        free(apagar);
    }
    cabeca->prox=NULL;
}

void addMusicParaTeste(No* cabeca){
    limparPlaylist(cabeca);
    No* m5 = (No*) malloc(sizeof(No));
    m5->prox = NULL;
    strcpy(m5->mu.nome, "Tocando em Frente");
    strcpy(m5->mu.autor, "Almir Sater & Renato Teixeira");
    strcpy(m5->mu.genero, "Sertaneja");
    m5->mu.ano_lancamento = 1990;

    No* m4 = (No*) malloc(sizeof(No));
    m4->prox = m5;
    strcpy(m4->mu.nome, "Calice");
    strcpy(m4->mu.autor, "Chico Buarque & Gilberto Gil");
    strcpy(m4->mu.genero, "Protesto");
    m4->mu.ano_lancamento = 1973;

    No* m3 = (No*) malloc(sizeof(No));
    m3->prox = m4;
    strcpy(m3->mu.nome, "Sampa");
    strcpy(m3->mu.autor, "Caetano Veloso");
    strcpy(m3->mu.genero, "Urbana");
    m3->mu.ano_lancamento = 1978;

    No* m2 = (No*) malloc(sizeof(No));
    m2->prox = m3;
    strcpy(m2->mu.nome, "Aquarela");
    strcpy(m2->mu.autor, "Toquinho");
    strcpy(m2->mu.genero, "Poetica");
    m2->mu.ano_lancamento = 1983;

    No* m1 = (No*) malloc(sizeof(No));
    m1->prox = m2;
    strcpy(m1->mu.nome, "O Leaozinho");
    strcpy(m1->mu.autor, "Caetano Veloso");
    strcpy(m1->mu.genero, "Romantica");
    m1->mu.ano_lancamento = 1977;

    cabeca->prox=m1;

}




//Dados da musica
Musica lerMusica(){
    Musica m;
    printf("Digite o nome da musica\n");
    fgets(m.nome, sizeof(m.nome), stdin);
    m.nome[strcspn(m.nome, "\n")]='\0';
    printf("Digite o nome do autor da musica\n");
    fgets(m.autor, sizeof(m.autor), stdin);
    m.autor[strcspn(m.autor, "\n")]='\0';
    printf("Digite o genero da musica\n");
    fgets(m.genero, sizeof(m.genero), stdin);
    m.genero[strcspn(m.genero, "\n")]='\0';
    printf("Digite o ano da musica\n");
    scanf("%i", &m.ano_lancamento);
    getchar();
    return m;

}


//Adicionando a musica no final da playlist
void addMusica(No* cabeca){
    No* novo = malloc(sizeof(No));
    novo->mu=lerMusica();
    novo->prox=NULL;

    //adicionando no final
    No* atual = cabeca;
    while(atual->prox!=NULL){
        atual=atual->prox;
    }
    //o prox do ultimo ano apontando para o novo no
    atual->prox=novo;

    printf("Musica adicionada na playlist com sucesso\n");

}

//Removendo a ultima musica
void removerMusica(No* cabeca){
    No* atual = cabeca->prox;
    No* antecessor;
    if(atual==NULL){
        printf("A playlist esta vazia\n");
    }
    else if(atual->prox==NULL){
        cabeca->prox=NULL;
        free(atual);
        printf("Musica removida com sucesso, a playlist agora esta vazia\n");
    }
    else{
        while(atual->prox!=NULL){
            antecessor = atual;
            atual=atual->prox;
        }
        antecessor->prox= NULL;
        free(atual);
        printf("Musica removida com sucesso\n");

    }





}

//Remover uma música com base no nome
void RemoverUmaMusica(No *cabeca){
    No* atual = cabeca->prox;
    if(atual==NULL){
        printf("A playlist esta vazia\n");
    }
    else{
        printf("Digite o nome da musica que voce deseja remover\n");
        char musicaBuscada[51];
        fgets(musicaBuscada, (sizeof(musicaBuscada)), stdin);
        musicaBuscada[strcspn(musicaBuscada, "\n")] = '\0';

        No* antecessor = cabeca;
        while(atual!=NULL && strcmp(musicaBuscada, atual->mu.nome)!=0){
            antecessor=atual;
            atual =atual->prox;
        }
        if(atual==NULL){
            printf("A musica buscada nao foi encontrada\n");
            }
        else{
            if(atual->prox==NULL){
                free(atual);
                antecessor->prox=NULL;
                printf("Musica removida com sucesso, a playlist agora esta vazia\n");

            }
            else{
                antecessor->prox=atual->prox;
                free(atual);
                printf("Musica removida com sucesso\n");
            }

        }
    }




}

void tocarTodasMusicas(No *cabeca){
    No* atual = cabeca->prox;
    if(atual==NULL){
        printf("A lista esta vazia\n");
    }
    else{
        while(atual!=NULL){
            printf("------------------------\n");
            printf("Tocando: %s\n", atual->mu.nome);
            printf("Autor: %s\n", atual->mu.autor);
            printf("------------------------\n");
            esperar(2000);

            atual=atual->prox;
        }

    }
}

int main(){
    No cabeca;
    cabeca.prox=NULL;
    int loop = 1;
    while(loop){
        printf("------------------------\n");
        printf("Digite o que deseja fazer\n");
        printf("1 - Adicionar uma musica\n");
        printf("2 - Remover a ultima musica\n");
        printf("3 - Tocar todas as musicas\n");
        printf("4 - Remover musica\n");
        printf("5 - Limpar playlist\n");
        printf("6 - Adicionar musicas Teste\n");
        printf("0 - Sair\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        printf("------------------------\n");
        if(acao==1){
            addMusica(&cabeca);
        }
        else if(acao==2){
            removerMusica(&cabeca);
        }
        else if(acao==3){
            tocarTodasMusicas(&cabeca);
        }
        else if(acao==4){
            RemoverUmaMusica(&cabeca);
        }
        else if(acao==5){
            limparPlaylist(&cabeca);
            printf("A playlist foi limpa\n");
        }
        else if(acao==6){
            addMusicParaTeste(&cabeca);
        }
        else if(acao==0){
            limparPlaylist(&cabeca);
            loop=0;
        }


    }



}
