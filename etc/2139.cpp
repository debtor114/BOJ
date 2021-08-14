#include <iostream>

using namespace std;

int main() {
    int d1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    while (1) {
        int d = -1, m =-1, y=-1, result = 0, flag = 0;
        cin >> d >> m >> y;
        if (!d && !m && !y) break;

        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
			flag = 1;
		}


        if (flag) for (int i = 0; i < m-1; i++) result += d2[i];
        else for (int i = 0; i < m-1; i++) result += d1[i];
        
        result += d;
        cout << result << endl;

    }
}