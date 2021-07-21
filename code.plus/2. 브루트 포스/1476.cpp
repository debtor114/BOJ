#include <iostream>

using namespace std;

int main() {
    int E, S, M;
    int A = 0, B = 0, C = 0;
    cin >> E >> S >> M;

    for (int i = 1; i <= 7980; i++) {
        A++;
        if (A > 15) A -= 15;
        B++;
        if (B > 28) B -= 28;
        C++;
        if (C > 19) C -= 19;

        if (E == A && S == B && M == C) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}