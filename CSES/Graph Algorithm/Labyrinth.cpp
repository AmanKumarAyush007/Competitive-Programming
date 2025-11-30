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

using pi = pair<int,int>;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1 ,0, 0};

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<char>> dir(n,vector<char>(m,'Z'));

    pi st,en;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') st = {i,j};
            if(grid[i][j] == 'B') en = {i,j};
        }
    }


    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    auto traverse = [&](){
        cout << "YES\n";
        
        vector<char> ans; 
        int x = en.ff, y = en.ss;
        
        while(!(x == st.ff && y == st.ss)){            
            ans.pb(dir[x][y]);
            
            if(dir[x][y] == 'U') x += dx[3], y += dy[3];
            else if (dir[x][y] == 'D') x += dx[2], y += dy[2];
            else if (dir[x][y] == 'R') x += dx[0], y += dy[0];
            else  x += dx[1], y += dy[1];
        }

        reverse(all(ans));
        
        cout << ans.size() << nl;
        for(auto &i : ans) cout << i ;
        cout << nl;
    };
    
    
    
    queue<pi> q;
    q.push(st);
    vis[st.ff][st.ss] = 1;

    while(q.size()){
        auto [x,y] = q.front();
        
        for(int i = 0; i < 4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];

            if(X >= n || X < 0 || Y >= m || Y < 0 || grid[X][Y] == '#' || vis[X][Y]) continue;
            
            if(i == 0) dir[X][Y] = 'L';
            if(i == 1) dir[X][Y] = 'R';
            if(i == 2) dir[X][Y] = 'U';
            if(i == 3) dir[X][Y] = 'D';
            
            
            if(!vis[X][Y]){
                q.push({X,Y});
                vis[X][Y] = 1;
            }
        }
        q.pop();
    }


    if(!vis[en.ff][en.ss]) cout << "NO" << nl;
    else traverse();
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