#include <stdio.h>

// Definindo constantes para o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // 1. Inicialização do Tabuleiro 10x10 com 0s (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Vetor unidimensional representando as 3 partes estruturais do navio
    int navio[TAM_NAVIO] = {3, 3, 3};


    // --- 1. POSICIONAMENTO: NAVIO HORIZONTAL ---
    int linha_h = 0;
    int coluna_h = 0;
    int sobreposicao_h = 0;

    // Validação de limites (coluna inicial + tamanho não pode estourar o limite direito)
    if (coluna_h + TAM_NAVIO <= TAM_TABULEIRO && linha_h < TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao_h = 1;
            }
        }
        if (sobreposicao_h == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = navio[i];
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
    }


    // --- 2. POSICIONAMENTO: NAVIO VERTICAL ---
    int linha_v = 2;
    int coluna_v = 0;
    int sobreposicao_v = 0;

    // Validação de limites (linha inicial + tamanho não pode estourar o limite inferior)
    if (linha_v + TAM_NAVIO <= TAM_TABULEIRO && coluna_v < TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao_v = 1;
            }
        }
        if (sobreposicao_v == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = navio[i];
            }
        } else {
            printf("Erro: Sobreposição no navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
    }


    // --- 3. POSICIONAMENTO: NAVIO DIAGONAL DESCENDENTE (Noroeste para Sudeste) ---
    // Linha aumenta e Coluna aumenta simultaneamente
    int linha_d1 = 1;
    int coluna_d1 = 5;
    int sobreposicao_d1 = 0;

    // Validação: Garante que nem a linha nem a coluna ultrapassem o limite máximo (9)
    if (linha_d1 + TAM_NAVIO <= TAM_TABULEIRO && coluna_d1 + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] != 0) {
                sobreposicao_d1 = 1;
            }
        }
        if (sobreposicao_d1 == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = navio[i];
            }
        } else {
            printf("Erro: Sobreposição no navio diagonal descendente.\n");
        }
    } else {
        printf("Erro: Navio diagonal descendente fora dos limites.\n");
    }


    // --- 4. POSICIONAMENTO: NAVIO DIAGONAL ASCENDENTE (Sudoeste para Nordeste) ---
    // Linha diminui e Coluna aumenta simultaneamente
    int linha_d2 = 8;
    int coluna_d2 = 2;
    int sobreposicao_d2 = 0;

    // Validação: A linha recua (subindo no mapa) e a coluna avança (indo para a direita)
    if (linha_d2 - TAM_NAVIO + 1 >= 0 && coluna_d2 + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_d2 - i][coluna_d2 + i] != 0) {
                sobreposicao_d2 = 1;
            }
        }
        if (sobreposicao_d2 == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_d2 - i][coluna_d2 + i] = navio[i];
            }
        } else {
            printf("Erro: Sobreposição no navio diagonal ascendente.\n");
        }
    } else {
        printf("Erro: Navio diagonal ascendente fora dos limites.\n");
    }


    // --- 3. EXIBIÇÃO DO TABULEIRO COMPLETO ---
    printf("--- Tabuleiro de Batalha Naval - Nível Aventureiro ---\n\n");
    
    // Loops aninhados para renderizar as linhas e colunas alinhadas com espaços
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}
