#include <iostream>
#include <map>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    map <int, int> m;

    int sum  = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                sum = i+j+k;
                if (m.find(sum) == m.end()) m[sum] = 1;
                else m[sum]++;
            }
        }
    }
    
    int max_first = 10000000, max_second = -1;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == max_second) {
            if (iter->first > max_first) continue;

            else {
                max_first = iter->first;
                max_second = iter->second;
            }
        }

        else if (iter->second > max_second) {
                max_first = iter->first;
                max_second = iter->second;         
        }
    }
    
    cout << max_first << endl;
    return 0;
    
}