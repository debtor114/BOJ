#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int numOfPrime = 0;
    vector <int> prime;


    while (M != N+1) {
        int count = 0;
        for (int i = 1; i <= M; i++) 
            if (M % i == 0) count++;
        
        if (count == 2) {
            numOfPrime++;
            prime.push_back(M);
        }
        M++;
    }
    
    if (prime.empty()) cout << "-1" << endl;
    else {
        int sum = 0;
        for (int i = 0; i < prime.size(); i++)
            sum += prime[i];

        int min = *min_element(prime.begin(), prime.end());
        
        cout << sum << endl << min << endl;
    }

    return 0;
}