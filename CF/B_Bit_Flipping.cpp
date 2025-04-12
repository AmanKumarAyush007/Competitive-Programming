#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k == 0) {
        cout << s << nl;
        while(n--) cout << 0 << " ";
        cout << nl;
        return;
    }
    vector<int> v(n,0);
    int sum = 0;
    if(k&1){
        for(int i = 0; i < n; i++){
            if(sum >= k) break;
            if(s[i] == '0') {
                v[i] = 0;
            }
            else v[i] = 1;
            sum += v[i];
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(sum >= k) break;
            if(s[i] == '1') {
                v[i] = 0;
            }
            else v[i] = 1;
            sum += v[i];
        }
    }


    if(k - sum > 0){
        int rest = k-sum;
        int pre = v[n-1];
        v[n-1] += rest;
        
    }

    for(int i = 0; i < n; i++){
        if((k-v[i])%2 == 1){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    
    cout << s << nl;

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