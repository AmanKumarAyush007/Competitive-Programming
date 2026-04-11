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

using pi = pair<int,int>;


void solve(){
    int x, y;
    cin >> x >> y;

    int best = inf;
    int ansp = 0, ansq = 0;

    bool ok = 0;
    
    auto eval = [&](){
        int p = x;
        int q = y;

        for(int i = 0; i <= 30; i++){
            if((1LL << i) & p){
                if(((1LL << i) & p) == ((1LL << i) & q)){
                    q &= ~(1LL << i);
                }
            }
        }

        debug(p,q);

        if((abs(x-p) + abs(y - q)) <= best){
            cout << "fst\n";
            best = min(best, (abs(x-p) + abs(y - q)));
            debug(best, p,q, ok);
            ansp = p, ansq = q;
            if(ok) swap(ansp,ansq);
        }


        for(int i = 31; i >= 0; i--){
            q = y;
            if(((1LL << i) & p) == 0){
                if(((1LL << i) & q) == 0){
                    // debug(q,i);
                    q |= (1LL << i);
                    debug(q);
                    q &= ~((1LL << i) - 1);
                    debug(q);
                    
                    if((abs(x-p) + abs(y - q)) <= best){
                        debug(q,i);
                        
                        best = min(best, (abs(x-p) + abs(y - q)));
                        debug(best, p,q, ok);

                        ansp = p, ansq = q;
                        if(ok) swap(ansp, ansq);

                        // break;
                    }
                }   
            }
        }
    };



    eval();
    swap(x,y);
    ok = 1;
    eval();

    cout << ansp << " " << ansq << nl;
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