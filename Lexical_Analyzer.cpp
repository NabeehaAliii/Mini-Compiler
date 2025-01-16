#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

/*
    Lexical Analyzer for Simple Programming Language
    Author: Nabeeha Ali
    Description:
    This program reads a source code file and performs lexical analysis
    to identify and classify tokens such as keywords, identifiers, constants,
    operators, and punctuators. It reports lexical errors for unrecognized symbols.

    File: test_code.txt (contains the source code for analysis)
*/

string keywords[] = {"int", "char", "if", "else", "for", "while", "do", "return"};
char operators[] = {'+', '-', '*', '/', '=', '<', '>'}; // Operators to recognize
char punctuators[] = {'(', ')', '{', '}', ',', ';'};         // Punctuators to recognize

bool isKeyword(string word) {
    for (string keyword : keywords) {
        if (word == keyword)
            return true;
    }
    return false;
}

bool isOperator(char ch) {
    for (char op : operators) {
        if (ch == op)
            return true;
    }
    return false;
}

bool isPunctuator(char ch) {
    for (char punc : punctuators) {
        if (ch == punc)
            return true;
    }
    return false;
}

bool isConstant(string word) {
    // Check if the word is a numeric constant
    for (char ch : word) {
        if (!isdigit(ch))
            return false;
    }
    return !word.empty();
}

bool isSpace(char ch) {
    return isspace(ch);
}

void lexicalAnalyzer(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!\n" << endl;
        return;
    } else {
        cout << "File is Accessed Successfully. Now working on it in Lexical Analyzer Phase!\n";
    }

    char ch;
    string word = "";
    cout << "Tokens Identified:\n";

    while (file.get(ch)) {
        if (isalpha(ch)) {
            // Build identifier or keyword
            word += ch;
        } else if (isdigit(ch)) {
            // Build numeric constant
            word += ch;
        } else if (isOperator(ch)) {
            // Finalize previous token
            if (!word.empty()) {
                if (isKeyword(word))
                    cout << "Keyword: " << word << endl;
                else if (isConstant(word))
                    cout << "Constant: " << word << endl;
                else
                    cout << "Identifier: " << word << endl;
                word = "";
            }
            // Print operator
            cout << "Operator: " << ch << endl;
        } else if (isPunctuator(ch)) {
            // Finalize previous token
            if (!word.empty()) {
                if (isKeyword(word))
                    cout << "Keyword: " << word << endl;
                else if (isConstant(word))
                    cout << "Constant: " << word << endl;
                else
                    cout << "Identifier: " << word << endl;
                word = "";
            }
            // Print punctuator
            cout << "Punctuator: " << ch << endl;
        } else if (isSpace(ch)) {
            // Finalize previous token
            if (!word.empty()) {
                if (isKeyword(word))
                    cout << "Keyword: " << word << endl;
                else if (isConstant(word))
                    cout << "Constant: " << word << endl;
                else
                    cout << "Identifier: " << word << endl;
                word = "";
            }
        } else if (ch == '\'') {
            // Flag single quotes as lexical errors
            cout << "Lexical Error: Unrecognized symbol: " << ch << "\n";
            break; 
        } else {
            // Handle other lexical errors
            cout << "Lexical Error: Unrecognized symbol: " << ch << "\n";
            break; 
        }
    }

    // Check the last word
    if (!word.empty()) {
        if (isKeyword(word))
            cout << "Keyword: " << word << endl;
        else if (isConstant(word))
            cout << "Constant: " << word << endl;
        else
            cout << "Identifier: " << word << endl;
    }

    file.close();
}

int main() {
    string filename = "test_code.txt";

    // Author Information
    cout << "Lexical Analyzer by Nabeeha Ali\n";
    cout << "-------------------------------\n";

    // Call lexical analyzer
    lexicalAnalyzer(filename);

    return 0;
}
