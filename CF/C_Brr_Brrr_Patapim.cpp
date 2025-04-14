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
    int n;
    cin >> n;

    set<int> st;
    for(int i = 1; i <= 2*n; i++){
        st.insert(i);
    }

    vector<int> sol(2*n,-1);
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            // cout << a[i][j] << " ";
            // cout << i+j+2-1 << " ";
            sol[i+j + 2 - 1] = a[i][j];
            st.erase(a[i][j]);
        }
        // cout << nl;
    }

    // for(auto &i : st) cout << i << " ";
    // cout << 

    for(int i = 0; i < n; i++){
        if(sol[i] == -1) sol[i] = *st.begin();
    }

    for(auto &i : sol) cout << i << " ";
    
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