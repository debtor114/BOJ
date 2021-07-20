#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    double A, D, H;
    scanf("%lf %lf %lf", &A, &D, &H);
    
    int ans = ceil((H - A) / (A - D)) + 1;

    printf("%d\n", ans);
    
    return 0;
}

