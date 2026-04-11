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
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    vector<int> v(n);
    inp(v);

    int x = v[p-1];

    multiset<int> ms;
    for(int i = 0; i < k; i++){
        ms.insert(v[i]);
        if(i == p-1) ms.insert(-1);
    }

    int ans = 0;

    deque<int> dq;

    for(int i = k; i < n; i++){
        if(i == p-1) dq.pb(-1);
        dq.pb(v[i]);
    }


    
    while(m > 0){

        int fst = *ms.begin();
        
        if(fst == -1){
            if(m >= x){
                m -= x;
                if(dq.size()){
                    ms.erase(ms.find(x));
                    ms.erase(ms.find(-1));
                    ms.insert(dq.front());
                    dq.pop_front();
                    dq.push_back(-1);
                    dq.pb(x);
                }
                
                ans++;
            }
            else break;
        }
        else{
            if(m >= fst){
                m -= fst;
                if(dq.size()){
                    ms.erase(ms.find(fst));
                    if(dq.front() == -1){
                        ms.insert(dq.front());
                        dq.pop_front();
                    }
                    ms.insert(dq.front());
                    dq.pop_front();

                    dq.pb(fst);
                }
            }
            else break;
        }

    }


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