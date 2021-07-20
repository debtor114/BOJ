#include <iostream>
#include <vector>

using namespace std;

int n, r;
vector <int> list;

void combination(int depth, int index) {
    
    if (depth == r) {
        for (int i = 0; i < r; i++)
            cout << list[i] << " ";

        cout << "\n";
        return;
    }
    

   for (int i = index; i <= n; i++) {
            list.push_back(i);
            combination(depth+1, i+1);
            list.pop_back();
    }
}

int main() {
    cin >> n >> r;

    combination(0, 1);
    return 0;
}