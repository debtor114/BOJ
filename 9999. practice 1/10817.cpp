#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    int arr[3];
    
    scanf("%d %d %d", &a, &b, &c);
    
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    
    sort(arr, arr + 3);
    
    printf("%d", arr[1]);
}