#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int sum = 0;
    vector <int> t;

    cin  >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A' || s[i] ==  'B' || s[i] ==  'C')  t.push_back(3);
        else if (s[i] == 'D' || s[i] ==  'E' || s[i] ==  'F') t.push_back(4);
        else if (s[i] == 'G' || s[i] ==  'H' || s[i] ==  'I') t.push_back(5);
        else if (s[i] == 'J' || s[i] ==  'K' || s[i] ==  'L') t.push_back(6);
        else if (s[i] == 'M' || s[i] ==  'N' || s[i] ==  'O') t.push_back(7);
        else if (s[i] == 'P' || s[i] ==  'Q' || s[i] ==  'R' || s[i] ==  'S') t.push_back(8);
        else if (s[i] == 'T' || s[i] ==  'U' || s[i] ==  'V') t.push_back(9);
        else if (s[i] == 'W' || s[i] ==  'X' || s[i] ==  'Y' || s[i] ==  'Z') t.push_back(10);
    }

    for (int i = 0; i < t.size(); i++) {
        sum += t[i];
    }
        
    cout << sum << endl;
    return 0;

}