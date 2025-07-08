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
    int n,m;
    cin >> n >> m;

    vector<vector<char>> a(n,vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    if(n*m == 1){
        cout << 0 << nl;
        return;
    }

    queue<pair<int,int>> q;

    map<pair<int,int>, bool> vis; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 && a[i][j] == 'U') || (i == n-1 && a[i][j] == 'D') || (j == 0 && a[i][j] == 'L') || (j == m-1 && a[i][j] == 'R')){
                q.push({i,j});
                vis[{i,j}] = 1;
            }
        }
    }


    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        if(x+1 < n && (!vis[{x+1,y}] ) && (a[x+1][y] == 'U')) {
            q.push({x+1,y});
            vis[{x+1,y}] = 1;
        }
        
        if((x - 1 >= 0) && (!vis[{x-1,y}]) && (a[x-1][y] == 'D')) {
            q.push({x-1,y});
            vis[{x-1,y}] = 1;
        }

        if(y+1 < m && (!vis[{x,y+1}]) && (a[x][y+1] == 'L')) {
            q.push({x,y+1});
            vis[{x,y+1}] = 1;
        }
        
        if(y-1 >=0 && (!vis[{x,y-1}]) && (a[x][y-1] == 'R')) {
            q.push({x,y-1});
            vis[{x,y-1}] = 1;
        }


        auto check = [&](int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m) return;

            if(a[i][j] != '?' || vis[{i,j}]) return;

            if((i+1 < n && (!vis[{i+1,j}]))) return;

            if(((i - 1 >= 0) && (!vis[{i-1,j}]))) return;

            if((j+1 < m && (!vis[{i,j+1}]))) return;

            if((j-1 >=0 && (!vis[{i,j-1}]))) return;

            q.push({i,j});
            vis[{i,j}] = 1;


            // if( (a[i][j] == '?')  &&  (i+1 < n && (vis[i+1][y]))  &&  ((i - 1 >= 0) && (vis[i-1][y])) &&  (j+1 < m && (vis[x][j+1])) &&  (j-1 >=0 && (vis[x][j-1])))
            // {
                //     q.pusj({i,j});
                //     vis[{i,j}] = 1;
            // }
        };

        check(x+1,y);
        check(x-1,y);
        check(x,y+1);
        check(x,y-1);
    }  
    
    
    int ans = n*m;

    for(auto &[a,b] : vis) if(b) ans--;;


    cout << ans << nl;
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