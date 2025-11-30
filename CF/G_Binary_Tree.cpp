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
#define nl               endl
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
    int n;
    cin >> n;
    
    vector<pi> child(n+1);
    vector<int> par(n+1);

    for(int i = 1; i <= n; i++){
        cin >> child[i].ff >> child[i].ss;
    }

    for(int i = 1; i <= n; i++){
        par[child[i].ff] = i;
        par[child[i].ss] = i;
    }


    auto ask = [&](int x, int y){
        cout << "? " << x << " " << y << nl;
        int res;
        cin >> res;
        return res;
    };


    auto base = [&](){
        int root = -1;
        vector<bool> isChild(n+1,false);

        for(int i=1; i<=n; i++){
            if(child[i].ff != 0) isChild[child[i].ff] = true;
            if(child[i].ss != 0) isChild[child[i].ss] = true;
        }

        for(int i=1; i<=n; i++){
            if(!isChild[i]){
                root = i;
                break;
            }
        }

        return root;
    };

    int root = base();


    while (true) {
        auto [l, r] = child[root];
    
        if (l == 0 && r == 0) {
            cout << "! " << root << nl;
            cout.flush();
            return;
        }
    
        if (l == 0) {
            int res = ask(root, r);
            if (res == 0) {  
                cout << "! " << root << nl;
                cout.flush();
                return;
            } else {       
                root = r;
            }
        }
        else if (r == 0) {
            int res = ask(root, l);
            if (res == 0) {  
                cout << "! " << root << nl;
                cout.flush();
                return;
            } else {         
                root = l;
            }
        }
        else {
            int res = ask(l, r);
            if (res == 0) root = l;       
            else if (res == 2) root = r;  
            else {                        
                cout << "! " << root << nl;
                cout.flush();
                return;
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