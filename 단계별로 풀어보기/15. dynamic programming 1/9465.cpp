#include <iostream>
#include <algorithm>

int input[2][100001];
int memo[100001][2];

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> input[0][i];

        for (int i = 1; i <= N; i++)
            cin >> input[1][i];

        // memo[i][0]: i째 선택에서 위에 꺼를 고른경우 
        // memo[i][1]: i째 선택에서 밑에 꺼를 고른경우
        memo[0][0] = memo[0][1]  = 0;

        memo[1][0] = input[0][1];
        memo[1][1] = input[1][1];

        for (int i = 2; i <= N; i++) {
            memo[i][0] = max(memo[i-1][1], memo[i-2][1]) + input[0][i];
            memo[i][1] = max(memo[i-1][0], memo[i-2][0]) + input[1][i];
        }

        cout << max(memo[N][0], memo[N][1]) << endl;
    }
    return 0;
}