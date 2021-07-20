#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int memo[1001][1001];
    string s1, s2;
    cin >> s1 >> s2;

    s1 = "0" + s1;
    s2 = "0" + s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j])  memo[i][j] = memo[i-1][j-1] + 1;
            else  memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

        }
    }

    string LCS;
    int x = s1.length()-1;
    int y = s2.length()-1;
    int LCS_length = memo[x][y];

    while (LCS_length != 0) {
        if (memo[x-1][y] == LCS_length) x--;
        else if (memo[x][y-1] == LCS_length)  y--;
        else {
            LCS.push_back(s1[x] == s2[x] ? s1[x] : s2[y]);
            x--, y--;
            LCS_length--;
        }
    }


    printf("%d\n", memo[s1.length()-1][s2.length()-1]);
    if (memo[s1.length()-1][s2.length()-1] != 0) {
        for (int i = LCS.length() - 1; i >= 0; i--)
            printf("%c", LCS[i]);

        printf("\n");
    }
    return 0;

}