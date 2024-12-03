#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit()
using namespace std;
// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3; // Higher precedence for power operator
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
std::string infixToPostfix(const std::string &infix)
{
    stack<char> st; // Stack for operators
    string postfix; // Resulting postfix expression

    for (char c : infix)
    {
        if (isdigit(c) || isalpha(c))
        {
            // Operand: Append to postfix
            postfix += c;
        }
        else if (c == '(')
        {
            // Opening parenthesis: Push to stack
            st.push(c);
        }
        else if (c == ')')
        {
            // Closing parenthesis: Pop until '('
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from stack
        }
        else if (isOperator(c))
        {
            // Operator: Pop operators of higher or equal precedence
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // Push current operator
        }
    }

    // Pop any remaining operators in the stack
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

class Node
{
public:
    char val;
    Node *left, *right;

    Node(char val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *syntaxTree(string postfix)
{
    stack<Node *> st;
    for (char c : postfix)
    {
        if (isalnum(c))
        {
            Node *node = new Node(c);
            st.push(node);
        }
        else
        {
            Node *node = new Node(c);
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
            st.push(node);
        }
    }
    return st.top();
}

void printSyntaxTree(Node *node, int level)
{
    if (node == NULL)
        return;
    printSyntaxTree(node->left, level + 1);
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
    cout << node->val << endl;

    printSyntaxTree(node->right, level + 1);
}

int main()
{
    string infix;
    // cout << "Enter infix expression: ";
    // cin >> infix;
    infix = "A+B*(C^D-E)";

    string postfix = infixToPostfix(infix);
    Node *node = syntaxTree(postfix);
    printSyntaxTree(node, 0);

    return 0;
}
