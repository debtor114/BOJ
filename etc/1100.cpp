#include <cstdio>

using namespace std;

int main() {
    char c;
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%c", &c);
            if (c == 'F') {
                if (i % 2 == 0 && j % 2 == 0) {
                    count++;
                    //printf("(%d, %d)\n", i, j);
                }
                if (i % 2 == 1 && j % 2 == 1) {
                    count++;
                    //printf("(%d, %d)\n", i, j);
                }
            }          
        }
    }

    printf("%d\n", count);
    return 0;
    
}