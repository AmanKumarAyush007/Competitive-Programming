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
    int n,k;
    cin >> n >> k;
    int a[n],b[n];
    inp(a);
    inp(b);
    vector<int> s(n+1);
    for(int i = 0; i < n; i++){
        s[abs(b[i])] += a[i];
    }
    int lft = 0;
    for(int i = 1; i <= n; i++){
        lft += k - s[i];
        if(lft < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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