#include <iostream>
#include <string>

using namespace std;

string change2to8(string s)
{
    int result = 0;

    for (int i = 0; i < s.size(); i++)
        result = result * 2 + (s[i] - '0');

    return to_string(result);
}

int main() {
    string s;
    cin >> s;

    string ans;
    
    int r = s.size() % 3;

    // 길이를 3으로 나눈 나머지가 0이 아닌경우 먼저 그 만큼만 떼서 변환하기
    if(r != 0)
        ans.append(change2to8(s.substr(0, r)));

    for (int i = r; i < s.size(); i+=3)
        ans.append(change2to8(s.substr(i, 3)));

    cout << ans << endl;
}