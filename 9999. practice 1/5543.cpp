#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector <int> burger, beverage;
    int sum = 0;
    int temp;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &temp);
        burger.push_back(temp);
    }

    for (int i = 0; i < 2; i++) {
        scanf("%d", &temp);
        beverage.push_back(temp);
    }

    sum = *min_element(burger.begin(), burger.end()) + *min_element(beverage.begin(), beverage.end()) - 50;
    printf("%d\n", sum);
    return 0;
    
}