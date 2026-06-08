#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

int main() {
    // 1. Inicialização do Tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int navio[TAM_NAVIO] = {3, 3, 3};

    // --- REPOSICIONANDO OS NAVIOS (Níveis Anteriores) ---
    // Horizontal (0,0)
    for(int i = 0; i < TAM_NAVIO; i++) tabuleiro[0][0 + i] = navio[i];
    // Vertical (2,0)
    for(int i = 0; i < TAM_NAVIO; i++) tabuleiro[2 + i][0] = navio[i];
    // Diagonal Descendente (1,5)
    for(int i = 0; i < TAM_NAVIO; i++) tabuleiro[1 + i][5 + i] = navio[i];
    // Diagonal Ascendente (8,2)
    for(int i = 0; i < TAM_NAVIO; i++) tabuleiro[8 - i][2 + i] = navio[i];


    // --- 2. CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5) ---
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // A. Construindo o Cone
    // O cone começa no topo (linha 0, coluna 2) e se expande para baixo.
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // A largura do cone cresce conforme a linha (i) aumenta
            if (i <= 2 && j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

    // B. Construindo a Cruz
    // A cruz é formada por uma linha central e uma coluna central.
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // C. Construindo o Octaedro (Losango)
    // Usamos a Distância de Manhattan em relação ao centro (2,2)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Calculando a distância absoluta de i e j até o centro (2)
            int dist_i = (i > 2) ? (i - 2) : (2 - i);
            int dist_j = (j > 2) ? (j - 2) : (2 - j);
            
            // Se a soma das distâncias for <= 1, pertence ao octaedro
            if (dist_i + dist_j <= 1) {
                octaedro[i][j] = 1;
            }
        }
    }


    // --- 3. SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO ---
    
    // Configurando as coordenadas de origem (centro de impacto no tabuleiro)
    int origem_cone_x = 7, origem_cone_y = 8;     // Canto inferior direito
    int origem_cruz_x = 3, origem_cruz_y = 3;     // Meio superior esquerdo
    int origem_octaedro_x = 7, origem_octaedro_y = 2; // Canto inferior esquerdo

    // Aplicando a habilidade CONE
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                // Ajuste de índice: centraliza a matriz 5x5 subtraindo 2 da origem
                int px = origem_cone_x - 2 + i;
                int py = origem_cone_y - 2 + j;
                // Valida se o impacto ocorre dentro dos limites do mapa 10x10
                if (px >= 0 && px < TAM_TABULEIRO && py >= 0 && py < TAM_TABULEIRO) {
                    tabuleiro[px][py] = 5;
                }
            }
        }
    }

    // Aplicando a habilidade CRUZ
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int px = origem_cruz_x - 2 + i;
                int py = origem_cruz_y - 2 + j;
                if (px >= 0 && px < TAM_TABULEIRO && py >= 0 && py < TAM_TABULEIRO) {
                    tabuleiro[px][py] = 5;
                }
            }
        }
    }

    // Aplicando a habilidade OCTAEDRO
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int px = origem_octaedro_x - 2 + i;
                int py = origem_octaedro_y - 2 + j;
                if (px >= 0 && px < TAM_TABULEIRO && py >= 0 && py < TAM_TABULEIRO) {
                    tabuleiro[px][py] = 5;
                }
            }
        }
    }


    // --- 4. EXIBIÇÃO FINAL DO TABULEIRO ---
    printf("--- Tabuleiro de Batalha Naval - Nivel Mestre ---\n");
    printf("0 = Agua | 3 = Navio | 5 = Area de Habilidade\n\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
