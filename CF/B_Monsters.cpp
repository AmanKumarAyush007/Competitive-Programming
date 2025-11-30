#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int num_test_cases;
  cin >> num_test_cases;

  while (num_test_cases--) {
    int num_elements, window_size;
    cin >> num_elements >> window_size;

    vector<int> elements(num_elements);
    for (int i = 0; i < num_elements; ++i) {
      cin >> elements[i];
      elements[i] %= window_size; // Wrap around if exceeding window size
      if (elements[i] == 0) elements[i] = window_size; // Handle zero case
    }

    vector<int> original_indices(num_elements);
    for (int i = 0; i < num_elements; ++i) {
      original_indices[i] = i; // Store original indices
    }

    // Sort elements in descending order while keeping track of original positions
    stable_sort(original_indices.begin(), original_indices.end(),
                [&](int i, int j) { return elements[i] > elements[j]; });

    // Print original positions (indices + 1 for 1-based indexing)
    for (int index : original_indices) {
      cout << index + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}