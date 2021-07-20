#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    
   while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c && a == 0) break;

        if (c * c == a * a + b * b || a * a == b * b + c * c || b * b == a * a + c * c) 
            printf("right\n");
        else printf("wrong\n");
    } 
    return 0;
}