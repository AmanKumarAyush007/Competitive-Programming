#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    inp(a);
    vector<int> v(n+1);
    for(auto &i : a) if(i <= n) v[i]++;

    for(int i = 0; i < n+1; i++){
        if(v[i] == 0){
            cout << i << nl;
            return;
        }
        int diff = 0;
        if(v[i] > 1) {
            diff = v[i] - 1;
            v[i] = 1;
        }
        if(i+k < n) v[i+k] += diff;
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