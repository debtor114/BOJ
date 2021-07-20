#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int n, m;
vector <int> v, stack;

void RP(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << stack[i] << " ";

        cout << "\n";
    }
    
    else {
        for (int i = 0; i <= n-1; i++) {
            stack.push_back(v[i]);
            RP(depth + 1);
            stack.pop_back();
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        v.push_back(i+1);

    RP(0);
    return 0;
}