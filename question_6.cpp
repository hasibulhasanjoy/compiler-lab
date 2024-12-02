// explanation: https://chatgpt.com/c/674492d2-eba0-8010-8e50-7dcd5d4630a8

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string matches the Character Variable pattern
bool isCharacterVariable(const string &str)
{
    if (str.substr(0, 3) == "ch_")
    {
        for (int i = 3; i < str.length(); i++)
        {
            if (!isalnum(str[i]))
            {
                return false; // Not alphanumeric
            }
        }
        return true; // Valid Character Variable
    }
    return false;
}

// Function to check if a string matches the Binary Variable pattern
bool isBinaryVariable(const string &str)
{
    if (str.substr(0, 3) == "bn_")
    {
        for (int i = 3; i < str.length(); i++)
        {
            if (!isalnum(str[i]))
            {
                return false; // Not alphanumeric
            }
        }
        return true; // Valid Binary Variable
    }
    return false;
}

// Function to check if a string matches the Binary Number pattern
bool isBinaryNumber(const string &str)
{
    if (str[0] == '0')
    {
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] != '0' && str[i] != '1')
            {
                return false; // Not a valid binary digit
            }
        }
        return true; // Valid Binary Number
    }
    return false;
}

// Function to identify invalid input
bool isInvalidInput(const string &str)
{
    return true; // If it does not match any valid pattern, it's invalid
}

// Lexical Analyzer function to determine the type of the input
void lexicalAnalyzer(const string &str)
{
    if (isCharacterVariable(str))
    {
        cout << "CHAR_VAR" << endl; // Valid Character Variable
    }
    else if (isBinaryVariable(str))
    {
        cout << "BIN_VAR" << endl; // Valid Binary Variable
    }
    else if (isBinaryNumber(str))
    {
        cout << "BIN_NUM" << endl; // Valid Binary Number
    }
    else
    {
        cout << "INVALID" << endl; // Invalid input
    }
}

int main()
{
    string input;

    // Test inputs
    cout << "Enter input: ";
    cin >> input;

    lexicalAnalyzer(input); // Call lexical analyzer to determine the type

    return 0;
}
