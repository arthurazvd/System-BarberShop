struct cliente{
    char cpf[12];
    char nome[100];
    char tel[12];
};

struct horario{
    char cpf_cli[12];
    char data[11];
    char hora[3];
    char minuto[3];
};

struct precos{
    char id[10];
    char servico[25];
    char preco[10];
};

struct maquinas{
    char id[10];
    char nome[20];
};