#include <cstdio>
#include <vector>

using namespace std;

 int main() {
     int N;
     vector <int> v;
     scanf("%d", &N);
     for (int i = 0; i < N; i++) {
         int temp;
         scanf("%d", &temp);
         v.push_back(temp);
     }

     for (int i = 1; i < v.size(); i++) {
         int a = v[0];
         int b = v[i];
        

        while (1) {
            int r = a%b;
            if (r == 0) break;
            a = b;
            b = r;
        }

        printf("%d/%d\n", v[0]/b, v[i]/b);
     }
     return 0;
     
 }