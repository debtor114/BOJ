#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int temp;
    vector <int> arr;

    for (int i = 0; i < 9; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    int index = distance(arr.begin(), max_element(arr.begin(), arr.end())) + 1;
    int maxNum = *max_element(arr.begin(), arr.end());

    printf("%d\n%d\n", maxNum, index);
    return 0;
}