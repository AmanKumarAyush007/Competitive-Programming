#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n),a(k);
    inp(v)
    inp(a)


    auto lft = [&](int st, int en){
        
        int res = 0;

        for(int i = st; i <= en; i++){
            res++;
            while(i+1 <= en && v[i] == v[i+1]) i++;
        }

        return res;
    };

    auto rght = [&](int st, int en){
        
        int res = 0;

        for(int i = en; i >= st; i--){
            res++;
            while(i-1 >= st && v[i] == v[i-1]) i--;
        }

        return res;
    };


    int fst = -1, lst = -1;
    int ind = a[0] - 1;

    for(int i = 0; i < ind; i++){
        if(v[i] != v[ind]){
            fst = i;
            break;
        }
    }


    for(int i = n-1; i >= a[0]; i--){
        if(v[i] != v[ind]){
            lst = i;
            break;
        }
    }


    int ans = 0;
    
    if(fst != -1 && lst != -1) ans = max(lft(fst,ind), rght(ind, lst));
    else if(fst != -1) ans = lft(fst,ind);
    else if(lst != -1) ans = rght(ind, lst);
    

    cout << ans << nl;
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