#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if a string is a keyword
bool isKeyword(const string &str)
{
    vector<string> keywords = {
        "int",
        "float",
        "double",
        "char",
        "if",
        "else",
        "for",
        "while",
        "return",
        "void",
        "class",
        "public",
        "private",
        "protected",
        "static",
    };
    for (const string &keyword : keywords)
    {
        if (str == keyword)
            return true;
    }
    return false;
}

// Function to check if a string is an identifier
bool isIdentifier(const string &str)
{
    if (str.empty())
        return false;
    if (!(isalpha(str[0]) || str[0] == '_'))
        return false; // first character must be a letter or '_'
    for (char c : str)
    {
        if (!(isalnum(c) || c == '_'))
            return false; // subsequent characters must be alphanumeric or '_'
    }
    return true;
}

// Function to check if a string is an operator
bool isOperator(const string &str)
{
    vector<string> operators = {
        "+",
        "-",
        "*",
        "/",
        "%",
        "++",
        "--",
        "=",
        "==",
        ">",
        "<",
        ">=",
        "<=",
    };
    for (const string &op : operators)
    {
        if (str == op)
            return true;
    }
    return false;
}

// Function to check if a string is a constant (integer or float)
bool isConstant(const string &str)
{
    bool dotSeen = false;
    for (char c : str)
    {
        if (c == '.')
        {
            if (dotSeen)
                return false; // Only one dot allowed for float
            dotSeen = true;
        }
        else if (!isdigit(c))
        {
            return false; // All characters must be digits or a single dot for float
        }
    }
    return true;
}

int main()
{
    string input;

    cout << "Enter a word: ";
    cin >> input;

    if (isKeyword(input))
    {
        cout << input << " is a Keyword.\n";
    }
    else if (isIdentifier(input))
    {
        cout << input << " is an Identifier.\n";
    }
    else if (isOperator(input))
    {
        cout << input << " is an Operator.\n";
    }
    else if (isConstant(input))
    {
        cout << input << " is a Constant.\n";
    }
    else
    {
        cout << input << " is not recognized as a valid C++ element.\n";
    }

    return 0;
}
