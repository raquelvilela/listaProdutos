#include <stdio.h>
#include <stdlib.h>
#define T 500
#include <locale.h>

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


int main()
{

    setlocale(LC_ALL, "ptb");
    system ("color 1F");

    int opc = 0;
    int resp = 0;
    int qtdCompra = 0;
    int qtdVenda = 0;
    int pos = 0;
    int codigoProc = 0;
    Produto* vet_produto[T];
    inicializar(vet_produto, T);

    do{
        fflush(stdin);
        printf("Lista de Produtos \n");
        printf("-------------------- \n");
        printf("1. Cadastrar Produto \n");
        printf("2. Listar Produto \n");
        printf("3. Encontrar Produto \n");
        printf("4. Comprar Produto \n");
        printf("5. Vender Produto \n");
        printf("9. Sair \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opc);
        switch(opc){

            case 1:
                cadastrar(vet_produto, pos);
                pos++;
                break;

            case 2:
                listar(vet_produto, pos);
                break;

            case 3:
                printf("Digite o código do produto a ser encontrado: \n");
                scanf("%d", &codigoProc);
                encontrar(vet_produto, codigoProc, pos);
                break;

            case 4:
                printf("Digite a quantidade do produto que deseja comprar: \n");
                scanf("%d", &qtdCompra);
                printf("Digite o código do produto a ser comprado: \n");
                scanf("%d", &codigoProc);
                comprar(vet_produto, codigoProc, pos, qtdCompra);
                break;

            case 5:
                    printf("Digite a quantidade de itens para vender: \n");
                    scanf("%d", &qtdVenda);
                    printf("Digite o código do produto a ser vendido: \n");
                    scanf("%d", &codigoProc);
                    vender(vet_produto, codigoProc, pos, qtdVenda);
                break;

            case 9:
                printf("Fim do programa \n");
                break;
            default:
                printf("Opção inválida \n");
        }
        system("pause");
        system("cls");
    }while(opc!=9);
    return 0;
}



void inicializar(Produto* p[], int tam){
    for(int i=0; i<tam; i++){
        p[i] = NULL;
    }
}
void cadastrar(Produto* p[], int pos){
    p[pos] = (Produto*)malloc(sizeof(struct produto));
    fflush(stdin);
    printf("Digite o código do produto: \n");
    scanf("%d", &p[pos]->codigo);
    fflush(stdin);
    printf("Digite a descrição do produto: \n");
    scanf("%[^\n]", p[pos]->descricao);
    fflush(stdin);
    printf("Digite o nome do fornecedor do produto: \n");
    scanf("%[^\n]", p[pos]->fornecedor);
    fflush(stdin);
    printf("Digite a quantidade de estoque do produto: \n");
    scanf("%d", &p[pos]->quantidadeEstoque);
    fflush(stdin);
    printf("Digite o preco do produto: \n");
    scanf("%lf", &p[pos]->preco);
    printf("Registro do produto realizado com sucesso \n");
    printf("\n");
}
void listar(Produto* p[], int pos){
    for(int i=0; i<pos; i++){
        printf("Dados do Registro: %d \n", i+1 );
        printf("Código do Produto: %d \n", p[i]->codigo);
        printf("Descrição do Produto: %s \n", p[i]->descricao);
        printf("Fornecedor do Produto: %s \n", p[i]->fornecedor);
        printf("Preco do Produto: %.2lf \n", p[i]->preco);
        printf("Quantidade no Estoque: %d\n", p[i]->quantidadeEstoque);
        printf("\n");
        printf("--------------------------------------\n");
        printf("\n");
        return;

    }
}
void encontrar(Produto* p[], int proc, int pos){
    for(int i=0; i<pos; i++){
        if(proc== p[i]->codigo){
            printf("Dados do Registro: %d \n", i+1 );
            printf("Codigo do Produto: %d \n", p[i]->codigo);
            printf("Descricao do Produto: %s \n", p[i]->descricao);
            printf("Fornecedor do Produto: %s \n", p[i]->fornecedor);
            printf("Preco do Produto: %.2lf \n", p[i]->preco);
            printf("\n");
            printf("--------------------------------------\n");
            printf("\n");
            return;
        }
    }
    printf("Registro não encontrado \n");
}
void comprar(Produto* p[], int proc, int pos, int qtdCompra){
        for(int i=0; i<pos; i++){
            if(proc == p[i]->codigo){
                p[i]->quantidadeEstoque += qtdCompra;
                printf("Produto: %s\n", p[i]->descricao);
                printf("Valor final da compra: %.2lf \n", p[i]->preco * qtdCompra);
                printf("Valor final do estoque: %.2d \n", p[i]->quantidadeEstoque);

                printf("\n");
                printf("--------------------------------------\n");
                printf("\n");
                return;
             }
        }
        printf("Produto nao encontrado\n");
}

void vender(Produto* p[], int proc, int pos, int qtdVenda){
        for(int i=0; i<pos; i++){
            if(proc== p[i]->codigo){
                if(qtdVenda >= p[i] ->quantidadeEstoque){
                    printf("Quantidade indisponível no estoque\n");
                    printf("Quantidade em estoque: %.2d \n", p[i]->quantidadeEstoque);
                    return;

           }else{
                 p[i]->quantidadeEstoque -= qtdVenda;
                 printf("Produto: %s\n", p[i]->descricao);
                 printf("Valor final da venda: %.2lf \n", (p[i]->preco*0.20 + p[i]->preco) * qtdVenda);
                 printf("Valor final do estoque: %.2d \n", p[i]->quantidadeEstoque);

                 printf("\n");
                 printf("--------------------------------------\n");
                 printf("\n");
                 return;
                }
            }
        }
        printf("Produto não encontrado\n");
}
