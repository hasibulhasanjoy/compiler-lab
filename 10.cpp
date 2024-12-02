#include <bits/stdc++.h>
using namespace std;

bool canReduce(stack<string> st)
{
    if (!st.empty() && st.top() == "id")
    {
        return true; // Reduce "id" to "E"
    }
    if (st.size() >= 3)
    {
        string third = st.top();
        st.pop();
        string second = st.top();
        st.pop();
        string first = st.top();
        // Check for valid combinations
        if ((first == "E" && second == "+" && third == "E") ||
            (first == "E" && second == "*" && third == "E"))
        {
            return true;
        }
    }
    return false;
}

void reduce(stack<string> &st)
{
    if (!st.empty() && st.top() == "id")
    {
        st.pop();
        st.push("E"); 
    }
    else if (st.size() >= 3)
    {
        string third = st.top();
        st.pop();
        string second = st.top();
        st.pop();
        string first = st.top();
        st.pop();
        if (first == "E" && second == "+" && third == "E")
        {
            st.push("E"); // Reduce "E + E" to "E"
        }
        else if (first == "E" && second == "*" && third == "E")
        {
            st.push("E"); // Reduce "E * E" to "E"
        }
        else
        {
            // Push back if no rule matches
            st.push(first);
            st.push(second);
            st.push(third);
        }
    }
}

void print(stack<string> st)
{
    stack<string> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    // Input tokens for shift-reduce parsing (e.g., "id + id * id")
    vector<string> input = {"id", "+", "id", "*", "id"};
    stack<string> st; // Parsing stack

    size_t i = 0; // Pointer to input tokens
    while (i < input.size() || canReduce(st))
    {
        if (canReduce(st))
        {
            reduce(st);
        }
        else
        {

            st.push(input[i]);
            i++;
        }
        print(st);
    }

    // Final state check
    if (st.size() == 1 && st.top() == "E")
    {
        cout << "Parsing successful!" << endl;
    }
    else
    {
        cout << "Parsing failed." << endl;
    }

    return 0;
}