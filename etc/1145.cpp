#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
  
    if (a < b) swap(a, b);
	
    int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int LCM (int a, int b) {
    return a*b / gcd(a, b);

}
 
int main() {

    vector <int> list;

    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    int min = 1000000;
    int ans;

    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                ans = LCM(list[i], LCM(list[j], list[k]));
                //printf("LCM[%d][%d][%d]: %d\n",i, j, k, ans);
                if (min > ans) min = ans;
            }
        }
    }

    cout << min << endl;
    return 0;
}