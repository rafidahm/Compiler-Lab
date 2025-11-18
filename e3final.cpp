#include <iostream>
#include <regex>
using namespace std;

int main() {
    string email;
    // Domain after @ must be only letters, then dot, then TLD
    regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z]+\\.[a-zA-Z]{2,}$");

    cout << "Enter emails to check (type 'exit' to stop):\n";

    while (true) {
        cin >> email;

        if (email == "exit") break;  // stop the loop

        if (regex_match(email, pattern))
            cout << email << " : Valid Email\n";
        else
            cout << email << " : Invalid Email\n";
    }

    return 0;
}

