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
    vector<int> d(n),p(n);
    inp(p)
    inp(d)

    set<int> fit;

    set<int> temp;

    vector<int> sol(n);

    for(int i = 0; i < n; i++){
        if(fit.find(d[i]) != fit.end()){
            sol[i] = fit.size();
            continue;
        }

        int k = d[i];
        int x = p[k-1];
        temp.insert(k);

        while(temp.find(x) == temp.end()){
            temp.insert(x);
            x = p[x-1];
        }

        for(auto &el : temp) fit.insert(el);

        sol[i] = fit.size();
        temp.clear();
    }

    for(auto &i : sol) cout << i << " ";


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