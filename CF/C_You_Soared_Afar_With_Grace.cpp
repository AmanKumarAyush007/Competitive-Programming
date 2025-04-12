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


void solve(){
    int n;
    cin >> n;
    int a[n],b[n];
    inp(a)
    inp(b)

    set<pair<int,int>> st;

    map<pair<int,int>,int> mp;
    vector<pair<int,int>> vp(n);

    for(int i = 0; i < n; i++){
        mp[{a[i],b[i]}] = i;
        vp[i] = {a[i],b[i]};
    }

    int sme = 0;

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) st.insert({a[i],b[i]});
        else sme++;
    }



    for(auto &pr : st){
        pair<int,int> k = {pr.ss,pr.ff};
        if(st.find(k) == st.end()){
            cout << -1 << nl;
            return;
        }
    }

    if(sme > 1){
        cout << -1 << nl;
        return;
    }

    deque<pair<int,int>> dq;

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) dq.pb({a[i],b[i]});
    }
    
    while(!st.empty()){
        auto it = st.begin();
        int x = it->ff;
        int y = it->ss;
        dq.push_back({x,y});
        dq.push_front({y,x});
        st.erase({x,y});
        st.erase({y,x});
    }
    
    vector<pair<int,int>> v(all(dq));

    vector<pair<int,int>> sol;

    for(int i = 0; i < v.size(); i++){
        if(v[i] != vp[i]) {
            int ind = mp[v[i]];
            swap(vp[i],vp[ind]);
            swap(mp[vp[i]], mp[vp[ind]]);
            sol.pb({i+1, ind+1});    
        }
    }

    cout << sol.size() << nl;

    for(auto &[a,b] : sol) cout << a << " " << b << nl;

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