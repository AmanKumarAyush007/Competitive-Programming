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
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n,k;
    cin >> n >> k;
    if(n < 2*k) cout << -1;
    else{
        vector<int> v(n+1);
        for(int i = 0; i < k; i++){
            int lst = (k*((n-i)/k)) + i;
            // cout << lst << nl;
            for(int j = 1; j <= n; j++){
                if(j % k == i) {
                    v[j] = lst;
                    lst -= k;
                }
            }       
        }
        for(int i = 1; i <= n; i++){
            if(v[i] == i) {
                if(i+k <= n) swap(v[i],v[i+k]);
                else swap(v[i],v[i-k]);
            }
        }
        for(int i = 1; i <= n; i++){
            cout << v[i] << " ";
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