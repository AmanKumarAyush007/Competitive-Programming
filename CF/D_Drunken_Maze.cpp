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
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    inp(v);

    int dp[n][m][4][4];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    dp[i][j][k][l] = inf;
                }
            }
        }
    }

    queue<array<int,4>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'S') {
                q.push({i,j,0,0});
                dp[i][j][0][0] = 0;
            }
        }
    }

    int ans = inf;

    while(q.size()){
        auto [x,y,dir,l] = q.front();
        q.pop();

        if(v[x][y] == 'T'){
            ans = min(ans, dp[x][y][dir][l]);
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            int nL = l*(dir == i) + 1;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] == '#' || nL >= 4 || dp[nx][ny][i][nL] != inf) continue;

            dp[nx][ny][i][nL] = 1 + dp[x][y][dir][l];
            q.push({nx,ny,i,nL});
        }
    }

    if(ans == inf) ans = -1;

    cout << ans << nl;
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