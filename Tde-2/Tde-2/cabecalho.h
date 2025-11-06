
#ifndef CABECALHO_H
#define CABECALHO_H

typedef enum {
        PENDENTE,
        CANCELADO,
        CONCLUIDA
}Status;

typedef struct tarefa{
    char nome[50];
    char descricao[1001];
    char dia[11];//DD-MM-AAAA
    char hora[6];//HH:MM
    Status status;

}T;




typedef struct usuario{
    int id;
    int tipo;// 0 comum, 1 admin
    char nome[100];
    char sobrenome[100];
    char email[100];
    char senha[50];
    T tarefas[100];

}U;

void IniciarSistema();

void FazerLogin(char* _email, char* _senha);
void CadastrarUsuario(char* _nome, char* _sobrenome, char* _email, char*_senha);

int ValidarEmail(char* _email);

int ValidarSenha(char* _senha);





#endif // CABECALHO_h
