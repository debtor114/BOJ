#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, counts;
vector <int> v;
vector <string> s;

void permutation(int depth, int first_num, int last_num) {
    if (first_num == last_num || depth == m) {
        string str = "";
        for (int i = 0; i < m; i++) {
            str.append(to_string(v[i]));
            str.append(" ");

        }
        s.push_back(str);
        counts++;
    }
    
    else {
        for (int i = first_num; i <= last_num || depth == m; i++) {
            swap(v[first_num], v[i]);
            permutation(depth+1, first_num+1, last_num);
            swap(v[first_num], v[i]);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        v.push_back(i+1);
    
    permutation(0, 0, n-1);
    //cout << counts << endl;
    sort(s.begin(), s.end());
    for (vector<string>::iterator iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << "\n";

    return 0;
}