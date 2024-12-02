// explanation: https://chatgpt.com/c/67449842-46ac-8010-9a91-7f9a98299b8c

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Define the valid words for each category
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
}; // Verbs

// Function to check if a word is in a list
bool isInList(const string &word, const vector<string> &wordList)
{
    return find(wordList.begin(), wordList.end(), word) != wordList.end();
}

// Function to check if the sentence is valid according to the grammar rules
string checkSentence(const string &sentence)
{
    // Split the sentence into words
    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word)
    {
        words.push_back(word);
    }

    // Sentence must have 2 or 3 words
    if (words.size() != 2 && words.size() != 3)
    {
        return "Invalid sentence";
    }

    // Check if the first word (subject) is a valid proper noun or pronoun
    string subject = words[0];
    if (!isInList(subject, PN) && !isInList(subject, P))
    {
        return "Invalid sentence";
    }

    // Check if the second word (verb) is valid
    string verb = words[1];
    if (!isInList(verb, V))
    {
        return "Invalid sentence";
    }

    // If there is a third word, it must be a noun
    if (words.size() == 3)
    {
        string noun = words[2];
        if (!isInList(noun, N))
        {
            return "Invalid sentence";
        }
    }

    // If all checks pass, the sentence is valid
    return "Valid sentence";
}

int main()
{
    // Test the function with a list of example sentences
    vector<string> testSentences = {
        "he runs",         // Valid
        "Sagor eats rice", // Valid
        "I book",          // Invalid
        "Selim run home",  // Invalid
        "they take grass", // Valid
        "Salma read book"  // Valid
    };

    // Test each sentence
    for (const string &sentence : testSentences)
    {
        cout << "Sentence: '" << sentence << "' is " << checkSentence(sentence) << endl;
    }

    return 0;
}
