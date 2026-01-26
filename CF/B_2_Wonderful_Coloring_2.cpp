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



void solve(){
    int n,k;
    cin >> n >> k;
    
    vector<int> v(n);
    inp(v);

    vector<int> sol(n,0);
    map<int,set<int>> mp;

    for(int i = 0; i < n; i++){
        mp[v[i]].insert(i);
    }
    


    int rem = n;
    int col = 1;

    for(auto &[x,st] : mp){
        if(st.size() >= k){
            auto it = st.begin();
            advance(it, k);
            vector<int> nv(st.begin(), it);
            for(auto &i : nv){
                sol[i] = col;
                col++;
            } 
            col = 1;
            
            rem -= st.size();
        }
    }

    int left = rem/k;
    int curr = 0;


    for(auto &[x,st] : mp){
        if(curr == left) break;
        if(st.size() < k){
            vector<int> nv(st.begin(), st.end());
            for(auto &i : nv){
                sol[i] = col;
                rem--;
                col++;
                if(col > k) {
                    col = 1;
                    curr++;
                    if(curr == left) break;
                }
            }
        }
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