#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int temp;
    vector <int> arr, ascend, descend;
    for (int i = 0; i < 8; i++) {
        cin >> temp;
        arr.push_back(temp);
        ascend.push_back(temp);
        descend.push_back(temp);
    }

    sort(ascend.begin(), ascend.end());
    sort(descend.begin(), descend.end(), greater<int>());

    if (arr == ascend) cout << "ascending" << endl;
    else if (arr == descend) cout << "descending" << endl;
    else cout << "mixed" << endl;
    return 0;
}