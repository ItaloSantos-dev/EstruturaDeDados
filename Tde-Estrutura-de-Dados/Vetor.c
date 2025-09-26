#include<stdio.h>
#include<stdlib.h>

int main(){
    //Bilheteria de um cinema, número de poltornas fixo, 0=disponível|1=ocupado
    int lugaresCinema[25]={0};

    int loop = 1;
    while(loop){
        printf("-----------------------------------\n");
        printf("Digite o que deseja fazer\n");
        printf("1 - Escolher uma poltrona\n");
        printf("2 - ver poltronas \n");
        printf("3 - Ver poltrona especifica\n");
        printf("0 - Sair\n");
        int acao;
        scanf("%i", &acao);
        getchar();
        printf("-----------------------------------\n");
        if(acao==1){
            int loop2 = 1;
            while(loop2){
                printf("Digite qual poltrona voce deseja para assistir o filme | 0-24 \n");
                int poltronaEscolhida;
                scanf("%i", &poltronaEscolhida);
                getchar();
                if(poltronaEscolhida<0 || poltronaEscolhida>24){
                    printf("Digite um numero valido, entre 0 e 24\n");
                }
                else{
                    if(lugaresCinema[poltronaEscolhida]==1){
                        printf(("Desculpe, o assento escolhido esta ocupado, escolha outra poltrona\n"));

                    }
                    else{
                        lugaresCinema[poltronaEscolhida]=1;
                        int linha = poltronaEscolhida/5;
                        char coluna = 'C' +  ((poltronaEscolhida%5)-2);
                        printf("Parabens, seu assento na poltrona %i%c foi guardado com sucesso\n", linha, coluna);
                        loop2=0;

                    }
                }
            }
        }
        else if(acao==2){
                printf("D -> Disponivel\nO -> Ocupado\n");
                printf("  A B C D E\n");
            for (int i =0; i<25; i++){


                if(i%5==0){
                    int linha = i/5;
                    printf("%i ", linha );
                }
                if(lugaresCinema[i]==0){

                        printf("D ");
                    }
                    else{

                        printf("O ");
                    }
                    if((i+1)%5==0){
                        printf("\n");
                    }
            }
            printf("\n");
        }
        else if(acao==3){
            printf("Digite qual poltrona deseja consultar\n");
            int poltronaEscolhida;
            scanf("%i", &poltronaEscolhida);
            getchar();
            if(lugaresCinema[poltronaEscolhida]==1){
                printf("Esta poltrona esta ocupada\n");
            }
            else{
                printf("Essa poltrona esta disponivel\n");
            }

        }
        else if(acao==0){
            loop=0;
        }
    }

}
