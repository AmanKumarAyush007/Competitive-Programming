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
    int mx = INT_MIN;
    int s = 0, e = 0;
    for(int i = 0; i < n; i++){
        int inv = 0;
        for(int j = i; j < n; j++){
            if(a[i] > a[j]) inv++;
            else if(a[i] < a[j]) inv--;
            if(inv > mx) {
                s = i;
                e = j;
                mx = inv;
            }
        }
    }
    s++, e++;
    cout << s << " " << e;
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