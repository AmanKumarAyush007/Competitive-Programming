#include "Autocorrect.h"
#include "EditDistance.h"
#include <cctype> // For std::tolower

Autocorrect::Autocorrect(const Trie& dictionaryTrie) : dictionary(dictionaryTrie) {}

// Recursive function to generate words within a given edit distance
void Autocorrect::generateNearbyWords(const std::string& currentWord, int currentDistance, int maxDistance,
                                      std::set<std::string>& generatedWords) {
    if (currentDistance > maxDistance) {
        
        return;
    }

    // Check if the currentWord (generated) exists in the dictionary
    // We only add it to generatedWords if it's a valid dictionary word.
    // This reduces redundant edit distance calculations later.
    if (dictionary.search(currentWord)) {
        generatedWords.insert(currentWord);
    }

    // Base case: if currentDistance is already maxDistance, don't generate further
    if (currentDistance == maxDistance) {
        return;
    }

    // --- Generate words by one more edit operation ---

    // Deletion
    for (size_t i = 0; i < currentWord.length(); ++i) {
        std::string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
        generateNearbyWords(newWord, currentDistance + 1, maxDistance, generatedWords);
    }

    // Insertion
    for (size_t i = 0; i <= currentWord.length(); ++i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            std::string newWord = currentWord.substr(0, i) + ch + currentWord.substr(i);
            generateNearbyWords(newWord, currentDistance + 1, maxDistance, generatedWords);
        }
    }

    // Substitution
    for (size_t i = 0; i < currentWord.length(); ++i) {
        char originalChar = currentWord[i];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (ch == originalChar) continue;
            std::string newWord = currentWord;
            newWord[i] = ch;
            generateNearbyWords(newWord, currentDistance + 1, maxDistance, generatedWords);
        }
    }

    // Transposition (adjacent swap) - can be considered a special case of 2 substitutions,
    // but explicitly handling it can be more efficient for just transpositions.
    // However, for standard Levenshtein, two ops handle it. If you want Damerau-Levenshtein,
    // it's a different algorithm. For simplicity and constraint of 1-2 typos, we'll
    // rely on the Levenshtein to implicitly cover it with 2 operations.
    // If you explicitly wanted to add single-typo transpositions:
    // for (size_t i = 0; i + 1 < currentWord.length(); ++i) {
    //     std::string newWord = currentWord;
    //     std::swap(newWord[i], newWord[i+1]);
    //     generateNearbyWords(newWord, currentDistance + 1, maxDistance, generatedWords);
    // }
}


std::vector<Suggestion> Autocorrect::getSuggestions(const std::string& inputWord, int maxDistance) {
    std::set<std::string> potentialCandidates;
    // Start generating candidates from the input word with 0 edits
    // and recursively generate up to maxDistance edits.
    generateNearbyWords(inputWord, 0, maxDistance, potentialCandidates);

    // Use a priority queue to rank suggestions
    std::priority_queue<Suggestion, std::vector<Suggestion>, std::greater<Suggestion>> rankedSuggestions;

    for (const std::string& candidate : potentialCandidates) {
        // Only consider candidates that are actually in the dictionary (already filtered by generateNearbyWords)
        // and calculate their distance from the original input word.
        int dist = calculateEditDistance(inputWord, candidate);
        // Only add if distance is within maxDistance and not the original word itself
        if (dist > 0 && dist <= maxDistance) {
            rankedSuggestions.push({candidate, dist});
        }
    }

    std::vector<Suggestion> finalSuggestions;
    while (!rankedSuggestions.empty()) {
        finalSuggestions.push_back(rankedSuggestions.top());
        rankedSuggestions.pop();
    }

    return finalSuggestions;
}