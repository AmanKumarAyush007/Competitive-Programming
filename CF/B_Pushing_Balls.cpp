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


    int a[n][m],b[n][m],c[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            if(ch == '1') a[i][j] = 1;
            else a[i][j] = 0;
            b[i][j] = a[i][j];
            c[i][j] = a[i][j];
        }
    }

    

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            b[i][j] = min(b[i][j-1],b[i][j]);
        }
    }

    for(int j = 1; j < m; j++){
        for(int i = 1; i < n; i++){
            c[i][j] = min(c[i-1][j],c[i][j]);
        }
    }

    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if((a[i][j] == 1) && (c[i-1][j] == 0) && (b[i][j-1] == 0)){
                cout << "NO" << nl;
                return;
            }
        }
    }
    cout << "YES" << nl;
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