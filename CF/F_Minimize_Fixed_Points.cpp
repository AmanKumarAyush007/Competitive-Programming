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

vector<int> pre(1e5 + 5);

void precompute(){

    for(int i = pre.size() - 1; i >= 1; i--){
        pre[i] = i;
        for(int j = 2; (j*j)<= i; j++){
            if(i % j == 0) {
                pre[i] = i/j;
                break;
            }
        }
    }    
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        v[i] = i;
    }
    for(int i = n; i >= 1; i--){
        int div = pre[i];
        if(div != i) swap(v[i],v[div]);       
    }
    
    for(int i = 1; i <= n; i++){
        cout << v[i] << " ";
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}