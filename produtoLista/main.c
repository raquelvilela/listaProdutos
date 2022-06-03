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
    system("title Lista de Produtos"); //titulo
    system("mode con:cols=60 lines=30"); //redimendionar tamanho
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
        printf("\t\t*****************************");
        printf("\n\t\t***** LISTA DE PRODUTOS *****\n");
        printf("\t\t*****************************\n");
        printf("\t\t1. Cadastrar Produto \n");
        printf("\t\t2. Listar Produtos \n");
        printf("\t\t3. Encontrar Produto \n");
        printf("\t\t4. Comprar Produto \n");
        printf("\t\t5. Vender Produto \n");
        printf("\t\t9. Sair \n\n");
        printf("\t\tDigite sua opção: \n");
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
                printf("\tDigite o código do produto a ser encontrado: \n");
                scanf("%d", &codigoProc);
                encontrar(vet_produto, codigoProc, pos);
                break;

            case 4:
                printf("\tDigite a quantidade do produto que deseja comprar: \n");
                scanf("%d", &qtdCompra);
                printf("\tDigite o código do produto a ser comprado: \n");
                scanf("%d", &codigoProc);
                comprar(vet_produto, codigoProc, pos, qtdCompra);
                break;

            case 5:
                printf("\tDigite a quantidade de itens para vender: \n");
                scanf("%d", &qtdVenda);
                printf("\tDigite o código do produto a ser vendido: \n");
                scanf("%d", &codigoProc);
                vender(vet_produto, codigoProc, pos, qtdVenda);
                break;

            case 9:
                printf("\t\t---Fim do programa ---\n");
                break;
            default:
                 printf("\t\tOpção inválida. \n");
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
    printf("\tDigite o código do produto: \n");
    scanf("%d", &p[pos]->codigo);
    fflush(stdin);
    printf("\tDigite a descrição do produto: \n");
    scanf("%[^\n]", p[pos]->descricao);
    fflush(stdin);
    printf("\tDigite o nome do fornecedor do produto: \n");
    scanf("%[^\n]", p[pos]->fornecedor);
    fflush(stdin);
    printf("\tDigite a quantidade de estoque do produto: \n");
    scanf("%d", &p[pos]->quantidadeEstoque);
    fflush(stdin);
    printf("\tDigite o preço do produto: \n");
    scanf("%lf", &p[pos]->preco);
    printf("\t\t\nRegistro do produto realizado com sucesso \n");
    printf("\n");
}
void listar(Produto* p[], int pos){
    for(int i=0; i<pos; i++){
        printf("\t\tDados do Registro: %d \n", i+1);
        printf("\t\tCódigo do Produto: %d \n", p[i]->codigo);
        printf("\t\tDescrição do Produto: %s \n", p[i]->descricao);
        printf("\t\tFornecedor do Produto: %s \n", p[i]->fornecedor);
        printf("\t\tPreço do Produto: %.2lf \n", p[i]->preco);
        printf("\t\tQuantidade no Estoque: %d\n", p[i]->quantidadeEstoque);
        printf("\n");
        printf("\t\t------------------------------\n");
        printf("\n");
        return;

    }
}
void encontrar(Produto* p[], int proc, int pos){
    for(int i=0; i<pos; i++){
        if(proc== p[i]->codigo){
            printf("\tDados do Registro: %d \n", i+1 );
            printf("\tCódigo do Produto: %d \n", p[i]->codigo);
            printf("\tDescrição do Produto: %s \n", p[i]->descricao);
            printf("\tFornecedor do Produto: %s \n", p[i]->fornecedor);
            printf("\tPreço do Produto: %.2lf \n", p[i]->preco);
            printf("\n");
            printf("\t-------------------------------\n");
            printf("\n");
            return;
        }
    }

    printf("\n\t\tRegistro não encontrado \n\n");
}
void comprar(Produto* p[], int proc, int pos, int qtdCompra){
        for(int i=0; i<pos; i++){
            if(proc == p[i]->codigo){
                p[i]->quantidadeEstoque += qtdCompra;
                printf("\tProduto: %s\n", p[i]->descricao);
                printf("\tValor final da compra: %.2lf \n", p[i]->preco * qtdCompra);
                printf("\tQuantidade final do estoque: %.2d \n", p[i]->quantidadeEstoque);
                printf("\n");
                printf("\t-----------------------------------\n");
                printf("\n");
                return;
             }
        }
        printf("\n\t\tProduto não encontrado\n\n");
}

void vender(Produto* p[], int proc, int pos, int qtdVenda){
        for(int i=0; i<pos; i++){
            if(proc== p[i]->codigo){
                if(qtdVenda > p[i] ->quantidadeEstoque){
                    printf("\tQuantidade indisponível no estoque\n");
                    printf("\tQuantidade em estoque: %.2d \n", p[i]->quantidadeEstoque);
                    return;

               }else{
                    p[i]->quantidadeEstoque -= qtdVenda;
                    printf("\tProduto: %s\n", p[i]->descricao);
                    printf("\tValor final da venda: %.2lf \n", (p[i]->preco*0.20 + p[i]->preco) * qtdVenda);
                    printf("\tQuantidade final do estoque: %.2d \n", p[i]->quantidadeEstoque);
                    printf("\n");
                    printf("\t-----------------------------------\n");
                    printf("\n");
                    return;
                    }
            }
        }
        printf("\n\t\tProduto não encontrado\n\n");
}
