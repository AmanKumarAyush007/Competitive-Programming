#include "EditDistance.h"
#include <vector>

// Implementation of the Levenshtein Edit Distance algorithm
int calculateEditDistance(const std::string &s1, const std::string &s2)
{
    int m = s1.length();
    int n = s2.length();

    // Create a 2D vector to store the distances
    // dp[i][j] will be the Levenshtein distance between s1[0..i-1] and s2[0..j-1]
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Initialize the dp table
    // If s1 is empty, the distance is the length of s2 (all insertions)
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = i;
    }
    // If s2 is empty, the distance is the length of s1 (all deletions)
    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = j;
    }

    // Fill the dp table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            dp[i][j] = std::min({
                dp[i - 1][j] + 1,       // Deletion
                dp[i][j - 1] + 1,       // Insertion
                dp[i - 1][j - 1] + cost // Substitution
            });
        }
    }

    return dp[m][n];
}