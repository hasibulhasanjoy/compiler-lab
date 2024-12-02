#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype> // For isupper()
using namespace std;

// Global declarations
map<char, vector<string>> grammar; // Stores grammar rules
map<char, set<char>> firstSets;    // Stores First sets
map<char, set<char>> followSets;   // Stores Follow sets

// Function to calculate First set of a symbol
void calculateFirst(char symbol)
{
    if (firstSets.count(symbol))
        return; // Already calculated

    set<char> first;
    for (const string &production : grammar[symbol])
    {
        for (char ch : production)
        {
            if (!isupper(ch))
            { // Terminal
                first.insert(ch);
                break;
            }
            else
            {
                calculateFirst(ch); // Non-terminal
                first.insert(firstSets[ch].begin(), firstSets[ch].end());
                if (firstSets[ch].count('#') == 0)
                    break; // No epsilon, stop
            }
        }
    }
    firstSets[symbol] = first;
}

// Function to calculate Follow set of a symbol
void calculateFollow(char symbol)
{
    if (followSets.count(symbol))
        return; // Already calculated

    set<char> follow;
    if (symbol == 'S')
        follow.insert('$'); // Start symbol gets '$'

    for (const auto &rule : grammar)
    {
        char nonTerminal = rule.first;
        for (const string &production : rule.second)
        {
            for (size_t i = 0; i < production.size(); ++i)
            {
                if (production[i] == symbol)
                {
                    size_t j = i + 1;
                    while (j < production.size())
                    {
                        char next = production[j];
                        if (!isupper(next))
                        { // Terminal
                            follow.insert(next);
                            break;
                        }
                        else
                        {
                            follow.insert(firstSets[next].begin(), firstSets[next].end());
                            if (firstSets[next].count('#') == 0)
                                break; // No epsilon, stop
                        }
                        ++j;
                    }
                    if (j == production.size() && nonTerminal != symbol)
                    {
                        calculateFollow(nonTerminal);
                        follow.insert(followSets[nonTerminal].begin(), followSets[nonTerminal].end());
                    }
                }
            }
        }
    }
    follow.erase('#'); // Follow set cannot have epsilon
    followSets[symbol] = follow;
}

int main()
{
    freopen("./inputs/13.txt", "r", stdin);
    int n;
    cout << "Enter the number of grammar rules: ";
    cin >> n;
    cout << "Enter the grammar rules (e.g., S->AB|a):\n";
    for (int i = 0; i < n; ++i)
    {
        string rule;
        cin >> rule;
        char nonTerminal = rule[0];
        string production = rule.substr(3); // Skip "X->"
        size_t pos = 0;
        while ((pos = production.find('|')) != string::npos)
        {
            grammar[nonTerminal].push_back(production.substr(0, pos));
            production.erase(0, pos + 1);
        }
        grammar[nonTerminal].push_back(production);
    }

    // Calculate First sets
    for (const auto &rule : grammar)
    {
        calculateFirst(rule.first);
    }

    // Calculate Follow sets
    for (const auto &rule : grammar)
    {
        calculateFollow(rule.first);
    }

    // Display First sets
    cout << "\nFirst sets:\n";
    for (const auto &firstSet : firstSets)
    {
        cout << firstSet.first << " = { ";
        for (char ch : firstSet.second)
            cout << ch << " ";
        cout << "}\n";
    }

    // Display Follow sets
    cout << "\nFollow sets:\n";
    for (const auto &followSet : followSets)
    {
        cout << followSet.first << " = { ";
        for (char ch : followSet.second)
            cout << ch << " ";
        cout << "}\n";
    }

    return 0;
}
