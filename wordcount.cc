#include "wordcount.h"

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

void WordCount::add(string word) {
    // COMPLETE
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
    // COMPLETE
}