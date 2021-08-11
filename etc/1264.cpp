#include <cstdio>

int main() {
    char c;
    int count = 0;
    while (1) {
        scanf("%1c", &c);
        if (c == '#') break;

        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            count++;

        if (c == 10) {
            printf("%d\n", count);
            count = 0;
        }
    }
    
    return 0;
}