#include <stdio.h>
#include <string.h>

const char KEYBOARD[] = "`1234567890-=QWERTYUIOP[]\\\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    int ch;
    char *ptr;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n') {
            putchar(ch);
        } else {
            ptr = strchr(KEYBOARD, ch);
            if (ptr != NULL) {
                putchar(*(ptr - 1));
            } else {
                putchar(ch);
            }
        }
    }

    return 0;
}