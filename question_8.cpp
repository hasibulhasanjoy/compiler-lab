#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// Function to check if the word is a valid keyword
bool isKeyword(const string &word)
{
    vector<string> keywords = {"int", "float", "double", "char", "if", "else", "for", "while", "do", "return", "break"};
    for (const string &keyword : keywords)
    {
        if (word == keyword)
        {
            return true;
        }
    }
    return false;
}

// Function to check if the word is a valid identifier
bool isIdentifier(const string &word)
{
    if (isdigit(word[0]))
    {
        return false; // Identifiers can't start with a digit
    }
    for (char ch : word)
    {
        if (!isalnum(ch) && ch != '_')
        {
            return false; // Identifiers should only contain alphanumeric characters or underscores
        }
    }
    return true;
}

// Function to check if the word is a valid integer
bool isInteger(const string &word)
{
    for (char ch : word)
    {
        if (!isdigit(ch))
        {
            return false; // Integer should only contain digits
        }
    }
    return true;
}

// Function to check if the word is a valid float
bool isFloat(const string &word)
{
    int dotCount = 0;
    for (char ch : word)
    {
        if (ch == '.')
        {
            dotCount++;
        }
        else if (!isdigit(ch))
        {
            return false; // Float should only contain digits and at most one dot
        }
    }
    return dotCount == 1; // Valid float has exactly one dot
}

// Function to check if the word is an arithmetic operator
bool isArithmeticOperator(const string &word)
{
    return word == "+" || word == "-" || word == "*" || word == "/";
}

// Function to classify the token
void classifyToken(const string &input)
{
    if (isKeyword(input))
    {
        cout << "Keyword" << endl;
    }
    else if (isFloat(input))
    {
        cout << "Float" << endl;
    }
    else if (isInteger(input))
    {
        cout << "Integer" << endl;
    }
    else if (isIdentifier(input))
    {
        cout << "Identifier" << endl;
    }
    else if (isArithmeticOperator(input))
    {
        cout << "Arithmetic Operator" << endl;
    }
    else
    {
        cout << "Unknown" << endl;
    }
}

int main()
{
    string input;
    cout << "Enter a word: ";
    cin >> input;

    classifyToken(input);

    return 0;
}
