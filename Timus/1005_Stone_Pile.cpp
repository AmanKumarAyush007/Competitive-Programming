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

set<int> st;

void subsm(vector<int> &v,int sum,int i){
    if(i == v.size()) {
        st.insert(sum);
        return;
    }
    subsm(v,sum + v[i],i+1);      //take
    subsm(v,sum,i+1);           //leave
}


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    subsm(v,0,0);
    int ans = INT_MAX;
    int sum = sm(v);
    // for(auto &i : st) cout << i << " ";
    for(auto &i : st) {
        if(i != sm(v) && (st.find(sum-i) != st.end())) ans = min(abs(i-(sum - i)),ans);
    }
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}