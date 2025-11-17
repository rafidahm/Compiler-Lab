// 2. Convert the regular expression: (ab+b)*a
#include <iostream>
using namespace std;

int main() {
    char s[1000];
    while (cin >> s) {
        int state = 0;
        for (int i = 0; s[i] != '\0'; ++i) {
            char c = s[i];
            if (state == 0) {
                if (c == 'a') state = 1;
                else if (c == 'b') state = 0;
                else state = 2;
            }
            else if (state == 1) {
                if (c == 'a') state = 2;
                else if (c == 'b') state = 0;
                else state = 2;
            }
            else state = 2;
        }
        if (state == 1) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }
    return 0;
}

