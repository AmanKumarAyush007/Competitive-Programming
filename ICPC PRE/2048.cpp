#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MAX_Y = 4 * 1000000 + 1;  // Given that 1 <= Y <= 4 * 10^6

// Function to precompute the configurations for all possible values up to MAX_Y
void precomputeConfigurations(vector<ll>& dp) {
    dp[4] = 1;
    dp[8] = 1;

    for (ll i = 12; i < MAX_Y; i += 4) {
        for (ll j = 4; j <= i / 2; j *= 2) {
            if (i >= 2 * j) {
                dp[i] = (dp[i] + dp[i - 2 * j]) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    // Precompute all possible results up to MAX_Y
    vector<ll> dp(MAX_Y, 0);
    precomputeConfigurations(dp);

    // Process the test cases
    while (t--) {
        ll y;
        cin >> y;
        if (y % 2 != 0 || y == 2) {
            cout << 0 << "\n";
        } else {
            cout << dp[y] << "\n";
        }
    }

    return 0;
}
