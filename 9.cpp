#include <bits/stdc++.h>

using namespace std;
vector<string> PN = {
    "Sagor",
    "Selim",
    "Salma",
    "Nipu",
}; // Proper Nouns

vector<string> P = {
    "he",
    "she",
    "i",
    "we",
    "you",
    "they",
}; // Pronouns

vector<string> N = {
    "book",
    "cow",
    "dog",
    "home",
    "grass",
    "rice",
    "mango",
}; // Nouns

vector<string> V = {
    "read",
    "eat",
    "take",
    "run",
    "write",
};

int main()
{
    string sentence;
    cin >> sentence;
    vector<string> words;
    string word;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            words.push_back(word);
            word = "";
            continue;
        }
        word += sentence[i];
    }
    words.push_back(word);
    if (words.size() < 2 | words.size() > 3)
    {
        cout << "Invalid sentence" << endl;
        return 0;
    }
    if (find(P.begin(), P.end(), words[0]) == P.end() || find(PN.begin(), PN.end(), words[0]) == PN.end())
    {
        cout << "Invalid Sentence" << endl;
        return 0;
    }
}