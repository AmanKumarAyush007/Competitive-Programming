#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    inp(a);
    inp(b);
    int mx = -1, ind = -1;
    for(int i = 0; i < m; i++){
        if(b[i] > mx){
            mx = b[i];
            ind = i;
        }
    }
    
    



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