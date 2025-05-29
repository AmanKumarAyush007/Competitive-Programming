#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

#include <string>
#include <algorithm> // For std::min

// Function to calculate Levenshtein Edit Distance
int calculateEditDistance(const std::string &s1, const std::string &s2);

#endif // EDIT_DISTANCE_H