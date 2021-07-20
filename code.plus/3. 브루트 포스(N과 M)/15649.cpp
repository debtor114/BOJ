#include <iostream>
#include <vector>

using namespace std;

int n, r;
vector <int> list;

int visit[100];

void permutation(int depth) {



    
    if (depth == r) {
        for (int i = 0; i < r; i++)
            cout << list[i] << " ";

        cout << "\n";
        return;
    }
    

   for (int i = 1; i <= n; i++) {
       if (!visit[i]) {
            list.push_back(i);
            visit[i] = 1;
            permutation(depth+1);
            list.pop_back();
            visit[i] = 0;
        }
    }
}

int main() {
    cin >> n >> r;

    permutation(0);
    return 0;
}