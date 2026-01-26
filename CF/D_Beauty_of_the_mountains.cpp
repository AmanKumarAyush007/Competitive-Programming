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



void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    int grid[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<string> v(n);
    inp(v);

    int x = 0, y = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == '0') x += grid[i][j];
            else y += grid[i][j];
        }
    }


    if(x == y){
        cout << "YES\n";
        return;
    }

    set<int> st;

    int pre[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pre[i][j] = v[i][j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            pre[i][j] += pre[i][j-1];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            pre[j][i] += pre[j-1][i];
        }
    }


    for(int i = 0; i+k-1 < n; i++){
        for(int j = 0; j+k-1 < m; j++){
            int sti = i, eni = i+k-1;
            int stj = j, enj = j+k-1;

            if(sti >= n || stj >= m || eni >= n || enj >= m || sti > eni || stj > enj) continue;

            int val = pre[eni][enj];
            if(sti > 0) val -= pre[sti-1][enj];
            if(stj > 0) val -= pre[eni][stj-1];
            if(sti > 0 && stj > 0) val += pre[sti-1][stj-1];

            int cnt = k*k - val;
            val = abs(cnt-val);
            
            if(val > 0) st.insert(val);
        }
    }

    if(!st.size()){
        cout << "NO\n";
        return;
    }

    int g = *st.begin();

    for(auto &i : st) g = gcd(i,g);

    if(abs(x-y) % g == 0) cout << "YES";
    else cout << "NO";
    cout << nl;
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