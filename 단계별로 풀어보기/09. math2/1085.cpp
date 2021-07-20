#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    int ans = min(min((w-x), (h-y)), min(x, y));
    printf("%d\n", ans);
    return 0;
    
}