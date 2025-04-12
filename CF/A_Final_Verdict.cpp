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
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    inp(a);
    int to = sm(a);
    // int avg = ceil(1.0*to/n);
    // // cout << avg;

    if((to%(x*n) == 0)) cout << "YES";
    else cout <<"NO";

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