#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector <int> v, list;

void combination (int depth, int index) {
    if (depth == 6) {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;

        return;
    }


    for (int i = index; i < N; i++) {
        list.push_back(v[i]);
        combination(depth+1, i+1);
        list.pop_back();
    }

}

int main () {
    while (1) {
        cin >> N;
        if (N == 0) break;
        
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }

        combination(0, 0);
        cout << endl;

        v.clear();
        list.clear();
    }

    return 0;
}