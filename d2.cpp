
// 2. Create a lexical analyzer that counts the total number of identifiers in a given C/C++ program. 3. Modify your lexical analyzer to remove comments (// and /* */) and return the cleaned code.
#include <iostream>
#include <cstring>
using namespace std;

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char s[1000];
    int identifierCount = 0;

    while (cin.getline(s, 1000)) {
        int i = 0;
        char token[100];
        int t;

        while (s[i] != '\0') {
            if (s[i] == ' ' || s[i] == '\t' || s[i]=='\n') {
                i++;
                continue;
            }

            if (isLetter(s[i])) {
                t = 0;
                while (isLetter(s[i]) || isDigit(s[i])) {
                    token[t++] = s[i++];
                }
                token[t] = '\0';

                if (!(strcmp(token,"int")==0 || strcmp(token,"float")==0 ||
                      strcmp(token,"if")==0 || strcmp(token,"else")==0 ||
                      strcmp(token,"for")==0 || strcmp(token,"while")==0 ||
                      strcmp(token,"return")==0))
                    identifierCount++;

                continue;
            }
            i++;
        }
    }

    cout << "Total Identifiers: " << identifierCount << endl;
    return 0;
}
