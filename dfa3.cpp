
// . Create a DFA that accepts only those strings over {a, b} where no two consecutive b’s appear.  (TC: abba, ababab, abbba, baaab)
#include <iostream>
#include <string>
using namespace std;

int main() {

    while(true) {
        string s;
        cout << "Enter a string over {a, b} (type 'exit' to stop): ";
        cin >> s;

        if(s == "exit") break;  // exit the loop

        int state = 0; // 0 = no previous b, 1 = previous was b, 2 = reject
        bool invalid = false;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];

            if(c != 'a' && c != 'b') {
                cout << "Invalid input\n";
                invalid = true;
                break;
            }

            if(state == 0) {
                if(c == 'a') state = 0;
                else if(c == 'b') state = 1;
            }
            else if(state == 1) {
                if(c == 'a') state = 0;
                else if(c == 'b') { state = 2; break; } // two consecutive b's
            }
        }

        if(invalid) continue;

        if(state == 0 || state == 1)
            cout << "ACCEPT\n";
        else
            cout << "REJECT\n";
    }

    return 0;
}

