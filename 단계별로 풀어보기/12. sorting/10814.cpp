#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

bool comp(const pair <int, string> &p1, const pair <int, string> &p2) {
    return p1.first < p2.first;

}

int main() {

    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    int age;
        string name;
    vector <pair <int, string>> v;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }

    stable_sort(v.begin(), v.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}