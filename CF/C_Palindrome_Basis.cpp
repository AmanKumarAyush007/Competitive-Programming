#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)

const int MOD = 1e9 + 7;

vector<vector<int>> dp(4e4 + 5);
vector<int> v;


int ways(int n, int i){
    if(n < 0 || i >= v.size()) return 0;
    if(n == 0) return 1;

    if(dp[n][i] != -1) return dp[n][i];

    int ans = 0;

    ans = ((ways(n,i+1)%MOD) + (ways(n-v[i],i)%MOD)) % MOD;

    return dp[n][i] = ans;
}



void solve(){
    int n;
    cin >> n;
    cout << ways(n,0);
    cout << nl;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    for(int i = 1; i <= 4e4; i++){
        if(i <= 9) v.pb(i);
        else{
            string s = to_string(i);
            bool ck = 1;
            for(int j = 0; j <= s.size()/2; j++){
                if(s[j] != s[s.size()-j-1]) ck = 0;
            }
            if(ck) v.push_back(i);
        }
    }



    for(auto &i : dp) {
        i.resize(v.size() + 1,-1);
    }


    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}