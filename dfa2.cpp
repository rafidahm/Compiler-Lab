#include <iostream>
#include <string>
using namespace std;

int main() {

    while(true) {
        string s;
        cout << "Enter a binary string (type 'exit' to stop): ";
        cin >> s;

        if(s == "exit") break;   // simple exit

        int state = 0; // 0 = even number of 1s, 1 = odd number of 1s

        bool invalid = false;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            if(c != '0' && c != '1') {
                cout << "Invalid input\n";
                invalid = true;
                break;
            }

            if(c == '1') {
                state = 1 - state;  // toggle between even/odd
            }
        }

        if(invalid) continue;

        if(state == 0)
            cout << "Accepted\n";
        else
            cout << "Rejected\n";
    }

    return 0;
}
