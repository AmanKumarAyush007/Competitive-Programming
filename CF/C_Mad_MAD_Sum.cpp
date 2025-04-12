#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for(auto &i : a) {
        cin >> i;
        sum += i;
    }
    // cout << sum;
    if(n == 1) {
        cout << sum << nl;
        return;
    }
    bool ck = true;
    set<int> s;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        if(mp[a[i]] >= 2) s.insert(a[i]);
        if(s.size() == 0) a[i] = 0;
        else {
            a[i] = *s.rbegin();
        }
    }
    
    int pre[n];
    pre[0] = a[0];
    

    for(int i = 1; i <= n ; i++){
        pre[i] = a[i] + pre[i-1];
    }
    
    



    for(auto &i : pre) cout << i << " ";
    // cout << nl;
    for(auto &i : pre) sum += i;

    cout << sum << nl;
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