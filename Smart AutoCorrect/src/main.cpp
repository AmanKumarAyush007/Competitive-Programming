#include <iostream>
#include <fstream>
#include <string>
#include <chrono>    // For timing
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

#include "Trie.h"
#include "Autocorrect.h"

// Function to convert a string to lowercase
std::string toLower(const std::string &s)
{
    std::string lower_s = s;
    std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return lower_s;
}

int main()
{
    Trie dictionaryTrie;
    const std::string dictionaryFilePath = "words.txt"; // Make sure this file is in the same directory as the executable

    std::cout << "Loading dictionary from " << dictionaryFilePath << "..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream inputFile(dictionaryFilePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open dictionary file '" << dictionaryFilePath << "'" << std::endl;
        std::cerr << "Please ensure 'words.txt' is in the same directory as the executable." << std::endl;
        return 1;
    }

    std::string word;
    long long wordCount = 0;
    while (std::getline(inputFile, word))
    {
        if (!word.empty())
        {
            dictionaryTrie.insert(toLower(word)); // Convert to lowercase before inserting
            wordCount++;
        }
    }
    inputFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Dictionary loaded with " << wordCount << " words in " << duration.count() << " seconds." << std::endl;

    Autocorrect autocorrectSystem(dictionaryTrie);

    std::cout << "\nEnter a word to check (type 'exit' to quit):" << std::endl;
    std::string inputWord;
    while (std::getline(std::cin, inputWord) && toLower(inputWord) != "exit")
    {
        std::string lowerInputWord = toLower(inputWord);

        if (dictionaryTrie.search(lowerInputWord))
        {
            std::cout << "No correction needed. '" << inputWord << "' is a valid word." << std::endl;
        }
        else
        {
            std::cout << "Word '" << inputWord << "' not found. Generating suggestions..." << std::endl;
            // Generate suggestions up to 2 edits
            std::vector<Suggestion> suggestions = autocorrectSystem.getSuggestions(lowerInputWord, 2);

            if (suggestions.empty())
            {
                std::cout << "No suggestions found within 1-2 edits." << std::endl;
            }
            else
            {
                std::cout << "Suggestions (ranked by edit distance):" << std::endl;
                // Only display the best suggestion as per the objective
                std::cout << "- " << suggestions[0].word << " (Edit Distance: " << suggestions[0].distance << ")" << std::endl;
                // If you want to show all:
                // for (const auto& s : suggestions) {
                //     std::cout << "- " << s.word << " (Edit Distance: " << s.distance << ")" << std::endl;
                // }
            }
        }
        std::cout << "\nEnter a word to check (type 'exit' to quit):" << std::endl;
    }

    std::cout << "Exiting autocorrect system. Goodbye!" << std::endl;

    return 0;
}