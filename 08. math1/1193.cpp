#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, i = 1;
    cin >> N;

    while (1) {
        if (N - i <= 0)
            break;

        else {
            N -= i;
            i++;
        }
    }
    // 짝수번째 
    if (i % 2 == 0) cout << N << "/" << i+1-N << endl;
    
    // 홀수번째
    else cout << i+1-N << "/" << N << endl;
    
    return 0;
}