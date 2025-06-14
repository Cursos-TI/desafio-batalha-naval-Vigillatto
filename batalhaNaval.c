#include <stdio.h>
#include <string.h>

#define TAM 10

// Função para imprimir o tabuleiro
void exibirTabuleiro(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para limpar o tabuleiro
void limparTabuleiro(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

// Função para posicionar navio vertical
void posicionarNavioVertical(int matriz[TAM][TAM], int x, int y, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        matriz[x + i][y] = 3;
    }
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(int matriz[TAM][TAM], int x, int y, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        matriz[x][y + i] = 3;
    }
}

// Função para posicionar navio na diagonal principal (↘)
void posicionarNavioDiagonalPrincipal(int matriz[TAM][TAM], int x, int y, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        matriz[x + i][y + i] = 3;
    }
}

// Função para posicionar navio na diagonal secundária (↙)
void posicionarNavioDiagonalSecundaria(int matriz[TAM][TAM], int x, int y, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        matriz[x + i][y - i] = 3;
    }
}

// Funções de habilidades especiais
void habilidadeCone(int matriz[5][5]) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    memcpy(matriz, cone, sizeof(int) * 25);
}

void habilidadeOctaedro(int matriz[5][5]) {
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    memcpy(matriz, octaedro, sizeof(int) * 25);
}

void habilidadeCruz(int matriz[5][5]) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    memcpy(matriz, cruz, sizeof(int) * 25);
}

// Função para exibir matriz 5x5 de habilidade
void exibirHabilidade(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int tabuleiro[TAM][TAM];
    limparTabuleiro(tabuleiro);

    // Nível Novato: 2 navios simples
    posicionarNavioVertical(tabuleiro, 0, 0, 3);     // Navio vertical
    posicionarNavioHorizontal(tabuleiro, 5, 2, 4);   // Navio horizontal

    // Nível Aventureiro: navios diagonais
    posicionarNavioDiagonalPrincipal(tabuleiro, 2, 2, 3);
    posicionarNavioDiagonalSecundaria(tabuleiro, 1, 8, 3);

    printf("\nTabuleiro com navios (0 = livre, 3 = navio):\n");
    exibirTabuleiro(tabuleiro);

    // Nível Mestre: habilidades especiais
    int habilidade[5][5];

    printf("\nHabilidade em Cone:\n");
    habilidadeCone(habilidade);
    exibirHabilidade(habilidade);

    printf("\nHabilidade em Octaedro:\n");
    habilidadeOctaedro(habilidade);
    exibirHabilidade(habilidade);

    printf("\nHabilidade em Cruz:\n");
    habilidadeCruz(habilidade);
    exibirHabilidade(habilidade);

    return 0;
}
