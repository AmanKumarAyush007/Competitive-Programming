#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include <map>    // For std::map for children

class TrieNode
{
public:
    std::map<char, std::unique_ptr<TrieNode>> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie
{
public:
    Trie();
    void insert(const std::string &word);
    bool search(const std::string &word) const;
    // Helper to collect all words in the Trie (useful for debugging or advanced features)
    // void collectAllWords(TrieNode* node, std::string currentWord, std::vector<std::string>& words) const;

private:
    std::unique_ptr<TrieNode> root;
};

#endif // TRIE_H