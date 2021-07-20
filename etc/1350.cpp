// 항상 데이터의 크기를 보고 long long인지 int인지, 항상 long long으로 쓰는게 좋을지도?

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, cluster, need;
    vector <long long> v;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    cin >> cluster;

    need = 0;
    for (int i = 0; i < N; i++) {
        need += (int)ceil((double)v[i] / cluster);
        
    }

    long long ans = cluster * need;

    cout << ans << "\n";
    return 0;

}