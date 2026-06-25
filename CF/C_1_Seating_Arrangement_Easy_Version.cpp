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
    int n, x, s;
    cin >> n >> x >> s;

    string st;
    cin >> st;

    vector<string> v(x);
    
    int rem = x;
    int i = 0, j = 0;
    int omni = 0;

    auto upd_i = [&](){
        while(i < x && v[i].size() > 0)
            i++;
    };
    
    auto upd_j = [&](){
        while(j < x && v[j].size() == s)
            j++;
    };


    for(auto &c : st){
        if(c == 'I'){
            upd_i();
        
            if(i < x){
                v[i] += c;
        
                upd_i();
                upd_j();
            }
        }
        else if(c == 'A'){
            upd_i();
            upd_j();
        
            if(i > 0 && j < x && v[j].size() < s){
                if(v[j].size() > 0)
                    omni++;
        
                v[j] += c;
        
                upd_i();
                upd_j();
            }
            else{
                upd_i();
        
                if(i < x){
                    v[i] += c;
        
                    upd_i();
                    upd_j();
                }
            }
        }
        else{
            upd_j();
        
            if(j < x && v[j].size() > 0){
                v[j] += c;
        
                upd_i();
                upd_j();
            }
            else if(omni > 0 && j < x){
                v[j] += c;
                omni--;
        
                upd_i();
                upd_j();
            }
        }
    }


    int ans = 0;

    for(auto &i : v) ans += i.size();

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