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
    int a[n];
    inp(a);

    int x = (a[n-1] - (n*a[0])) / (1 - (n*n));
    int y = a[0] - n*x;

    if(x < 0 || y < 0) cout << "NO";
    else{
        for(int i = 0; i < n; i++){
            if(((n-i)*x + ((i+1)*y)) != a[i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES";    
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