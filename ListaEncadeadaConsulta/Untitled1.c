#include<stdio.h>
#include<stdlib.h>

typedef struct consulta{
    char nome_med[21];
    char nome_pac[21];
    char hora[6]; //00-23
    char data[11];//xx-xx-xxxx


}Consulta;

Consulta cadastrar_consulta (){
    Consulta consul;
    printf("Digite o nome do medico\n");
    scanf("%s", consul.nome_med);
    getchar();
    printf("Digite o nome do paciente\n");
    scanf("%s", consul.nome_pac);
    getchar();
    printf("Digite a hora do atendimento\n");
    scanf("%s", consul.hora);
    getchar();
    printf("Digite data do atendimento\n");
    scanf("%s", consul.data);
    getchar();
    return consul;




}

typedef struct no{
    Consulta consul;
    struct no *proximo;

}No;

No *addlista(No *ultimo){
    No* novo = malloc(1*sizeof(No));
    if (novo){
        novo->consul = cadastrar_consulta();
        novo -> proximo = ultimo;
        return novo;
    }
    else{
        printf("Deu ruin");
    }



}



int main(){
    No *ultimo= NULL;
    int loop =1;

    while(loop){
        printf("Deseja adicionar um novo cadastro de consulta? 1 | 0");
        int acao;
        scanf("%i", &acao);
        if(acao){
            ultimo = addlista(ultimo);
        }
        else{
            No *atual = ultimo;
            No *temp;

            while(atual != NULL){
                temp = atual;
                atual = atual->proximo;
                free(temp);
                }
            loop=0;


        }
    }






