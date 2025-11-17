
// 2. Validate whether a string is a valid integer constant:
// Examples to test: 12, 0034, -45, abc.
#include <iostream>
using namespace std;

int main() {
    char s[1000];

    while (cin >> s) {
        int valid = 1;
        int i = 0;

        if (s[0] == '-') i = 1;

        if (s[i] == '\0') valid = 0;

        for (; s[i] != '\0'; i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                valid = 0;
                break;
            }
        }

        if (valid) cout << s << " : Valid Integer\n";
        else cout << s << " : Invalid Integer\n";
    }

    return 0;
}
