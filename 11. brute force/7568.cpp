#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int T;
    vector <int> rank;
    vector < pair < pair <int, int> , int> > dungchi;
    cin >> T;
    int temp = T;
    while (temp--) {
        int w, h;
        cin >> w >> h;
        dungchi.push_back(make_pair(make_pair(w, h), 0));
    }

    int count = 0;
    for (int i = 0; i < dungchi.size(); i++) {
        for (int j = i+1; j < dungchi.size(); j++) {
            if (dungchi[i].first.first > dungchi[j].first.first && dungchi[i].first.second > dungchi[j].first.second) 
                dungchi[i].second++;

            else if (dungchi[i].first.first < dungchi[j].first.first && dungchi[i].first.second < dungchi[j].first.second)
                dungchi[j].second++;

            else {
                dungchi[i].second++;
                dungchi[j].second++;
            }
        }
    }

    for (int i = 0; i < dungchi.size(); i++) 
        dungchi[i].second = T - dungchi[i].second;

    for (int i = 0; i < dungchi.size(); i++)
        cout << dungchi[i].second << endl;

    return 0;
}