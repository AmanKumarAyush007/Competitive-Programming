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

bool po(int x) {
    int root = sqrt(x);
    return root * root == x;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    if(po(n*(n+1)/2)){
        cout << -1 << nl;
        return;
    }
    for(int i = 0; i < n; i++){
        v[i] = n-i;
    }

    vector<int> pre(n);
    pre[0] = v[0];
    for(int i = 1; i < n; i++){
        pre[i] = v[i] + pre[i-1];
    }

    for(int i = 0; i < n-1; i++){
        if(po(pre[i])) swap(v[i],v[i+1]);
    }
    for(auto &i : v) cout << i << " ";
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