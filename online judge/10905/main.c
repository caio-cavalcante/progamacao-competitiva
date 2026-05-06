#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    char p1[1000], p2[1000];

    strcpy(p1, s1);
    strcat(p1, s2);
    strcpy(p2, s2);
    strcat(p2, s1);

    return strcmp(p2, p1);
}

int main() {
    int i, n;

    while (scanf("%d", &n) == 1 && n != 0) {
        char **nums = (char **)malloc(n * sizeof(char *));
        for (i = 0; i < n; i++) {
            nums[i] = (char *)malloc(100 * sizeof(char));
            scanf("%s", nums[i]);
        }

        qsort(nums, n, sizeof(char *), compare);

        for (i = 0; i < n; i++) {
            printf("%s", nums[i]);
        }
        printf("\n");

        for (i = 0; i < n; i++) free(nums[i]);
        free(nums);
    }

    return 0;
}