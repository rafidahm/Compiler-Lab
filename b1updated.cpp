#include <iostream>
using namespace std;

int main() {
    char s[1000];

    while (cin >> s) {
        int state = 0; // 0 = {A}, 1 = {A,B}, 2 = {A,B,C} accepting, 3 = dead

        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];

            if (state == 0) { // {A}
                if (c == '0') state = 1; // {A,B}
                else if (c == '1') state = 0; // {A}
                else state = 3; // invalid
            }
            else if (state == 1) { // {A,B}
                if (c == '0') state = 2; // {A,B,C}
                else if (c == '1') state = 1; // {A,B}
                else state = 3;
            }
            else if (state == 2) { // {A,B,C} accepting
                if (c == '0' || c == '1') state = 2;
                else state = 3;
            }
            else state = 3; // dead state
        }

        if (state == 2) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }

    return 0;
}

