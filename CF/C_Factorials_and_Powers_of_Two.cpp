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

const int limit = 1e12;
vector<int> fact;
vector<pair<int,int>> tot;

void rec(int i, int sum, int cnt){
    if(i == (fact.size() - 1)) {
        tot.pb({sum,cnt});
        return;
    }

    rec(i+1,sum, cnt);
    rec(i+1,sum + fact[i],cnt + 1);
}

void solve(){
    int n;
    cin >> n;
    int ans = inf;
    for(int i = 0; i < tot.size(); i++){
        if(tot[i].ff > n) break;
        else {
            int rest = n-tot[i].ff;
            ans = min(ans,tot[i].ss + setbit(rest));
        }
    }
    
    cout << ans << nl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact.pb(1);
    
    int k = 2;
    
    while(fact[fact.size()-1] < limit){
        fact.pb(fact[fact.size()-1] * k);
        k++;
    }
    rec(0,0,0);

    sort(all(tot));
    // cout << tot[tot.size()-1];

    // cout << tot.size() << nl;
   
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}