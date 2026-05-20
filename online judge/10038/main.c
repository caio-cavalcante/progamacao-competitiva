#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, d;
    int num[3003];
    int dif[3003];
    int isJolly = 1;
    
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        
        isJolly = 1;
        
        if (n == 1) isJolly = 1;
        
        for (i = 0; i <= n; i++) {
            dif[i] = 0;
        }
        
        for (i = 0; i < n-1; i++) {
            d = abs(num[i] - num[i+1]);
            
            if (((d < 1) || (d > n-1)) || (dif[d] == 1)) {
                isJolly = 0;
                break;
            }
            
            dif[d] = 1;
        }
        
        if (isJolly == 0) {
            printf("Not jolly\n");
        } else if (isJolly == 1) {
            printf("Jolly\n");
        }
    }

    return 0;
}
