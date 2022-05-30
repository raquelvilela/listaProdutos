#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define T 500
#include "produto.h"

int main()
{
    system("title Lista de Produtos"); //titulo
    system("mode con:cols=60 lines=30"); //redimendionar tamanho

    setlocale(LC_ALL, "ptb"); // acentuacao portugues
    system ("color 1F"); // system ("color 15F")  -- mudar cor

    int opc = 0;
    int resp = 0;
    int qtdCompra = 0, qtdVenda = 0;
    int pos = 0;
    int codigoProc = 0;
    Produto* vet_produto[T];
    inicializar(vet_produto, T);

    do{
        fflush(stdin);
        printf("\t\t***************************\n");
        printf("\t\t*****LISTA DE PRODUTOS*****\n");
        printf("\t\t***************************\n");
        printf("\t\t1. Cadastrar Produto \n");
        printf("\t\t2. Listar Produto \n");
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



