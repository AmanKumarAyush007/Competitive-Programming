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
    int a[n],b[n];
    inp(a);
    inp(b);
    int diff[n];
    int cnt0 = 0;
    vector<int> neg;
    multiset<int> ms;

    for(int i = 0; i < n; i++){
        diff[i] = b[i] - a[i];
        if(diff[i] == 0) cnt0++;
        else if(diff[i] < 0) neg.pb(abs(diff[i]));
        else{
            ms.insert(diff[i]);
        }
    }

    int ans = 0;

    for(int i = 0; i < neg.size(); i++){
        auto it = ms.lower_bound(neg[i]);
        if(it != ms.end()){
            ans++;
            ms.erase(it);
        }
    }

    cout << ans + (ms.size() + cnt0)/2;

    // for(auto &i : diff) cout << i << " ";

    

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