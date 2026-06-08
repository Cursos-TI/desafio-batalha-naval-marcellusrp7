#include <stdio.h>

// Definindo constantes para facilitar a manutenção e leitura do código
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // 1. Representação do Tabuleiro
    // Matriz 10x10 inicializada automaticamente com 0s (representando a água).
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // 2. Representação dos Navios
    // Vetor unidimensional que guarda os blocos do navio (valor 3).
    int navio[TAM_NAVIO] = {3, 3, 3};

    // --- Configuração do Navio Horizontal ---
    // Coordenadas de início (linha 2, coluna 2)
    int linha_h = 2;
    int coluna_h = 2;
    int sobreposicao_h = 0; // Flag para verificar sobreposição

    // Verifica se o navio horizontal cabe dentro dos limites do tabuleiro
    if (coluna_h + TAM_NAVIO <= TAM_TABULEIRO && linha_h < TAM_TABULEIRO) {
        // Verifica se há alguma parte de outro navio no caminho (sobreposição)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao_h = 1;
            }
        }
        
        // Se estiver dentro dos limites e sem sobreposição, posiciona o navio
        if (sobreposicao_h == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                // Copia o valor do vetor 'navio' para a matriz 'tabuleiro'
                tabuleiro[linha_h][coluna_h + i] = navio[i];
            }
        } else {
            printf("Erro: O navio horizontal irá se sobrepor a outro.\n");
        }
    } else {
        printf("Erro: As coordenadas do navio horizontal excedem o tabuleiro.\n");
    }

    // --- Configuração do Navio Vertical ---
    // Coordenadas de início (linha 5, coluna 7)
    int linha_v = 5;
    int coluna_v = 7;
    int sobreposicao_v = 0; // Flag para verificar sobreposição

    // Verifica se o navio vertical cabe dentro dos limites do tabuleiro
    if (linha_v + TAM_NAVIO <= TAM_TABULEIRO && coluna_v < TAM_TABULEIRO) {
        // Verifica se há sobreposição antes de posicionar
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao_v = 1;
            }
        }
        
        // Se válido, posiciona o navio vertical
        if (sobreposicao_v == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                // O deslocamento agora é feito nas linhas, mantendo a coluna fixa
                tabuleiro[linha_v + i][coluna_v] = navio[i];
            }
        } else {
            printf("Erro: O navio vertical irá se sobrepor a outro.\n");
        }
    } else {
        printf("Erro: As coordenadas do navio vertical excedem o tabuleiro.\n");
    }

    // 3. Exibição do Tabuleiro
    printf("--- Tabuleiro de Batalha Naval ---\n\n");
    
    // Loop aninhado para percorrer cada linha e coluna da matriz
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Imprime o número e um espaço em branco para facilitar a visualização
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha após terminar de imprimir as colunas
        printf("\n");
    }

    return 0;
}
