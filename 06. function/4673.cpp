#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//int f[10001], onetoman[10001], ans[10001];
vector <int> f, onetoman, ans;

void selfNumGenerator (int n) {    
    if (n < 10) {
        f.push_back(2*n);
    }

    if (n >= 10 && n < 100) {
        f.push_back(n + n/10 + n%10);
    }

    if (n >= 100 && n < 1000) {
        f.push_back(n + n/100 + n/10 % 10 + n%10);
    }

    if (n >= 1000 && n < 10000) {
        f.push_back(n + n/1000 + n/100 % 10 + n/10 % 10 + n%10);
    }
}

int main() {

    for (int i = 0; i < 10001; i++) {
        onetoman.push_back(i);
        selfNumGenerator(i);
    }
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    set_difference(onetoman.begin(), onetoman.end(), f.begin(), f.end(), back_inserter(ans));

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= 10000)
            break;
        cout << ans[i] << endl;
    }

    return 0;
}