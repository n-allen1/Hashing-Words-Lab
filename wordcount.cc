#include "wordcount.h"

#include <algorithm>
#include <iostream>

WordCount::WordCount(int sz) {
    // COMPLETE
}

int WordCount::hash(string s) {
    // COMPLETE
    return 0; // not correct
}

int WordCount::count(string word) {
    // COMPLETE
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