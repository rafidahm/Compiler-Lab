
// 3. Convert this ε-NFA to a DFA:
// States: {q0, q1, q2}
// Start: q0
// Final: q2
// Transitions:
// q0 --ε--> q1
// q1 --a--> q1
// q1 --b--> q2

#include <iostream>
using namespace std;

int main() {
    char s[1000];

    while (cin >> s) {
        int state = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];

            if (state == 0) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else state = 3;
            }
            else if (state == 1) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else state = 3;
            }
            else if (state == 2) {
                if (c == 'a') state = 3;
                else if (c == 'b') state = 3;
                else state = 3;
            }
            else state = 3;
        }

        if (state == 2) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }

    return 0;
}
