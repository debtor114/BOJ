#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector <int> v;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    if (prev_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++)
            cout << v[i] << " "; 

    }
    else cout << "-1";
    
    cout << endl;
    return 0;
}