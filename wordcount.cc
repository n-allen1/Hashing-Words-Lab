#include "wordcount.h"

#include <algorithm>
#include <iostream>

WordCount::WordCount(int sz) {
    hashTable.resize(sz);
}

// Returns the hash using STL's built-in hash template
int WordCount::hash(string s) {
    std::hash<string> hashing;
    size_t hash_value = hashing(s);

    return static_cast<int>(hash_value);
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