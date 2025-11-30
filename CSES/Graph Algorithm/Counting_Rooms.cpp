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
#define inf              LLONG_MAXhil
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
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    queue<pi> q;

    vector<vector<int>> fnd(n,vector<int>(m,0));

    auto bfs = [&](int a, int b){

        if(fnd[a][b]){
            return 0;
        }

        q.push({a,b});
        fnd[a][b] = 1;

        
        while(q.size()){
            auto [x,y] = q.front();
            for(int i = 0; i < 4; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X >= n || X < 0 || Y < 0 || Y >= m) continue;
                if((fnd[X][Y] == 0) && grid[X][Y] == '.') {
                    q.push({X,Y});
                    fnd[X][Y]++;
                }
            }
            q.pop();
        }


        return 1;

    };

    int ans = 0;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                ans += bfs(i,j);
            }
        }
    }

    cout << ans;
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