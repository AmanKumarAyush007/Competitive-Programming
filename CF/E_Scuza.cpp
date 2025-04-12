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
    int n,q;
    cin >> n >> q;
    int a[n];
    inp(a);
    vector<int> preM(n),preS(n);
    preM[0] = a[0], preS[0] = a[0];
    for(int i = 1; i < n; i++){
        preM[i] = max(preM[i-1],a[i]);
        preS[i] = preS[i-1]+a[i];
    }
    while(q--){
        int x;
        cin >> x;
        auto it = upper_bound(all(preM),x);
        if(it == preM.begin()) cout << 0 << " ";
        else if(it == preM.end()) cout << preS[n-1] << " ";
        else cout << preS[it - preM.begin() - 1] <<  " ";
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