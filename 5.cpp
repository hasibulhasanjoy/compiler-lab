#include <bits/stdc++.h>
using namespace std;

bool isFloatVariable(string input)
{
    if (!((input[0] >= 'a' && input[0] <= 'h') || (input[0] >= 'A' && input[0] <= 'H') || (input[0] >= 'o' && input[0] <= 'z') || (input[0] >= 'O' && input[0] <= 'Z')))
    {
        return false;
    }

    for (int i = 1; i < input.length(); i++)
    {
        if (!isalnum(input[i]))
        {
            return false;
        }
    }
    return true;
}

bool isFloatNumber(string input)
{
    if (input[0] == '0' && input[1] == '.' && isdigit(input[2]) && isdigit(input[3]) && input.length() == 4)
    {
        return true;
    }
    if (input[0] > '0')
    {
        int decimalPointCount = 0;
        int decimalPoint = input.find('.');
        if (decimalPoint == -1)
        {
            return false;
        }
        for (int i = 0; i < decimalPoint; i++)
        {
            if (!isdigit(input[i]))
            {
                return false;
            }
        }
        int afterDecimal = 0;
        for (int i = decimalPoint + 1; i < input.length(); i++)
        {
            if (input[i] == '.' || !isdigit(input[i]))
            {
                return false;
            }
            afterDecimal++;
        }
        if (afterDecimal != 2)
        {
            return false;
        }
        return true;
    }
}

int main()
{
    string input = "12345600";
    cout << isFloatNumber(input) << endl;
    return 0;
}