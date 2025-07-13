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

int fun(int n){
    int x = 0;
    for(int i = 0; i < 61; i++){
        x += (1L<<i);
        if(x >= n) return i;
    }
    return -1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)
    
    int curr = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]){
            int j = i+1;
            while(j < n && v[j] < v[i]) {
                curr = max(curr, v[i] - v[j]);
                j++;
            }
            i = j-1;
        }
    }
    
    cout << fun(curr) + (curr != 0) << nl;
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