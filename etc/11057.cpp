#include <iostream>

using namespace std;

int memo[1001][10];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < 10; i++) 
        memo[1][i] = 1;


    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            int k = j;
            while (k < 10) {
                memo[i][j] += memo[i-1][k] % 10007;
                k++;
            }

            // cout << "memo[" << i << "][" << j << "]: " << memo[i][j] << endl; 
        }
    }

    int sum = 0;

    for (int i = 0; i < 10; i++)
        sum += (memo[N][i])%10007;

    cout << sum%10007 << endl;

    return 0; 
}