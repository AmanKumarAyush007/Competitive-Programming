#include <bits/stdc++.h>
using namespace std;

int compute_LIS_length(const vector<int>& arr) {
    vector<int> lis; 
    for (int x : arr) {
    // We use lower_bound to find the first element in lis that is not less than x.
        auto it = std::lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();
}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);


// Collapse
int t;
cin >> t;

while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    // dp[len] will hold the minimum possible ending value of an increasing subsequence of length 'len'.
    // Since a[i] ≥ 1 we can initialize dp[0] = 0 (as a stand-in for –infty) and dp[1..n] = INF.
    const int INF = 1000000000; // a number greater than any element (since ai ≤ n, and n ≤ 2e5, this is safe)
    vector<int> dp(n+1, INF);
    dp[0] = 0;

    int lis = 0; // length of the longest increasing subsequence
    for (int x : a) {
        // Find smallest index pos such that dp[pos] ≥ x, so that an increasing sequence of length pos can be extended.
        int pos = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        dp[pos] = x;
        lis = max(lis, pos);
    }

    // It has been proven that the minimum total penalty when splitting into 2 subsequences equals max(0, lis - 2)
    int ans = max(0, lis - 2);
    cout << ans << "\n";
}

return 0;
}