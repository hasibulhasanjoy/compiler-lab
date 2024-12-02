#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("./inputs/1.txt", "r", stdin);
    string inp;
    getline(cin, inp);
    int word = 1, digit = 0, letter = 0, other = 0;
    string letters, digits, other_characters;
    for (size_t i = 0; i < inp.length(); i++)
    {
        char c = inp[i];
        if (c == ' ')
        {
            word++;
        }
        else if (tolower(c) >= 'a' && tolower(c) <= 'z')
        {
            letter++;
            letters += c;
        }
        else if (c >= '0' && c <= '9')
        {
            digit++;
            digits += c;
        }
        else
        {
            other++;
            other_characters += c;
        }
    }
    cout << "Number of words: " << word << endl;
    cout << "Number of letters: " << letter << endl;
    cout << "Number of digits: " << digit << endl;
    cout << "Number other of characters: " << other << endl;

    cout << "\nThe letters are: " << letters << endl;
    cout << "The digits are: " << digits << endl;
    cout << "The characters are: " << other_characters << endl;
}