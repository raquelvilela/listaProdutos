struct produto{
    int codigo;
    char descricao[61];
    char fornecedor[61];
    int quantidadeEstoque;
    double preco;
};
typedef struct produto Produto;

void inicializar(Produto* p[], int tam);

void cadastrar(Produto* p[], int pos);

void listar(Produto* p[], int pos);

void encontrar(Produto* p[], int proc, int pos);

void comprar(Produto* p[], int proc, int pos, int qtdCompra);

void vender(Produto* p[], int proc, int pos, int qtdVenda);
