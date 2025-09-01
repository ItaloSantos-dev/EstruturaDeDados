#include<stdio.h>
#include<stdlib.h>
//criando a struct funcionario
typedef struct funcionario{
    char nome[11];
    int idade;
    float peso;
}Func;

//estrutura de um nó (dados e ponteiro para o próximo no)
typedef struct no{
    Func f;
    struct no *proximo;
}No;

//função que preenche os dados de um funcionario
Func ler_func (){
    Func f;
    printf("Digite o nome do funcionario\n");
    scanf("%s", f.nome);
    getchar();
    printf("Digite a idade do funcionario\n");
    scanf("%i",&f.idade );
    getchar();
    printf("Digite o peso do funcionario 'xxx,xx'\n");
    scanf("%f", &f.peso);
    getchar();
    return f;

}

//criando a função PUSH
No *empilhar (No *topo){
    //alocar memoria
    No *novo = malloc(sizeof(No));
    if( novo){
        //mudando atributos
        novo->f = ler_func();
        novo->proximo=topo;
        return novo;
    }
    else{
        printf("Erro na alocação");
        return NULL;
    }




}
int main(){
    //quando a pilha está vazia o topo é nulo
    No *topo = NULL;
    //menu
    int loop=1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - PUSH\n");
        printf("2 - POP\n");
        printf("3 - IMPRIMIR\n");
        printf("0 - SAIR\n");
        int dec;
        scanf("%i", &dec);
        getchar();

        if(dec==1){
            topo = empilhar(topo);
        }
    }


}
