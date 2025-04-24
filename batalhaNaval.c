#include <stdio.h>

//1. Declara variáveis
#define linhas 10
#define colunas 10


int main (){

    //2.Exibindo o tabuleiro (Usar loop's aninhados para imprimir o tabuleiro)
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 

    
    printf("***Bem-vindo ao jogo: Batalha Naval!***\n");
    printf("    %c %c %c %c %c %c %c %c %c %c\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5], linha[6], linha[7], linha[8], linha[9]);
       
    //3. Criando o Tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];
        for (int i = 0; i < 10; i++)
        {
            printf("%2d. ", i + 1);

            for (int j = 0; j < 10; j++)
            {
                printf("%d ", tabuleiro[i][j] =  0);
            }
            printf("\n");
        } 

        
    //4. Coordenadas e tamanho
    int navio_horizontal_coluna = 1;
    int navio_horizontal_linha = 8;
    int navio_vertical_coluna = 8;
    int navio_vertical_linha = 5;
    int navio_diagonal_linha = 2;
    int navio_diagonal_coluna = 1;
    int tamanho_navio = 3;

    //5.Posicionar os navios (Usar loop's para posicionar o navio)

    //5.1 Navio na horizontal
    if (navio_horizontal_coluna + navio_horizontal_linha > colunas)
    {
        printf("Opção inválida!\n");
    } else
    {
        for (int j = navio_horizontal_coluna; j < navio_horizontal_coluna + tamanho_navio; j++)
        {
            tabuleiro[navio_horizontal_linha] [j] = 3;
        } 
    }
    
    //5.2 Navio na vertical
    if (navio_vertical_linha + tamanho_navio > linhas)
    {
        printf("Opção inválida!\n");
    } else
    {
        for (int i = navio_vertical_linha; i < navio_vertical_linha + tamanho_navio; i++)
        {
            tabuleiro[i][navio_vertical_coluna] = 3;
        } 
    }

    //5.3 Navio diagonal 1 esquerda para a direita

    int navio_diagonal1_linha = 2;
    int navio_diagonal1_coluna = 2;
    int tamanho_navio_diagonal = 3;


    if (navio_diagonal1_linha + tamanho_navio_diagonal > linhas || 
    navio_diagonal1_coluna + tamanho_navio_diagonal > colunas) {
    printf("Opção inválida para navio diagonal!\n");
    } else {
    for (int i = 0; i < tamanho_navio_diagonal; i++) {
        tabuleiro[navio_diagonal1_linha + i][navio_diagonal1_coluna + i] = 3;
    }
    }
    
    
    //5.4 Navio diagonal 2 direita para a esquerda 
    int navio_diagonal2_linha = 2;
    int navio_diagonal2_coluna = 6;
    int tamanho_navio_diagonal2 = 3;

  
    if (navio_diagonal2_linha + tamanho_navio_diagonal2 > linhas ||
    navio_diagonal2_coluna - (tamanho_navio_diagonal2 - 1) < 0) {
    printf("Opção inválida para navio diagonal 2!\n");
    } else {
    for (int i = 0; i < tamanho_navio_diagonal2; i++) {
        tabuleiro[navio_diagonal2_linha + i][navio_diagonal2_coluna - i] = 3;
    }
    }

    //6.Imprimir novamente o tabuleiro
    printf("\n");
    printf("Navios posicionados!\n");
    printf("    %c %c %c %c %c %c %c %c %c %c\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5], linha[6], linha[7], linha[8], linha[9]);

    for (int i = 0; i < linhas; i++)
    {
        printf("%2d. ", i + 1);  
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ",tabuleiro[i][j]);
        }
        printf("\n");
    }
    
   


return 0;
 
}