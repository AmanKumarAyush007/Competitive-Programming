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

int n,m,sx,sy, ex,ey;
bool found = false;

set<pair<pi,pi>> st;

void dfs(int x, int y, int dx, int dy, int ans = 0){
    int sz = st.size();
    st.insert({{x,y},{dx,dy}});

    if(sz == st.size()) return;

    if(x == ex && y == ey){
        found = 1;
        cout << ans << nl;
        return;
    }

    int nx = x + dx, ny = y + dy;

    if(nx <= n && nx >= 1 && ny >= 1 && ny <= m){
        dfs(nx,ny,dx,dy,ans);
    }
    else {
        if(nx > n || nx < 1) dx *= -1;
        if(ny > m || ny < 1) dy *= -1;

        nx = x + dx;
        ny = y + dy;
        dfs(nx,ny,dx,dy,ans+1);
    }

}

void solve(){
    cin >> n >> m >> sx >> sy >> ex >> ey;
    st.clear();
    found = false;
    
    string s;
    cin >> s;

    int dx = (s[0] == 'D' ? 1 : -1);
    int dy = (s[1] == 'R' ? 1 : -1);

    dfs(sx,sy,dx,dy);

    if(!found) cout << -1 <<nl;
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