// c) Regular Expression to NFA:
// 1. Construct an NFA for the regular expression: a(b|c)*

#include <iostream>
using namespace std;

int main() {
    char s[100];
    int i = 0;
    int state = 0;

    cin >> s;

    while (s[i] != '\0') {
        if (state == 0) {
            if (s[i] == 'a') state = 1;
            else {
                state = -1;
                break;
            }
        }
        else if (state == 1) {
            if (s[i] == 'b' || s[i] == 'c') state = 1;
            else {
                state = -1;
                break;
            }
        }
        i++;
    }

    if (state == 1) cout << "Accepted\n";
    else cout << "Rejected\n";

    return 0;
}
