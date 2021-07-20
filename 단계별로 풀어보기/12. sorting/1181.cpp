#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <string>

using namespace std;

bool comp(const string &v1, const string &v2) {
    if (v1.length() == v2.length()) return v1 < v2;
    return v1.length() < v2.length();
}

int main() {
    int N;
    vector < string > v;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    // sort(v.begin(), v.end(), comp);
    // v.erase(unique(v.begin(), v.end()));

    // vector <string>::iterator iter;
    // for (iter = v.begin(); iter != v.end(); iter++) {
    //     cout << *iter << endl;
    // }

    vector<string>::iterator iter;
    vector<string>::iterator end_iter;

    sort(v.begin(), v.end(), comp);
    end_iter = unique(v.begin(), v.end());

    for (iter = v.begin(); iter != end_iter; iter++)
        cout << *iter << endl;

    return 0;
}