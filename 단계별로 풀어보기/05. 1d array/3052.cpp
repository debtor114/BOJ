#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector <int> box, mods;
    int temp;

    for (int i = 0; i < 10; i++) {
        cin >> temp;
        box.push_back(temp % 42);
    }

    sort(box.begin(), box.end());
    box.erase(unique(box.begin(), box.end()), box.end());

    cout << box.size() << endl;
    return 0;
}