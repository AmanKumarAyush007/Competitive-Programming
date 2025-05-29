#include "Trie.h"
#include <iostream>

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() : root(std::make_unique<TrieNode>()) {}

void Trie::insert(const std::string &word)
{
    TrieNode *current = root.get();
    for (char ch : word)
    {
        if (current->children.find(ch) == current->children.end())
        {
            current->children[ch] = std::make_unique<TrieNode>();
        }
        current = current->children[ch].get();
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string &word) const
{
    const TrieNode *current = root.get();
    for (char ch : word)
    {
        if (current->children.find(ch) == current->children.end())
        {
            return false;
        }
        current = current->children.at(ch).get(); // Use .at() for const access
    }
    return current->isEndOfWord;
}

// Optional: for collecting all words (e.g., if you need to iterate through them)
// void Trie::collectAllWords(TrieNode* node, std::string currentWord, std::vector<std::string>& words) const {
//     if (!node) {
//         return;
//     }
//     if (node->isEndOfWord) {
//         words.push_back(currentWord);
//     }
//     for (const auto& pair : node->children) {
//         collectAllWords(pair.second.get(), currentWord + pair.first, words);
//     }
// }