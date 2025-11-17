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

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char s[1000];
    cin.getline(s, 1000);

    int i = 0;
    char token[100];
    int t;

    while (s[i] != '\0') {
        if (s[i] == ' ' || s[i] == '\t') {
            i++;
            continue;
        }

        if (isLetter(s[i])) {
            t = 0;
            while (isLetter(s[i]) || isDigit(s[i])) {
                token[t++] = s[i++];
            }
            token[t] = '\0';

            if (strcmp(token, "int") == 0 ||
                strcmp(token, "float") == 0 ||
                strcmp(token, "if") == 0 ||
                strcmp(token, "else") == 0)
                cout << token << " : Keyword\n";
            else
                cout << token << " : Identifier\n";

            continue;
        }

        if (isDigit(s[i])) {
            t = 0;
            while (isDigit(s[i])) {
                token[t++] = s[i++];
            }
            token[t] = '\0';
            cout << token << " : Number\n";
            continue;
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '=') {
            cout << s[i] << " : Operator\n";
            i++;
            continue;
        }

        if (s[i] == ';') {
            cout << s[i] << " : Semicolon\n";
            i++;
            continue;
        }

        i++;
    }

    return 0;
}
