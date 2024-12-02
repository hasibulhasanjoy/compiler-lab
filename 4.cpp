#include <bits/stdc++.h>
using namespace std;

bool isInt(string input)
{
    if (!(input[0] >= 'i' && input[0] <= 'n' || input[0] >= 'I' || input[0] <= 'N'))
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

bool isShortInteger(string input)
{
    if (input.length() < 1 || input.length() > 4)
    {
        return false;
    }
    if (input[0] == '0')
    {
        return false;
    }
    for (int i = 1; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

bool isLongInteger(string input)
{
    if (input.length() < 5)
    {
        return false;
    }
    if (input[0] == '0')
    {
        return false;
    }
    for (int i = 1; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}