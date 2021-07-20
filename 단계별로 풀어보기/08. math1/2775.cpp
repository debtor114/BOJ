#include <iostream>

using namespace std;

int main() {
    int T, k, n, apart[15][15];

    // initialize
    for (int j = 0; j < 14; j++) apart[0][j] = j+1;

    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            if (j == 0) apart[i][j] = 1;
            else apart[i][j] = apart[i][j-1] + apart[i-1][j];
        }
    }

    cin >> T;
    while(T--) {
        cin >> k >> n;
        cout << apart[k][n-1] << endl;
    }
    return 0;
}



// 1 5 15
// 1 4 10
// 1 3 6 ...               108
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14