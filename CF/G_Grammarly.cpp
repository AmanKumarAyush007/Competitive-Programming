#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define MOD 998244353
#define nl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    // map for DP memoization
    unordered_map<string,int> memo;
    memo[""] = 0;

    // store all substrings by length
    vector<set<string>> substrings_by_len(n+1);
    for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j<n;j++){
            temp += s[j];
            substrings_by_len[j-i+1].insert(temp);
        }
    }

    // iterate lengths from 1..n
    for(int len=1; len<=n; len++){
        for(auto &u : substrings_by_len[len]){
            string child1 = u.substr(1);   // u[1:]
            string child2 = u.substr(0, u.size()-1); // u[:-1]

            int res = 1;

            // add DP of child1
            res = (res + memo[child1]) % MOD;

            // add DP of child2 if different
            if(child1 != child2){
                res = (res + memo[child2]) % MOD;
            }

            memo[u] = res;
        }
    }

    cout << memo[s] << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}
