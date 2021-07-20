#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int N, M;
deque <int> s;
vector < pair <int, int> > targets;



int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        s.push_back(i);

    for (int i = 1; i <= M; i++) {
        int target;
        scanf("%d", &target);
        targets.push_back(make_pair(target, target));
    }
    
    int count = 0;
    while (!targets.empty()) {
        int x;
            if (abs(1 - targets.front().second) > 1+s.size() - targets.front().second)
                x = 1+s.size() - targets.front().second;

            else x = 1 - targets.front().second;

            if (x < 0) {
                for (int i = 0; i < -x; i++) {
                    s.push_back(s.front());
                    s.pop_front();  
                    count++;   
                }    
            }

            else {
                for (int i = 0; i < x; i++) {
                    s.push_front(s.back());
                    s.pop_back();   
                    count++;                 
                }
            }

            for (int k = 1; k < targets.size(); k++) {
                targets[k].second += x-1;
                if (targets[k].second <= 0) targets[k].second += s.size();
                if (targets[k].second > s.size()) targets[k].second -= s.size();
            }

            s.pop_front();
            targets.erase(targets.begin());
            
    }

    printf("%d\n", count);
    return 0;
    
}