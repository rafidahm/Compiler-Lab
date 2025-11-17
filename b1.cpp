// NFA to DFA Conversion:
// 1. Convert the following NFA to DFA:
// State
// B
// *C
// 0
// 1

// B
// C
// →A A, B A
// C
// C


#include <iostream>
using namespace std;

int main() {
    char s[1000];

    while (cin >> s) {
        int state = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];

            if (state == 0) {
                if (c == '0') state = 0;
                else if (c == '1') state = 1;
                else state = 3;
            }
            else if (state == 1) {
                if (c == '0') state = 1;
                else if (c == '1') state = 2;
                else state = 3;
            }
            else if (state == 2) {
                if (c == '0') state = 2;
                else if (c == '1') state = 2;
                else state = 3;
            }
            else state = 3;
        }

        if (state == 2) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }

    return 0;
}
