#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x1, x2, y1, y2, r1, r2, ans;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        int d = (x2 -x1) * (x2 -x1) + (y2 - y1) * (y2 - y1);
        int add = r1 + r2;
        int sub = r2 - r1;
        
        // 원의 중심이 같은 경우
        if (d == 0) {
            if (r1 == r2) ans = -1;
            else ans = 0;
        }

        // 원의 중심이 다른 경우
        else {
            // 한 원이 다른 원의 외부에 있는 경우
            if (d > add * add) ans = 0;
            else if ( d == add * add) ans = 1;
            else if ( d < add * add && d > sub * sub ) ans = 2;
            
            // 한 원이 다른 원의 내부에 있는 경우
            else if ( d == sub * sub ) ans = 1;
            else if ( d < sub * sub ) ans = 0; 
            } 
        
        printf("%d\n", ans);
    }      
    return 0;
}