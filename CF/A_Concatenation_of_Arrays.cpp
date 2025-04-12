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

bool cmp(pair<int,int> x, pair<int,int> y){
    if(max(x.ff,x.ss) == max(y.ff,y.ss)) return min(x.ff,x.ss) < min(y.ff,y.ss);
    return max(x.ff,x.ss) < max(y.ff,y.ss);
}

void solve(){
    int n;
    cin >> n; 
    vector<pair<int,int>> vp(n); 

    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        vp[i] = {x,y};
    }
    sort(all(vp),cmp);
    for(auto &[a,b] : vp) cout << a << " " << b << " ";
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