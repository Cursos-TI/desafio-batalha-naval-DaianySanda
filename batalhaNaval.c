#include <stdio.h> // Biblioteca padrão de entrada e saída

    // 0. Declara constantes para o tamanho do tabuleiro
    #define linhas 10   // Número de linhas do tabuleiro
    #define colunas 10  // Número de colunas do tabuleiro

    // 1.1 Cone criação da recursiva
    /*
    Exemplo de saída de habilidade em cone:
    0 0 3 0 0
    0 3 3 3 0 
    3 3 3 3 3
    */

    void cone (int tabuleiro [linhas][colunas], int x, int y){

        int dx[] = { 0,  
                 1,  1,  1,  
              2,  2, 2, 2, 2 }; //linha
        int dy[] = {0, 
                -1, 0, 1, 
            -2, -1, 0, 1, 2 }; //coluna

    
        for (int i = 0; i < 9; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas)
            {
                tabuleiro [nx][ny] = 5;
            }
            
        }
        
    }


    // 1.2. Cruz criação da recursiva
    /*
    Exemplo de saída de habilidade em cruz:
    0 0 3 0 0 
    3 3 3 3 3 
    0 0 3 0 0
    */

    void cruz (int tabuleiro [linhas][colunas], int x, int y){

        int dx[] = {  0,  
                0, 0, 0, 0, -1, 
                      1 }; //linha 

        int dy[] = { -2, 
               -1, 0, 1, 2, 0, 
                      0 }; //coluna 
    
        for (int i = 0; i < 7; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas)
            {
                tabuleiro [nx][ny] = 5;
            }
            
        }
        
    }

    // 1.3. Octaedro criação da recursiva
    /*
    Exemplo de saída de habilidade em octaedro:
    0 0 3 0 0 
    0 3 3 3 0 
    0 0 3 0 0 
    */
    
    void octaedro (int tabuleiro [linhas][colunas], int x, int y){

        int dx[] = {-1,  
                  0, 0, 0, 
                     1}; //linha 
        int dy[] = { 0, 
                 -1, 0, 1, 
                     0}; // coluna 
    
        for (int i = 0; i < 5; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas)
            {
                tabuleiro [nx][ny] = 5;
            }
            
        }
        
    }


int main() {

    // 2. Exibindo o cabeçalho do jogo
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Letras para rotular as colunas

    printf("*Bem-vindo ao jogo: Batalha Naval!*\n");

    // Imprime os rótulos das colunas (A a J)
    printf("    %c %c %c %c %c %c %c %c %c %c\n",
           linha[0], linha[1], linha[2], linha[3], linha[4],
           linha[5], linha[6], linha[7], linha[8], linha[9]);

    // 3. Criando e inicializando o tabuleiro (matriz 10x10)
    int tabuleiro[10][10]; // Matriz que representa o tabuleiro

    for (int i = 0; i < 10; i++) {
        printf("%2d. ", i + 1); // Exibe o número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // Inicializa cada posição como 0 (água)
            printf("%d ", tabuleiro[i][j]); // Exibe o valor da célula
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    // 4. Coordenadas e tamanho dos navios
    int navio_horizontal_coluna = 1; // Coluna inicial do navio horizontal
    int navio_horizontal_linha = 8;  // Linha onde o navio horizontal será colocado

    int navio_vertical_coluna = 8;   // Coluna do navio vertical
    int navio_vertical_linha = 5;    // Linha inicial do navio vertical

    int tamanho_navio = 3; // Tamanho padrão dos navios

    // 5. Posicionando os navios

    // 5.1 Navio na horizontal (→)
    if (navio_horizontal_coluna + tamanho_navio > colunas) {
        printf("Opção inválida!\n"); // Verifica se ultrapassa os limites do tabuleiro
    } else {
        for (int j = navio_horizontal_coluna; j < navio_horizontal_coluna + tamanho_navio; j++) {
            tabuleiro[navio_horizontal_linha][j] = 3; // Marca como navio (valor 3)
        }
    }

    // 5.2 Navio na vertical (↓)
    if (navio_vertical_linha + tamanho_navio > linhas) {
        printf("Opção inválida!\n"); // Verifica se ultrapassa o limite inferior
    } else {
        for (int i = navio_vertical_linha; i < navio_vertical_linha + tamanho_navio; i++) {
            tabuleiro[i][navio_vertical_coluna] = 3; // Marca a coluna do navio
        }
    }

    // 5.3 Navio na diagonal da esquerda para a direita (↘)
    int navio_diagonal1_linha = 0;  // Linha inicial
    int navio_diagonal1_coluna = 0; // Coluna inicial
    int tamanho_navio_diagonal = 3; // Tamanho do navio

    // Verifica se há espaço suficiente
    if (navio_diagonal1_linha + tamanho_navio_diagonal > linhas || navio_diagonal1_coluna + tamanho_navio_diagonal > colunas) 
        {
            printf("Opção inválida para navio diagonal!\n");
        } else 
        {
            for (int i = 0; i < tamanho_navio_diagonal; i++) 
            {
            tabuleiro[navio_diagonal1_linha + i][navio_diagonal1_coluna + i] = 3; 
            // Incrementa linha e coluna a cada passo → cria diagonal ↘
            }
        }

    // 5.4 Navio na diagonal da direita para a esquerda (↙)
    int navio_diagonal2_linha = 0;  // Linha inicial
    int navio_diagonal2_coluna = 5; // Coluna inicial (à direita)
    int tamanho_navio_diagonal2 = 3; // Tamanho do navio

    // Verifica se há espaço suficiente
    if (navio_diagonal2_linha + tamanho_navio_diagonal2 > linhas || navio_diagonal2_coluna - (tamanho_navio_diagonal2 - 1) < 0) 
        {
            printf("Opção inválida para navio diagonal 2!\n");
        } else 
        {
            for (int i = 0; i < tamanho_navio_diagonal2; i++) 
            {
                tabuleiro[navio_diagonal2_linha + i][navio_diagonal2_coluna - i] = 3;
                // Incrementa a linha e decrementa a coluna → cria diagonal ↙
            }
        }
    
    // 6. Poisionar o Cone e ligar a recursividade

    int cone_linha = 7;
    int cone_coluna = 6;

    cone(tabuleiro,cone_linha, cone_coluna);
    
    // 6. Poisionar a Cruz ligar a recursividade
    
    int cruz_linha = 2;
    int cruz_coluna = 7;

    cruz(tabuleiro,cruz_linha, cruz_coluna);
    
    // 6. Poisionar o Octaedro ligar a recursividade
       
    int octaedro_linha = 5;
    int octaedro_coluna = 5;

    octaedro(tabuleiro,octaedro_linha, octaedro_coluna);

    // 9. Imprimir novamente o tabuleiro com os navios posicionados
    printf("\n");
    printf("Navios posicionados!\n");

    // Exibe novamente as letras das colunas
    printf("    %c %c %c %c %c %c %c %c %c %c\n",
           linha[0], linha[1], linha[2], linha[3], linha[4],
           linha[5], linha[6], linha[7], linha[8], linha[9]);

    for (int i = 0; i < linhas; i++) {
        printf("%2d. ", i + 1); // Exibe o número da linha
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada célula do tabuleiro (0 = água, 3 = navio)
        }
        printf("\n");
    }

    return 0; // Fim do programa
}