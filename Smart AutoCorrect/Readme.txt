Smart Autocorrect System

This project implements a smart autocorrect engine in C++ capable of suggesting corrections for misspelled words using a Trie data structure for efficient dictionary lookups and the Levenshtein Edit Distance algorithm for calculating word similarity.


# Features :

    Efficient Dictionary Storage: Utilizes a Trie to store a large dictionary of English words, enabling fast prefix-based searches and lookups.
    Misspell Detection: Quickly identifies if an input word exists in the loaded dictionary.
    Intelligent Suggestion Generation: When a word is misspelled, the system generates potential corrections by applying insertions, deletions, and substitutions to the input word.
    Edit Distance Calculation: Employs the Levenshtein Edit Distance algorithm to quantify the "distance" (number of single-character edits) between the misspelled word and potential correct words.
    Constraint-Based Correction: Suggestions are limited to a maximum edit distance of 2, focusing on common typos.
    Ranked Suggestions: Uses a priority queue to rank suggestions, always prioritizing words with the lowest edit distance.
    Case-Insensitive Handling: All input words and dictionary words are converted to lowercase for consistent comparisons.

# Project Structure : 

Autocorrect_System/
├── src/
│   ├── main.cpp          # Main program execution, dictionary loading, and user interaction.
│   ├── Trie.h            # Header for the Trie data structure.
│   ├── Trie.cpp          # Implementation of the Trie.
│   ├── EditDistance.h    # Header for the Levenshtein Edit Distance utility functions.
│   ├── EditDistance.cpp  # Implementation of the Levenshtein Edit Distance.
│   ├── Autocorrect.h     # Header for the Autocorrect logic class.
│   └── Autocorrect.cpp   # Implementation of the Autocorrect suggestion generation and ranking.
├── words.txt             # The dictionary file containing English words (one word per line).
└── README.md             # This README file.

# How to Compile and Run :
//Prerequisites//
    A C++ compiler (e.g., GCC/G++). The project uses C++17 features (-std=c++17 recommended).

1. Obtain the Dictionary File

    Download or create a plain text file named words.txt.
    This file should contain one English word per line.
    Place words.txt directly in the Autocorrect_System/ directory (the same directory as this README.md file). A good dictionary file might contain 5,000-10,000 common English words.

2. Navigate to the Project Directory

Open your terminal or command prompt and change your current directory to the Autocorrect_System/ folder:
Bash

cd path/to/Autocorrect_System

3. Compile the Source Code

Use the G++ compiler to compile all .cpp files in the src/ directory:
Bash

g++ -std=c++17 src/*.cpp -o autocorrect

This command compiles all the necessary source files and creates an executable named autocorrect.
4. Run the Program

Execute the compiled program from the same directory where words.txt is located:
Bash

./autocorrect

# Usage :

    Loading Dictionary: Upon starting, the program will attempt to load words from words.txt into the Trie. A message will indicate success or failure.
    Enter a Word: The program will prompt you to "Enter a word to check:".
    Check Spelling:
        If the word is found in the dictionary, it will confirm "No correction needed."
        If the word is not found, it will generate and display the best suggestion (based on the lowest edit distance) found within 1-2 edits.
    Exit: Type exit and press Enter to quit the program.

# Assumptions Made : 

    The dictionary file words.txt is located in the same directory from which the executable is run.
    Words in words.txt are primarily English words, one per line, and are handled case-insensitively.
    The system focuses on corrections within a maximum Levenshtein edit distance of 2.
    The current implementation does not consider word frequency for ranking suggestions (this was an optional bonus feature). Suggestions are strictly ranked by edit distance.
    Transpositions (e.g., recieve to receive) are implicitly handled by the Levenshtein distance as two operations (a deletion and an insertion, or two substitutions), rather than a single dedicated "transpose" operation from Damerau-Levenshtein.

Feel free


