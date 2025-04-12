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

int check(int mx, string &s, vector<int> &v, int k){
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i < n; ){
        if((v[i] >= mx && s[i] == 'R') || mx > v[i]){
            i++;
            continue;
        }
        while(i < n && !(v[i] >= mx && s[i] == 'R')){
            i++;
        }
        cnt++;        
    }
    return cnt;
}


void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n);
    inp(v);
    int hi = *max_element(all(v));
    int lo = 0;
    int ans = hi;
    bool hit = false;
    while(hi >= lo){
        int mid = (lo + hi)/2;
        if(check(mid,s,v,k) <= k){
            ans = mid;
            hi = mid-1;
            hit = true;
        }
        else lo = mid + 1;
    }
    if(ans > 0 && hit) ans--;
    cout << ans;    
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