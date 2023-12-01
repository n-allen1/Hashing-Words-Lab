#include "wordcount.h"

#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <iostream>

WordCount::WordCount(int sz) {
    hashTable.resize(sz);
}

// Returns the hash using STL's built-in hash template
int WordCount::hash(string s) {
    return hashFunction(s) % hashTable.size();
}

int WordCount::count(string word) {
    int checkCount = hash(word);
    for (const auto& hashPair : hashTable[checkCount])
    {
        if (hashPair.first == word)
        {
            return hashPair.second;
        }
    }
    return 0; // not correct
}

void WordCount::add(std::string word) {
    int checkCount = hash(word);

    auto& list = hashTable[checkCount];
    
    auto it = std::find_if(list.begin(), list.end(), [&word](const std::pair<std::string, int>& pair) 
    {
        return pair.first == word;
    });

    if (it != list.end()) 
    {
        // If the word is found, increment its count
        it->second++;
    } else {
        // If the word is not found, add a new pair with count 1
        list.push_back({word, 1});
    }
}


void WordCount::print() {
    std::vector<std::pair<string, int>> words;
    for (auto entry: hashTable)
        for (auto pair: entry)
            words.push_back(pair);
    sort(words.begin(), words.end());
    for (auto pair: words)
        std::cout << pair.first << ": " << pair.second << std::endl;
}

void printFileWordCount(string filename, int tableSize) {
    std::unordered_map<std::string, int> wordCount;
    
    std::ifstream file(filename);

    std::string word;
    while (file >> word) 
    {
        wordCount[word]++;
    }

    file.close();
}