/*
Para cada palavra da lista:
    Para cada linha i de 0 até m-1:
        Para cada coluna j de 0 até n-1:
            Se matriz[i][j] == primeira letra da palavra:
                Chamar FUNÇÃO_BUSCA_DIRECIONAL(i, j, palavra)
                Se encontrou: 
                    Salvar (i, j) e ir para a próxima palavra
                    
FUNÇÃO_BUSCA_DIRECIONAL(i, j, palavra)
    se o tamanho da palavra for 1, a busca acaba na primeira letra
    
    validar se as coordenadas estão dentro do intervalo 0≤linha<m e 0≤coluna<n
    Olhar as 8 células vizinhas.  
    Se achar a segunda letra na posição (i+Δlinha,j+Δcoluna), calcular a direção.
    Avançar em linha reta usando essa direção fixa.
*/
#include <stdio.h>
#include <ctype.h>

#define MAX_ROWS 55
#define MAX_COLS 55
#define MAX_WORD_LEN 100

char grid[MAX_ROWS][MAX_COLS];

const int dirRow[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dirCol[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int verifica_direcao(int row, int col, const char* word, int dir, int m, int n) {
    int len = 0;
    
    while (word[len] != '\0') len++;

    int i;
    for (i = 0; i < len; i++) {
        int next_row = row + i * dirRow[dir];
        int next_col = col + i * dirCol[dir];

        if (next_row < 0 || next_row >= m || next_col < 0 || next_col >= n) {
            return 0; 
        }

        if (tolower((unsigned char)grid[next_row][next_col]) != tolower((unsigned char)word[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num_cases;
    int t;

    if (scanf("%d", &num_cases) != 1) {
        return 0;
    }

    for (t = 0; t < num_cases; t++) {
        int m, n, k;
        int i, j, w, d;
        char word[MAX_WORD_LEN];

        scanf("%d %d", &m, &n);

        for (i = 0; i < m; i++) {
            scanf("%s", grid[i]);
        }

        scanf("%d", &k);

        for (w = 0; w < k; w++) {
            scanf("%s", word);

            int found = 0;

            for (i = 0; i < m && !found; i++) {
                for (j = 0; j < n && !found; j++) {
                    
                    if (tolower((unsigned char)grid[i][j]) == tolower((unsigned char)word[0])) {
                        
                        for (d = 0; d < 8; d++) {
                            if (verifica_direcao(i, j, word, d, m, n)) {
                                printf("%d %d\n", i + 1, j + 1);
                                found = 1;
                                break;
                            }
                        }
                    }

                }
            }
        }

        if (t < num_cases - 1) {
            printf("\n");
        }
    }

    return 0;
}
