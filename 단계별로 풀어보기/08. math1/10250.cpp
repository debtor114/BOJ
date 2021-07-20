#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;

    while (T--) {
        cin >> H >> W >> N;
        int floor, room;

        if (N % H == 0) {
            floor = H;
            room = N / H;
        }

        else {
            floor = N % H;
            room = N / H + 1;
        }
        
        if (room < 10)
            cout << floor << "0" << room << endl;

        else
            cout << floor << room << endl; 

    }
    return 0;
}