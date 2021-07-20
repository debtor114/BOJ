#include <iostream>

using namespace std;

int main() {
    int arr[20000];
    int N;

    for (int i = 0; i < 20000; i++) 
        arr[i] = 3*i*i + 3*i + 2;

    cin >> N;
    for (int i = 0; ; i++) {
        if (N < arr[i])
            break;
    }

    int i = 0;
    int count = 1;
    
    while (arr[i] <= N) {
        if (N == 1)
            break;

        count++;
        i++;
    }

    cout << count << endl;
    return 0;
    
}