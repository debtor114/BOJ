#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    vector <int> v, modv;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    
    int mini = v[1] - v[0];
    
    vector <int> factor;

    for (int i = 2; i <= mini/2; i++) {
        if (mini % i == 0) factor.push_back(i);
    }
    factor.push_back(mini);

    vector <int> ans;
    for (int i = 0; i < factor.size(); i++) {
        int flag = 1;
        for (int j = 0; j < N-1; j++) {
            if (v[j] % factor[i] != v[j+1] % factor[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) ans.push_back(factor[i]);
    }

    

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;


}