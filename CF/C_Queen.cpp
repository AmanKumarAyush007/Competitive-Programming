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


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1,vector<int>());

    map<int,int> mp;

    int st = -1;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x != -1){
            adj[i+1].pb(x);  
            adj[x].pb(i+1);               
            mp[i+1] = y;
        }
        else st = i+1;
    }


    vector<bool> vis(n+1,false);
    queue<int> q;

    vis[st] = true;
    q.push(st);

    vector<int> sol;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        bool check = true;
        if(mp[curr] == 0) check = false;

        for(auto &i : adj[curr]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                if(mp[i] == 0) check = false;
            }
        }

        if(check) sol.pb(curr);
    }

    sort(all(sol));
    
    if(sol.size() == 0) cout << -1;
    else for(auto &i : sol) cout << i << " ";

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}