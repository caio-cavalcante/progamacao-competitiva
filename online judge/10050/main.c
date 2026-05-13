#include <stdio.h>

int main() {
    int i, j, T, N, P;
    
    printf("Tests: ");
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        printf("Days: ");
        scanf("%d", &N);
        
        printf("Parties: ");
        scanf("%d", &P);
        
        int hartal_days[3651] = {0};
        int h_parameter;
        
        for (i = 0; i < P; i++) {
            printf("Hartal for P#%d: ", i+1);
            scanf("%d", &h_parameter);
                
            for (j = h_parameter; j <= N; j += h_parameter) {
                hartal_days[j] = 1;
            }
        }
        
        int lost_days = 0;
        
        for (i = 1; i <= N; i++) {
            if (hartal_days[i]) {
                if (i % 7 != 6 && i % 7 != 0) {
                    lost_days++;
                }
            }
        }
        
        printf("Lost: %d\n", lost_days);
    }
    
    return 0;
}