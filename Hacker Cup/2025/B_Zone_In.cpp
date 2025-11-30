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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
using pi = pair<int,int>;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<char>> mat(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m, false));
    vector<vector<int>> dis(n,vector<int>(m,1000));

    queue<pi> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#' || i == 0 || i == n-1 || j == 0 || j == m-1) {
                q.push({i,j});
                vis[i][j] = true;
                dis[i][j] = 0;
            }
        }
    }

    int ans = 0;

    while(q.size()){
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            
            if(X >= n || Y >= m || X < 0 || Y < 0 || vis[X][Y] || (dis[x][y] + 1 >= k)) continue;

            dis[X][Y] = dis[x][y] + 1;
            

            q.push({X,Y});
            vis[X][Y] = 1;
        }


    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dis[i][j] >= k)  ans++;
        }
    }


    cout << ans << nl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}