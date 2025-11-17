// e) Regular Expression to Token Validator:
// 1. Write a program to validate whether an input string is a valid identifier.
// Rules:
// -Must start with a letter or underscore
// -Can contain letters, digits, and underscores
// -Examples to test: _temp, 9abc, value1, __id.
#include <iostream>
using namespace std;

int main() {
    char s[1000];

    while (cin >> s) {
        int valid = 1;
        int i = 0;

        if (!( (s[0] >= 'a' && s[0] <= 'z') ||
               (s[0] >= 'A' && s[0] <= 'Z') ||
               s[0] == '_' )) {
            valid = 0;
        }

        for (i = 1; s[i] != '\0'; i++) {
            if (!((s[i] >= 'a' && s[i] <= 'z') ||
                  (s[i] >= 'A' && s[i] <= 'Z') ||
                  (s[i] >= '0' && s[i] <= '9') ||
                  s[i] == '_')) {
                valid = 0;
                break;
            }
        }

        if (valid) cout << s << " : Valid Identifier\n";
        else cout << s << " : Invalid Identifier\n";
    }

    return 0;
}
