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

    vector<int> v(n);
    inp(v);

    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(v[i]);
    }

    int rest = n - st.size();

    set<int> used;

    if(rest == 0){
        for(int i = 0; i < k; i++){
            cout << v[i] << " ";
        }
    }
    else if(rest == 1){
        for(int i = 1; i <= n; i++){
            if(!st.count(i)){
                cout << i << " ";
                used.insert(i);
                k--;
                break;
            }
        }
        if(k){
            for(int i = 1; i <= n; i++){
                if(i != v[n-1] && !used.count(i)){
                    cout << i << " ";
                    used.insert(i);
                    k--;
                    break;
                }
            }
        }

        if(k){
            for(int i = 1; i <= n; i++){
                if(k == 0) break;
                if(!used.count(i)){
                    cout << i << " ";
                    used.insert(i);
                    k--;
                }
            }
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            if(k == 0) break;
            if(!st.count(i)){
                cout << i << " ";
                used.insert(i);
                k--;
            }
        }

        for(int i = 1; i <= n; i++){
            if(k == 0) break;
            if(!used.count(i)){
                cout << i << " ";
                used.insert(i);
                k--;
            }
        }
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