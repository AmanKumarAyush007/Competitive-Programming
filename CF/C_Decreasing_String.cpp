#include<bits/stdc++.h>
using namespace std;

#define int             int64_t
#define ff              first
#define ss              second
#define pb              push_back
#define inf             LLONG_MAX
#define hell            LLONG_MIN
#define nl              '\n'
#define all(a)          (a).begin(),(a).end()
#define rall(a)         (a).rbegin(),(a).rend()
#define sm(v)           accumulate(all(v),0LL)
#define inp(v)          for(auto& x : v) cin >> x;
#define setbit(x)       __builtin_popcountll(x)
#define lg(x)           (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)    partial_sum(all(a), (a).begin());
#define suffixsum(a)    partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif



void solve(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    int n = s.size();

    if(n == 1){
        cout << s;
        return;
    }

    vector<int> pre(n);

    iota(rall(pre),1);
    
    prefixsum(pre);
    
    int pred = lower_bound(all(pre),k) - pre.begin();

    int ind = n - (pred) - (pre[pred] - k) - 1;


    while(pred > 0){

        int sz = s.size();
        string ns;

        ns += s[0];

        for(int i = 1; i < n; i++){

            if(s[i] >= ns[ns.size() - 1]) ns += s[i];
            else{
                while((s[i] < ns[ns.size() - 1]) && pred > 0){
                    ns.pop_back();
                    pred--;
                }
                ns += s[i];
            }

        }

        if(sz == ns.size() && pred > 0){
            while(pred > 0){
                ns.pop_back();
                pred--;
            }
        }
        
        s = ns;
    }

    cout << s[ind];
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