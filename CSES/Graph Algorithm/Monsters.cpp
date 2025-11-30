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
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dis(n, vector<int>(m,1e9));
    vector<vector<bool>> vis(n, vector<bool>(m,false));

    queue<pi> q;

    pi st;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'M') {
                dis[i][j] = 1;
                q.push({i,j});
                vis[i][j] = 1;
            }
            if(grid[i][j] == 'A') st = {i,j};
        }
    }

    if(st.ff == 0 || st.ff == n-1 || st.ss == 0 || st.ss == m-1){
        cout << "YES" << nl << 0;
        return;
    }


    while(q.size()){
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int a = x + dx[i];
            int b = y + dy[i];
            
            if(a >= n || a < 0 || b >= m || b < 0 || (grid[a][b] != '.') || vis[a][b]) continue;

            dis[a][b] = dis[x][y] + 1;
            q.push({a,b});
            vis[a][b] = 1;

        }
    }


    vector<vector<char>> dir(n, vector<char>(m, '#'));

    for(auto &i : vis) fill(all(i),false);
    map<pi,int> time;

    q.push(st);
    vis[st.ff][st.ss] = 1;
    time[st] = 1;

    auto traverse = [&](int x, int y){
        cout << "YES\n";
        string ans;
        while(grid[x][y] != 'A'){
            ans += dir[x][y];
            if(dir[x][y] == 'R') y--;
            else if(dir[x][y] == 'L') y++;
            else if(dir[x][y] == 'U') x++;
            else x--;
        }
        reverse(all(ans));
        cout << ans.size() << nl << ans;
    };

    while(q.size()){
        auto [x,y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){

            int a = x + dx[i];
            int b = y + dy[i];
            
            if(a >= n || a < 0 || b >= m || b < 0 || (grid[a][b] != '.') || vis[a][b]) continue;

            time[{a,b}] = time[{x,y}] + 1;
            if(time[{a,b}] < dis[a][b]){

                q.push({a,b});
                vis[a][b] = 1;
    
                if(i == 0) dir[a][b] = 'D';
                else if(i == 1) dir[a][b] = 'U';
                else if(i == 2) dir[a][b] = 'R';
                else dir[a][b] = 'L';
    
                if(a == 0 || a == n-1 || b == 0 || b == m-1){
                    traverse(a,b);
                    return;
                }
            }

        }
    }

    cout << "NO" << nl;
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