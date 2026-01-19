#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

map<char, vector<string>> grammar;   // Non-terminal -> productions
map<char, set<char>> FIRST, FOLLOW;  // FIRST and FOLLOW sets
set<char> nonTerminals, terminals;

// Function to check if a symbol is non-terminal
bool isNonTerminal(char c) {
    return nonTerminals.count(c) > 0;
}

// Compute FIRST of a symbol
set<char> computeFirst(char symbol);

// Compute FIRST of a string
set<char> firstOfString(const string &str) {
    set<char> result;
    bool epsilon = true;

    for (char c : str) {
        set<char> temp = computeFirst(c);
        result.insert(temp.begin(), temp.end());
        if (temp.count('ε')) {
            result.erase('ε'); // remove epsilon temporarily
        } else {
            epsilon = false;
            break;
        }
    }

    if (epsilon) result.insert('ε');
    return result;
}

// Compute FIRST of a symbol
set<char> computeFirst(char symbol) {
    if (!isNonTerminal(symbol)) {
        return {symbol}; // terminal
    }

    set<char> result;
    for (auto prod : grammar[symbol]) {
        set<char> temp = firstOfString(prod);
        result.insert(temp.begin(), temp.end());
    }
    return result;
}

// Compute FOLLOW sets
void computeFollow(char start) {
    FOLLOW[start].insert('$'); // start symbol gets $
    bool changed = true;

    while (changed) {
        changed = false;
        for (auto nt : nonTerminals) {
            for (auto prod : grammar[nt]) {
                for (int i = 0; i < prod.size(); i++) {
                    char B = prod[i];
                    if (!isNonTerminal(B)) continue;

                    set<char> followB;
                    if (i + 1 < prod.size()) {
                        string beta = prod.substr(i + 1);
                        set<char> firstBeta = firstOfString(beta);
                        bool hadEpsilon = firstBeta.count('ε');
                        firstBeta.erase('ε');
                        followB.insert(firstBeta.begin(), firstBeta.end());
                        if (hadEpsilon) {
                            followB.insert(FOLLOW[nt].begin(), FOLLOW[nt].end());
                        }
                    } else {
                        followB.insert(FOLLOW[nt].begin(), FOLLOW[nt].end());
                    }

                    int oldSize = FOLLOW[B].size();
                    FOLLOW[B].insert(followB.begin(), followB.end());
                    if (FOLLOW[B].size() > oldSize) changed = true;
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter grammar in format: NonTerminal=production1|production2\n";
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        char nt = input[0];
        nonTerminals.insert(nt);
        string rhs = input.substr(2);
        string prod;
        for (char c : rhs) {
            if (c != '|') prod += c;
            if (c == '|' || &c == &rhs.back()) {
                grammar[nt].push_back(prod);
                prod = "";
            }
        }
    }

    // Compute FIRST sets
    for (auto nt : nonTerminals) {
        FIRST[nt] = computeFirst(nt);
    }

    // Compute FOLLOW sets
    computeFollow(*nonTerminals.begin());

    // Display FIRST sets
    cout << "\nFIRST sets:\n";
    for (auto nt : nonTerminals) {
        cout << nt << " : { ";
        for (char c : FIRST[nt]) cout << c << " ";
        cout << "}\n";
    }

    // Display FOLLOW sets
    cout << "\nFOLLOW sets:\n";
    for (auto nt : nonTerminals) {
        cout << nt << " : { ";
        for (char c : FOLLOW[nt]) cout << c << " ";
        cout << "}\n";
    }

    return 0;
}
