#include <iostream>
#include <string>

using namespace std;

int main() {
    string key, pt;
    getline(cin, pt);
    getline(cin, key);

    for (int i = 0; i < pt.length(); i++) {
        if (pt[i] != ' ') {
            pt[i] = (pt[i]-key[i%key.length()]);
            


        }
    }

}