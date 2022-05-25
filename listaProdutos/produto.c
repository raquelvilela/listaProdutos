#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

void inicializar(Produto* p[], int tam){
    for(int i=0; i<tam; i++){
        p[i] = NULL;
    }
}

void cadastrar(Produto* p[], int pos){
    p[pos] = (Produto*)malloc(sizeof(struct produto));
    fflush(stdin);
    printf("Digite o codigo do produto: \n");
    scanf("%d", &p[pos]->codigo);
    fflush(stdin);
    printf("Digite a descricao do produto: \n");
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
        printf("Codigo do Produto: %d \n", p[i]->codigo);
        printf("Descricao do Produto: %s \n", p[i]->descricao);
        printf("Fornecedor do Produto: %s \n", p[i]->fornecedor);
        printf("Preco do Produto: %.2lf \n", p[i]->preco);
        printf("\n");
        printf("--------------------------------------\n");
        printf("\n");

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
        //int estoque = p[pos]->quantidadeEstoque;
        double somaCompra = 0.0;
        int resp;
        //do{
           // printf("Caso deseje realizar a compra de outro produdo digite '1', caso nao queira,digite '0'?");
            //scanf("%d", &resp);
            for(int i=0; i<qtdCompra; i++) {
                for(int i=0; i<pos; i++){
                if(proc == p[i]->codigo){
                somaCompra += p[i]->preco;
            }
            p[i]->quantidadeEstoque++;
        }
    }
        //printf("Caso deseje realizar a compra de outro produdo digite '1', caso nao queira,digite '0'?");
        //scanf("%d", &resp);
//}while(resp!=0);

    printf("Valor final da compra: %.2lf \n", somaCompra);
    printf("Valor final do estoque: %.2d \n", p[pos]->quantidadeEstoque);
    printf("\n");
    printf("--------------------------------------\n");
    printf("\n");
}
void vender(Produto* p[], int proc, int pos, int qtdVenda){
        //int estoque = p[pos]->quantidadeEstoque;
        double somaVenda = 0.0;
        for(int i=0; i<qtdVenda; i++) {
            for(int i=0; i<pos; i++){
            if(proc== p[i]->codigo){
            somaVenda += p[i]->preco;

        }
        p[i]->quantidadeEstoque--;
    }
}
    printf("Valor final da venda: %.2lf \n", somaVenda);
    printf("Valor final do estoque: %.2d \n", p[pos]->quantidadeEstoque);
    printf("\n");
    printf("--------------------------------------\n");
    printf("\n");
}

