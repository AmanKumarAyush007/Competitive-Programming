#ifndef AUTOCORRECT_H
#define AUTOCORRECT_H

#include "Trie.h"
#include <string>
#include <vector>
#include <set>       // For std::set to store unique suggestions
#include <queue>     // For std::priority_queue
#include <algorithm> // For std::transform

// Structure to hold a suggestion and its edit distance
struct Suggestion
{
    std::string word;
    int distance;

    // Custom comparator for priority_queue: lower distance means higher priority
    bool operator>(const Suggestion &other) const
    {
        return distance > other.distance;
    }
};

class Autocorrect
{
public:
    Autocorrect(const Trie &dictionaryTrie);
    std::vector<Suggestion> getSuggestions(const std::string &inputWord, int maxDistance);

private:
    const Trie &dictionary; // Reference to the Trie
    void generateNearbyWords(const std::string &currentWord, int currentDistance, int maxDistance,
                             std::set<std::string> &generatedWords);
};

#endif // AUTOCORRECT_H