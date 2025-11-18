
// 2. Create a lexical analyzer that counts the total number of identifiers in a given C/C++ program. 3. Modify your lexical analyzer to remove comments (// and /* */) and return the cleaned code.
#include <iostream>
#include <cstring>
using namespace std;

// Function to check if a character is a letter or underscore
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c == '_');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char s[1000];  // Input line buffer
    int identifierCount = 0;  // Count of identifiers

    while (cin.getline(s, 1000)) {  // Read code line by line
        int i = 0;  // Index for traversing the line
        char token[100];  // Temporary storage for token
        int t;  // Index for token array

        while (s[i] != '\0') {  // Loop through the line

            // Skip spaces, tabs, newlines
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
                i++;
                continue;
            }

            // Start of a token (letter or underscore)
            if (isLetter(s[i])) {
                t = 0;  // Start token
                while (isLetter(s[i]) || isDigit(s[i])) {  // Collect token
                    token[t++] = s[i++];
                }
                token[t] = '\0';  // End token

                // Check if token is NOT a keyword
                if (!(strcmp(token,"int")==0 || strcmp(token,"float")==0 ||
                      strcmp(token,"if")==0 || strcmp(token,"else")==0 ||
                      strcmp(token,"for")==0 || strcmp(token,"while")==0 ||
                      strcmp(token,"return")==0)) {
                    identifierCount++;  // Count as identifier
                }

                continue;  // Go to next token
            }

            // Skip other characters
            i++;
        }
    }

    cout << "Total Identifiers: " << identifierCount << endl;
    return 0;
}



// Inside the while loop, before processing the line
if (s[i] == '/' && s[i+1] == '/') break; // single-line comment, ignore rest
if (s[i] == '/' && s[i+1] == '*') {      // multi-line comment
    i += 2;
    while (!(s[i] == '*' && s[i+1] == '/') && s[i] != '\0') i++;
    if (s[i] == '*' && s[i+1] == '/') i += 2;
    continue;
}

