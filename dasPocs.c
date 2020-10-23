#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int codigo;
    char nome[30];
    float valor;
}Tipo;

Tipo batatinhas[5] = {
    {1, "Batatinhas Pequenas", 4.0},
    {2, "Batatinhas Médias", 6.0},
    {3, "Batatinhas Grandes", 8.0},
    {4, "Batatinhas Jumbo", 10.0},
    {5, "Batatas Assadas", 8.50},
};

FILE * arq;

//Variaveis Globais 
int codigoPedido, quantidade;
float valorRecebido, valorTotal = 0;
char  fazerOutroPedido, querVia;

//Corpo do Programa
int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("\nOlá, vamos começar seu pedido!\n");
    
    do{
        printf("\n|=======================================================|");
        printf("\n+-------------------[FAÇA SEU PEDIDO]-------------------+");
        printf("\n|=======================================================|\n");
        
        printf("\n=========================================================");
        printf("\n|\t\t\tBATATINHAS DAS POCS\t\t|");
        printf("\n---------------------------------------------------------");
        printf("\n|  Código  |   \t\tProduto\t\t   |   Valor    |\t");
        printf("\n---------------------------------------------------------");
        printf("\n|========================[OPÇÕES]=======================|");
        printf("\n---------------------------------------------------------");
        printf("\n|     1    |   \t   Batatinhas Pequenas\t   |  R$  4,00  |");
        printf("\n|     2    |   \t   Batatinhas Médias  \t   |  R$  6,00  |");
        printf("\n|     3    |   \t   Batatinhas Grandes \t   |  R$  8,00  |");
        printf("\n|     4    |   \t   Batatinhas Jumbo   \t   |  R$ 10,00  |");
        printf("\n|     5    |   \t   Batatas Assadas    \t   |  R$  8,50  |");
        printf("\n=========================================================\n");
        
        //abertura e cabeçalho do arquivo NotaFiscal.txt
        arq = fopen ("NotaFiscal.txt", "w");
        fprintf(arq, "\n\t  =================================================");
        fprintf(arq, "\n\t  |\t\tBATATINHAS DAS POCS\t\t|");
        fprintf(arq, "\n\t  -------------------------------------------------");
        fprintf(arq, "\nProduto\t\t   Valor unitario\t   Quantidade\tValor do pedido");
        
        printf("\nDigite o código do produto: ");
        scanf("%i", &codigoPedido);
        codigoPedido--;
        printf("\n=============================");
        printf(" \nProduto: %s ", batatinhas[codigoPedido].nome);
        printf("\n============================= ");
        printf("\n=============================");
        printf("\nPreço: %.2f ", batatinhas[codigoPedido].valor);
        printf("\n=============================");
        printf("\n=============================");
        printf("\nQuantidade: ");
        scanf("%d", &quantidade);
        printf("\n============================= \n");
        
        float valorDoPedido = batatinhas[codigoPedido].valor*quantidade;
        
        printf("\n=============================");
        printf("\nValor do Pedido: %.2f \n", valorDoPedido);
        printf("\n=============================\n\n");
        
        //gravação das informações do pedido no arquivo NotaFiscal.txt
        fprintf(arq, "\n%15s\t%.2f\t\t\t%3d\t\t%.2f", batatinhas[codigoPedido].nome, batatinhas[codigoPedido].valor, quantidade, valorDoPedido);
        
        valorTotal = valorTotal + valorDoPedido;
        
        printf("Deseja mais alguma coisa? sim(s) ou nao(n): ");
        fflush(stdin);
        scanf("%c", &fazerOutroPedido);
        
        }while(fazerOutroPedido == 's');
        
        printf ("\n\nQuer sua via? sim(s): ");
        fflush (stdin);
        scanf("%c" , &querVia);
        
        if(querVia == 's'){
            fprintf(arq, "\n\n\t\t   Valor total do pedido: R$ %.2f", valorTotal);
            fprintf(arq, "\n\t\t====================================================================\n");
            fclose(arq);
            //mostra na tela o conteúdo do arquivo NotaFiscal.txt
            system ("notepad NotaFiscal.txt");
        }

    return 0; 
}