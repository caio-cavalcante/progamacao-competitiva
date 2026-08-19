#include <stdio.h>

long long slicePizza(long long num) {
    return (num * num + num + 2) / 2;
}

int main() {
    long long num;

    while (scanf("%lld", &num) == 1 && num >= 0) {
        printf("%lld\n", slicePizza(num));
    }

    return 0;
}