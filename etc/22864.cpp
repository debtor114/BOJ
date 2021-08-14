#include <iostream>

using namespace std;

int main() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int hours = 0, works = 0, capa = 0;
    if (A > M) cout << works << "\n";
    else {
        while (hours != 24) {
            if (capa+A <= M) {
                capa += A;
                works += B;
            }

            else {
                capa -= C;
                if (capa < 0) capa = 0;

            }
            hours++;
        }
        cout << works << "\n";
    }

    return 0;
    
    
}