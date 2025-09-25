#include<stdio.h>
#include<stdlib.h>

typedef struct pilha {
    int dados[10];
    int topo;
}Pilha;

int lerDado(){
    printf("Digite o dado a ser guardado na pilha\n");
    int dado;
    scanf("%d", &dado);
    return dado;

}


void inserir(Pilha* pilha){

    if(pilha->topo>=10){
        printf("A pilha esta cheia\n");

    }
    else{
        pilha->topo++;
        pilha->dados[pilha->topo]=lerDado();
    }

}

void retirar(Pilha* pilha){
    if(pilha->topo==-1){
        printf("A pilha esta vazia\n");

    }
    else{
        int valor = pilha->dados[pilha->topo];
        pilha->topo--;
        printf("O elemento %i foi retirado\n", valor);
    }
}



void verPilha(Pilha* pilha){
    if(pilha->topo==-1){
        printf("A pilha esta vazia\n");
    }
    else{
        for (int i=pilha->topo; i>=0; i--){
            printf("Dado %i: %i\n", i, pilha->dados[i]);
        }

    }

}

void verseVazia(Pilha* pilha){
    if(pilha->topo==-1){
        printf("A pilha esta vazia\n");
    }
    else{
        printf("A pilha nao esta vazia\n");
    }
}

void verseCheia(Pilha* pilha){
    if(pilha->topo==9){
        printf("A pilha esta cheia\n");
    }
    else{
        printf("A pilha nao esta cheia\n");
    }
}

int main(){
    Pilha pilha;
    pilha.topo=-1;
    int loop=1;

    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - inserir\n");
        printf("2 - retirar\n");
        printf("3 - ver pilha \n");
        printf("4 - ver se pilha esta vazia \n");
        printf("5 - ver se pilha esta cheia \n");
        int acao;
        scanf("%i", &acao);
        if(acao==1){
            inserir(&pilha);
        }
        else if(acao==2){
            retirar(&pilha);
        }
        else if(acao==3){
            verPilha(&pilha);
        }
        else if(acao==4){
            verseVazia(&pilha);
        }
        else if(acao==5){
            verseCheia(&pilha);
        }

    }
}
