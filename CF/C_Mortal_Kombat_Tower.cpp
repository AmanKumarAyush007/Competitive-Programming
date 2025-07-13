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

vector<vector<int>> dp;
vector<int> v;
int n;

int rec(int curr, int turn){
    if(curr >= n) return 0;
    
    if(dp[curr][turn] != -1) return dp[curr][turn];

    int ans = 0;

    if(turn == 1){
        ans = min(rec(curr+1,turn^1),rec(curr+2,turn^1));
    }
    else{
        ans = min(v[curr] + rec(curr+1,turn^1), v[curr] + (((curr+1) >= n) ? 0 : v[curr+1]) + rec(curr+2,turn^1));
    }

    return dp[curr][turn] = ans;
}


void solve(){
    cin >> n;
    v.resize(n);
    inp(v)
    dp.assign(n + 5, vector<int>(2, -1));
    cout << rec(0,0);
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}