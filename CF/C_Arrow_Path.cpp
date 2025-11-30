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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve(){
    int n;
    cin >> n;

    char grid[2][n];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    queue<pi> q;

    map<pi,int> used;

    q.push({0,0});

    used[{0,0}]++;


    while(!q.empty()){

        auto [X,Y] = q.front();    
        q.pop();    

        
        for(int i = 0; i < 4; i++){
            int x = X, y = Y;
            x += dx[i];
            y += dy[i];
            if(x >= 0 && x < 2 && y >= 0 && y < n){
                
                if(grid[x][y] == '<') y--;
                else y++;

                if(x == 1 && y == n-1){
                    cout << "YES\n";
                    return;
                }

                if(!used.count({x,y})) {
                    q.push({x,y});
                    used[{x,y}]++;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}