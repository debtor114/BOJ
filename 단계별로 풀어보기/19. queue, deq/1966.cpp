#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, target;
        queue < pair <int, int> > q;

        cin >> N >> target;

        vector <int> v;
        for (int i = 0; i < N; i++) {
            int prior;
            cin >> prior;
            v.push_back(prior);
            q.push({i, prior});
        }

        sort(v.begin(), v.end(), greater<int>());

        int k = 0;
        vector <int> printOrder;

        while (!q.empty()) {
            if (q.front().second == v[k]) {
                printOrder.push_back(q.front().first);
                k++;
                q.pop();
            }

            else {
                q.push(q.front());
                q.pop();
            }
        }

        for (int i = 0; i < printOrder.size(); i++) {
            if (printOrder[i] == target) {
                cout << i+1 << endl;
                break;
            }
        }
    }
    return 0;
}