#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N;
    int numOfPrime = 0;
    cin >> N;
    while (N--) {
        int isPrime;
        int count = 0;
        cin >> isPrime;
        for (int i = 1; i <= isPrime; i++) 
            if (isPrime % i == 0) count++;
        
        if (count == 2) numOfPrime++;
    }
    cout << numOfPrime << endl;
    return 0;
}