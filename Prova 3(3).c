typedef struct
{
    int ano;
    int mes;
    int dia;
}tDataNascimento;

typedef struct
{
    char telefone[31];
    char nome[81];
    int codigo;
    float saldoDevedor;
    tDataNascimento dataNascimento;
}tCliente;
