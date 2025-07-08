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

    vector<int> v(n);
    inp(v)

    map<int,int> mp;

    for(auto &i : v) mp[i]++;


    vector<pair<int,int>> vp;

    int rest = 0;
    int curr = 0;

    for(int i = 0; i <= n; i++){
        vp.push_back({mp[i],n-curr+rest});
        if(mp[i]==0){
            break;
        }
        rest += mp[i]-1;
        curr += mp[i];

    }


    vector<int> tot(n+2,0);

    for(int i = 0; i < vp.size(); i++){
        int st = vp[i].ff, en = vp[i].ss;
        tot[st]++;
        tot[en+1]--;
    }

    for(int i = 1; i < n+1; i++){
        tot[i] += tot[i-1];
    }

    for(int i = 0; i < n+1; i++){
        cout << tot[i] << " ";
    }


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