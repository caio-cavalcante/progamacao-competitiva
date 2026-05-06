#include <stdio.h>
#include <string.h>

int n, m;
char field[100][101];

int countMines (int row, int col) {
    int d;
    if (field[row][col] == '*') return -1;

    int count = 0;
    int rowDir[] = {-1, -1, -1,  0, 0,  1, 1, 1}; /* direções para verificar */
    int colDir[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for (d = 0; d < 8; d++) {
        int nextRow = row + rowDir[d]; /* próxima linha para verificar */
        int nextCol = col + colDir[d]; /* próxima coluna para verificar */
        
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m) {
            if (field[nextRow][nextCol] == '*') count++;
        }
    }
    return count;
}

int main() {
    /* restrições:
    n, m entre 1 e 100
    termina quando enviar (0, 0)
    "*" é bomba, "." é número
    no output, informar "Field #x:"
    */
    int i, j;
    int fieldNum = 0;
    
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        for (i = 0; i < n; i++) {
            scanf("%s", &field[i]);
        }
        
        if(fieldNum > 0) printf("\n");
        fieldNum++;
        
        printf("Field #%d:\n", fieldNum);
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    printf("*");
                } else {
                    printf("%d", countMines(i, j));
                }
            }
            printf("\n");
        }
    }

    return 0;
}