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
    int a[n], b[m];
    inp(a)
    inp(b)

    int ans = inf;

    vector<int> pre(m,inf), suff(m,hell);

    int i = 0, j = 0;

    while(i < n && j < m){
        if(a[i] >= b[j]){
            pre[j] = i;
            i++;
            j++;
        }
        else i++;
    }

    i = n-1;
    j = m-1;

    while(i >= 0 && j >= 0){
        if(a[i] >= b[j]){
            suff[j] = i;
            i--;
            j--;
        }
        else i--;
    }


    if(pre[m-1] != inf) {
        cout << 0 << nl;
        return;
    }
    
    for(int j = 1; j < m-1; j++){
        if(suff[j + 1] > pre[j - 1]) ans = min(b[j],ans);
    }

    if(suff[1] != hell) ans = min(b[0],ans);
    if(pre[m-2] != inf) ans = min(b[m-1],ans);
    

    if(ans == inf) cout << -1 << nl;
    else cout << ans << nl;
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