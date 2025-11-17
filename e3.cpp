
// 3. Validate email format using a regular expression.
#include <iostream>
#include <regex>
using namespace std;

int main() {
    string email;
    regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    while (cin >> email) {
        if (regex_match(email, pattern))
            cout << email << " : Valid Email\n";
        else
            cout << email << " : Invalid Email\n";
    }

    return 0;
}
