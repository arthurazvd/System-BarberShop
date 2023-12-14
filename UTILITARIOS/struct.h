typedef struct cliente Cliente;

struct cliente{
    char cpf[12];
    char nome[100];
    char tel[12];
    int status;
    Cliente *prox;
};

struct horario{
    char cpf_cli[12];
    char data[11];
    char hora[6];
    char id_preco[10];
};

struct precos{
    char id[10];
    char servico[25];
    char preco[10];
    int status;
};

struct maquinas{
    char id[10];
    char nome[20];
};