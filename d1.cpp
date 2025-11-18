// Implement a Lexical Analyzer:
// 1. Write a lexical analyzer that identifies the following tokens from input text:
// ∙ Keywords: int, float, if, else
// ∙ Identifiers
// ∙ Numbers
// ∙ Operators: + - * / =
// Test on:
// int x = y + 45;
#include <iostream>
#include <cstring>
using namespace std;

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char s[1000];  // Input string
    cin.getline(s, 1000);  // Read a full line of input

    int i = 0;  // Index to traverse input
    char token[100];  // Temporary array to store a token
    int t;  // Index for token array

    while (s[i] != '\0') {  // Loop until end of string

        // Skip whitespace (space or tab)
        if (s[i] == ' ' || s[i] == '\t') {
            i++;
            continue;
        }

        // Check for keywords or identifiers
        if (isLetter(s[i])) {
            t = 0;  // Start of token
            // Build token: letters followed by letters/digits
            while (isLetter(s[i]) || isDigit(s[i])) {
                token[t++] = s[i++];
            }
            token[t] = '\0';  // Null terminate the token

            // Check if token is a keyword
            if (strcmp(token, "int") == 0 ||
                strcmp(token, "float") == 0 ||
                strcmp(token, "if") == 0 ||
                strcmp(token, "else") == 0)
                cout << token << " : Keyword\n";
            else
                cout << token << " : Identifier\n";  // Else it is an identifier

            continue;  // Move to next character
        }

        // Check for numbers
        if (isDigit(s[i])) {
            t = 0;  // Start of token
            while (isDigit(s[i])) {
                token[t++] = s[i++];
            }
            token[t] = '\0';
            cout << token << " : Number\n";  // Print number token
            continue;
        }

        // Check for operators
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '=') {
            cout << s[i] << " : Operator\n";
            i++;  // Move to next character
            continue;
        }

        // Check for semicolon
        if (s[i] == ';') {
            cout << s[i] << " : Semicolon\n";
            i++;
            continue;
        }

        // If character is unknown, skip it
        i++;
    }

    return 0;
}

