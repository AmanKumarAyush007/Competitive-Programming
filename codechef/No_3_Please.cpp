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
    vector<int> a(n);
    inp(a)

    vector<int> b = a;
    

    for(int i = 1; i < n; i++){
        a[i] += a[i-1];
    }

    int cnt = 0;
    int ck = -1;

    for(int i = 0; i < n-1; i++){
        if(a[i] % 3 == 0){
             cnt++;
             ck = i;
        }
        if(cnt > 1) {
            cout << "No\n";
            return;
        }
    }
    int sum = 0;
    for(int i = ck+1; i >= 0; i--){
        sum += b[i];
        if(sum % 3 == 0) {
            cout << "No\n";
            return;
        }
    }



    if(a[n-1] % 3 == 0) cout << "No" << nl;
    else cout <<"Yes" << nl;
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