#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int n, k;
    cin >> n >> k;
    
    // Map to store {l,r} pair and its corresponding m value
    map<pair<int, int>, int> range_values;
    
    // Set to store all m values we've seen
    set<int> m_values;
    
    // Process k queries
    for (int i = 0; i < k; i++) {
        int l, r, m;
        cin >> l >> r >> m;
        
        pair<int, int> current_range = {l, r};
        
        // Check if this {l,r} pair has been seen before
        if (range_values.find(current_range) != range_values.end()) {
            // If pair exists, check if m value matches
            if (range_values[current_range] != m) {
                cout << -1 << '\n';
                return;
            }
        } else {
            // If pair doesn't exist, store it
            range_values[current_range] = m;
        }
        
        // Store m value in set
        m_values.insert(m);
    }
    
    // Find first missing number from 1 to n
    int missing_number = 0;
    for (int i = 1; i <= n; i++) {
        if (m_values.find(i) == m_values.end()) {
            missing_number = i;
            break;
        }
    }
    
    // If no missing number found, print -1
    if (missing_number == 0) {
        cout << -1 << '\n';
        return;
    }
    
    // Print the missing number n times
    for (int i = 0; i < n; i++) {
        cout << missing_number << " ";
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}