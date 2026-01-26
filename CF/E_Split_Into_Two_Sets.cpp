#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

vector<vector<int>> adj;
vector<int> col;
bool ok = true;

void dfs(int x, int turn){
    col[x] = turn;

    for(auto &i : adj[x]){
        if(col[i] == -1){
            dfs(i, turn^1);
        }
        else{
            if(col[i] != turn^1){
                ok = false;
                return;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;

    ok = true;

    adj.assign(n,{});
    col.assign(n,-1);
    map<int,set<int>> mp;
    

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(x == y) ok = false;
        mp[x].insert(i);
        mp[y].insert(i);
    }

    if(!ok){
        cout << "NO\n";
        return;
    }

    for(auto &[a,b] : mp){
        if(b.size() != 2) {
            cout << "NO\n";
            return;
        }
        int x = *b.begin();
        b.erase(b.begin());
        int y = *b.begin();
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 0; i < n; i++){
        if(col[i] == -1 && ok) dfs(i,0);
    }

    cout << (ok ? "YES" : "NO") << nl;
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