#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> power;

int zeroCount (int num) {
    int result;

    for (int i = 0; i < 13; i++) {
        if (num >= power[i] && num < power[i+1])
            result = num/5 + i*(i+1)/2;
    }
    return result;
}


int main() {
    int N, M;
    cin >> N >> M;

    // 5의 제곱수 구하기
    for (int i = 0; i <= 13; i++) {
        power.push_back(pow(5, i));
    }
    

    cout << zeroCount(N) << "\n";
    cout << zeroCount(M) << "\n";
    cout << zeroCount(N-M) << "\n";
    return 0;
}