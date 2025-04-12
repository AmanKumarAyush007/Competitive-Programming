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
    int n;
    cin >> n;
    int a[n];
    inp(a);
    if(n&1){
        cout << 4 << nl;
        cout << 1 << " " << 2 <<"\n"<< 1 << " " << 2 << nl;
        cout << 2 << " " << n <<"\n"<< 2 << " " << n;
    }
    else{
        cout << 2 << nl;
        cout << 1 << " " << n <<"\n"<< 1 << " " << n;
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