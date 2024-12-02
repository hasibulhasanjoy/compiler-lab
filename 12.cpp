#include <bits/stdc++.h>
using namespace std;
// check isOperator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
// precedence of operators
bool validate(string input)
{
    stack<char> par;
    int len = input.length();
    bool expectOperator = false;
    bool expectOperand = true;
    for (int i = 0; i < len; i++)
    {
        char ch = input[i];
        if (isspace(ch))
        {
            continue;
        }
        else if (isOperator(ch))
        {
            if (expectOperator == false)
            {
                return false;
            }
            expectOperator = false;
            expectOperand = true;
        }
        else if (isalnum(ch) || ch == '.')
        {
            if (expectOperand == false)
            {
                return false;
            }
            expectOperator = true;
            expectOperand = false;
        }
        else if (ch == '(')
        {
            if (expectOperand == false)
            {
                return false;
            }
            par.push(ch);
            expectOperand = true;
            expectOperator = false;
        }
        else if (ch == ')')
        {
            if (expectOperand == true)
            {
                return false;
            }
            par.pop();
            expectOperand = false;
            expectOperator = true;
        }
    }
    return par.empty() && expectOperator && !expectOperand;
}
int main()
{
    string expression = "2+5(3*5)";
    if (validate(expression))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
    return 0;
}