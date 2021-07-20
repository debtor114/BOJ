#include <iostream>
#include <vector>

using namespace std;

int n, r;
vector <int> list;

void permutation_dup(int depth) {
    
    if (depth == r) {
        for (int i = 0; i < r; i++)
            cout << list[i] << " ";

        cout << "\n";
        return;
    }
    

   for (int i = 1; i <= n; i++) {
            list.push_back(i);
            permutation_dup(depth+1);
            list.pop_back();
    }
}

int main() {
    cin >> n >> r;

    permutation_dup(0);
    return 0;
}