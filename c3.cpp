
// 3. Construct an NFA using Thompson’s Algorithm for: a*|b(a|b)
#include <iostream>
using namespace std;

int main() {
    char s[100];
    while (cin >> s) {
        int i = 0;
        int ok = 0;

        int onlyA = 1;
        while (s[i] != '\0') {
            if (s[i] != 'a') onlyA = 0;
            i++;
        }
        if (onlyA == 1) ok = 1; // If all are 'a', ACCEPT

        i = 0;
        if (s[0] == 'b' && (s[1] == 'a' || s[1] == 'b') && s[2] == '\0') ok = 1;

        if (ok == 1) cout << "ACCEPT\n";
        else cout << "REJECT\n";
    }
    return 0;
}

