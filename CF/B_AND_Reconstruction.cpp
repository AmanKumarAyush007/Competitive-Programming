#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n-1];
    for(int i = 0; i < n-1; i++){
        cin >> a[i];
    }
    vector<int> v;
    v.pb(a[0]);
    for(int i = 0; i < n-2; i++){
        int ele = a[i] | a[i+1];
        v.pb(ele);
    }
    int nxt = 0;
    for(int i = 0; i < 32; i++){
        if((v[n-2]&(1LL<<i) == 0) && (a[n-2]&(1LL<<i) != 0)){
            cout << -1 << nl;
            return;
        }
        else{
            nxt+=(v[n-2]&(1LL<<i)) & (a[n-2]&(1LL<<i));
        }
    }
    v.pb(nxt);
    for(int i = 0; i < v.size()-1; i++){
        if((v[i]&v[i+1]) != a[i]){
            cout << -1 << nl;
            return;
        }
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