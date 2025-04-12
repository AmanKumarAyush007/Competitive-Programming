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

bool check(int mid, vector<int> &v){
    vector<int> bit(22,0);
    int n = v.size();
    int st = 0;
    for(int i = 0; i < mid; i++){

        for(int j = 0; j < 22; j++){
            bit[j] += (bool)(v[i] & (1LL << j));
        }

        st |= v[i]; 
    }
    for(int i = 1; i <= n-mid; i++){

        for(int j = 0; j < 22; j++){
            bit[j] -= (bool)(v[i-1] & (1LL << j));
        } 

        for(int j = 0; j < 22; j++){
            bit[j] += (bool)(v[i+mid-1] & (1LL << j));
        }

        int temp = 0;    
        for(int i = 0; i < 22; i++){
            if(bit[i]) temp = (temp | (1LL << i));
        }

        if(temp != st) return false;
    }
    return true;
}


void solve(){
    int n; cin >> n;
    vector<int> v(n);
    inp(v);
    int hi = v.size();
    int lo = 1;
    int ans = 1;

    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(check(mid,v)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
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