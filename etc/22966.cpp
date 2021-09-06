#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector < pair <int, string> > v;
    for (int i = 0; i < N; i++) {
        string prob;
        int hard;

        cin >> prob >> hard;
        v.push_back(make_pair(hard, prob));
    }

    sort (v.begin(), v.end());
    cout << v[0].second << "\n";
    return 0;
}