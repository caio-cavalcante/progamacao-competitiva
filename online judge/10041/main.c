/*
1. Ler N (casos de teste)
2. Para cada teste:
   a. Ler R e os R elementos para um array S
   b. Ordenar o array S em ordem crescente
   c. Identificar a casa da mediana: VITO_HOUSE = S[R / 2]
   d. Calcular D = soma de |S[i] - VITO_HOUSE| para i de 0 até R-1
   e. Imprimir D
*/

#include <stdio.h>
#include <stdlib.h> /* qsort(array_name, array_size, sizeof(element_type), compare), abs() */

int compare(const void *a, const void *b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    int t, i;
    int num_cases;
    int relatives;
    int street[505];
    int vito_house;
    int distance;
    
    if (scanf("%d", &num_cases) != 1) return 0;
    
    for (t = 0; t < num_cases; t++) {
        scanf("%d", &relatives);
        
        for(i = 0; i < relatives; i++){
            scanf("%d", &street[i]);
        }
        
        qsort(street, relatives, sizeof(street[0]), compare);
        
        vito_house = street[relatives / 2]; /* median after sort */
        
        distance = 0;
        for(i = 0; i < relatives; i++) {
            distance += abs(street[i] - vito_house);
        }
        
        printf("%d\n", distance);
    }

    return 0;
}
