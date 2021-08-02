#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector <string> v;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    // for (int i = 0; i < v.size(); i++)
    //     sort(v[i].begin(), v[i].end());

    string str = v[0];
    for (int i = 1; i < N; i++) {
        set_intersection(str.begin(), str.end(), v[i].begin(), v[i].end(), str.begin());
        cout << str << " " << v[i] << endl;
    }
    
    cout << str << endl;
    return 0;
    
}