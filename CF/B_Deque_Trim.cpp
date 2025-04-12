#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()



int longestSubarrayWithSumK(const vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> prefixSum;
    int sum = 0;
    int maxLen = -1;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];

        if (sum == k) {
            maxLen = i + 1;
        }

        if (prefixSum.find(sum - k) != prefixSum.end()) {
            maxLen = max(maxLen, i - prefixSum[sum - k]);
        }

        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return maxLen;
}

void solve(){
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    int ans = longestSubarrayWithSumK(v,s);

    if(ans == -1 ) cout << -1;
    else cout << n - ans;


    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}