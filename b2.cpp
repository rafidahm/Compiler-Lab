// 2. Given the NFA for the regular expression: (a|b)*abb
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
                else if (c == 'b') state = 0;
                else state = 4;
            }
            else if (state == 1) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else state = 4;
            }
            else if (state == 2) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 3;
                else state = 4;
            }
            else if (state == 3) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 2;
                else state = 4;
            }
            else state = 4;
        }

        if (state == 3) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }

    return 0;
}
