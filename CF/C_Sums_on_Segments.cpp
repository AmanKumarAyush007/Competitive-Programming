#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    set<int> ans;
    ans.insert(0);

    for(auto &i : v) ans.insert(i);

    int ind = -1;
    int val = -1;

    for(int i = 0; i < n; i++){
        if(abs(v[i]) != 1) {
            ind = i;
            val = v[i];
            break;
        }
    }

    auto kad = [&](int st, int en){
        int curr = 0, mx = hell;
        for(int i = st; i <= en; i++){
            curr += v[i]; 
            if(curr < 0) curr = 0;
            mx = max(curr,mx);
        }
        return mx;
    };

    auto init = [&](int st, int en){

        int mx = kad(st,en);

        for(auto &i : v) i *= -1;
    
    
        int mn = -1*kad(st,en);
    
        for(auto &i : v) i *= -1;


        for(int i = mn; i <= mx; i++){
            ans.insert(i);
        }
    
    };


    if(ind == -1) init(0,n-1);
    else{
        int pmn = 0, pmx = 0, smx = 0, smn = 0;

        int curr = 0;

        int mn = 0, mx = 0;

        if(ind - 1 >= 0){

            for(int i = ind-1; i >= 0; i--){
                curr += v[i];
                pmn = min(curr,pmn);
                pmx = max(curr,pmx);
            }

            init(0,ind-1);
        }

        if(ind + 1 <= n-1){

            curr = 0;
    
            for(int i = ind+1; i < n; i++){
                curr += v[i];
                smn = min(curr,smn);
                smx = max(curr,smx);
            }

            init(ind+1,n-1);

        }
        

        int rmin = pmn + val + smn;
        int rmax = pmx + val + smx;


        for(int i = rmin; i <= rmax; i++){
            ans.insert(i);
        }
    }

    cout << ans.size() << nl;
    for(auto &i : ans) cout << i << " ";
    
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