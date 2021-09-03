#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int x1, x2;
    x1 = ceil((double)M/4);
    x2 = ceil((double)N/4);

    int dis = x1-x2;
    
    int y1, y2;

    if (N%4 > 0) y2 = N%4;
    else y2 = 4;

    if (M%4 > 0) y1 = M%4;
    else y1 = 4;

    dis += abs(y2-y1);

    cout << dis << endl;
    
}