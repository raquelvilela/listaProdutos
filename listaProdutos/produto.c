#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include<locale.h>
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
        printf("\t\tDados do Registro: %d \n", i+1 );
        printf("\t\tCódigo do Produto: %d \n", p[i]->codigo);
        printf("\t\tDescrição do Produto: %s \n", p[i]->descricao);
        printf("\t\tFornecedor do Produto: %s \n", p[i]->fornecedor);
        printf("\t\tPreço do Produto: %.2lf \n", p[i]->preco);
        printf("\t\tQuantidade no Estoque: %d\n", p[i]->quantidadeEstoque);
        printf("\n");
        printf("\t\t------------------------------\n");
        printf("\n");

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
