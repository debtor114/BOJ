#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector < string > nums;
    vector < int > numbers;
    vector <char> ops;

    string s1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= 57 && s[i] >= 48) {
            s1.push_back(s[i]);

        }
        else {
            ops.push_back(s[i]);
            nums.push_back(s1);
            
            s1 = "";
        };
        
    }
    nums.push_back(s1);

    for (int i = 0; i < nums.size(); i++) {
        numbers.push_back(stoi(nums[i]));
    }

    int sum = numbers[0];

    int flag = 1;

    for (int i = 1; i < numbers.size(); i++) {
        if (ops[i-1] == '-') flag = 0;

        if (flag) sum += numbers[i];
        else sum -= numbers[i];
    }

    cout << sum << endl;
    return 0;
}