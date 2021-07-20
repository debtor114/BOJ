#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string A, B, C;

int main() {

    cin >> A >> B;

    int lengthA = A.length();
    int lengthB = B.length();

    int c = 0;
    while (lengthA > 0 || lengthB > 0)
    {
        int k1, k2 = 0;
        if (lengthA > 0)
            k1 = A[--lengthA] - '0';
        if (lengthB > 0)
            k2 = B[--lengthB] - '0';

        cout << k1 << " " << k2 << endl;
        int res = k1 + k2 + c;
        c = res/10;
        res %= 10;
        char cur = res + '0';
        C += cur;

    }

    if (c > 0) C += c + '0';


    string ans = "";
    for (int i = (int)C.length()-1; i >= 0; --i) {
        ans += C[i];
    }


    return 0;
}