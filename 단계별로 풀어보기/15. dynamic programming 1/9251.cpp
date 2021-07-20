#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int memo[1001][1001];

    s1 = "0" + s1;
    s2 = "0" + s2;

    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 | j == 0) {
                memo[i][j] == 0;
                continue;
            }

            if (s1[i] == s2[j]) memo[i][j] = memo[i-1][j-1] + 1;
            else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
    }

    printf("%d\n", memo[s1.length()-1][s2.length()-1]);
    return 0;

}
