#include <stdio.h>
#include <stdlib.h>
#define T 500
#include "produto.h"

// --- REVER COMPRA E VENDA ---

int main()
{
    int opc = 0;
    int qtdCompra = 0;
    int qtdVenda = 0;
    int pos = 0;
    int codigoProc = 0;
    Produto* vet_produto[T];
    inicializar(vet_produto, T);

    do{
        printf("Lista de Produtos \n");
        printf("-------------------- \n");
        printf("1. Cadastrar Produto \n");
        printf("2. Listar Produto \n");
        printf("3. Encontrar Produto \n");
        printf("4. Comprar Produto \n");
        printf("4. Vender Produto \n");
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
                printf("Digite o codigo do produto a ser encontrado: \n");
                scanf("%d", &codigoProc);
                encontrar(vet_produto, codigoProc, pos);
                break;
            case 4:
                printf("Digite a quantidade de itens para comprar: \n");
                scanf("%d", &qtdCompra);
                printf("Digite o codigo do produto a ser comprado: \n");
                scanf("%d", &codigoProc);
                comprar(vet_produto, codigoProc, pos, qtdCompra);
                break;
            case 5:
                printf("Digite a quantidade de itens para vender: \n");
                scanf("%d", &qtdVenda);
                printf("Digite o codigo do produto a ser vendido: \n");
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

