#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("./inputs/2.txt", "r", stdin);
    int v = 0, c = 0;
    set<char> vowels, consonants;
    string vowel_words, consonant_words, word;
    vector<string> words;
    string input;
    getline(cin, input);
    for (auto ch : input)
    {
        char lowerCh = tolower(ch);
        word += lowerCh;
        if (lowerCh == ' ')
        {
            words.push_back(word);
            if (vowels.find(word[0]) != vowels.end())
            {
                vowel_words += word + " ";
            }
            else
            {
                consonant_words += word + " ";
            }
            word = "";
        }
        else if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u')
        {
            v++;
            vowels.insert(lowerCh);
        }
        else
        {
            c++;
            consonants.insert(lowerCh);
        }
    }
    words.push_back(word);
    cout << v << " " << c << endl;
    // print vowels and consonants
    cout << "vowels: ";
    for (auto vowel : vowels)
    {
        cout << vowel << " ";
    }
    cout << endl;
    cout << "consonants: ";
    for (auto consonant : consonants)
    {
        cout << consonant << " ";
    }
    // print words
    cout << endl;
    cout << "Words: ";
    for (auto word : words)
    {
        cout << word << " ";
    }
    cout << endl;
    // print vowel words
    cout << vowel_words << endl;
    cout << consonant_words << endl;
}