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
    string s;
    cin >> s;
    int l = 0, r = 0, wl = 0, wr = 0;

    int ck = 1;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == 'S'){
            if(ck) l++;
            else r++;
        }
        else if(s[i] == 'R'){
            if(ck) r++;
            else l++;
            ck = 1^ck;
        }
        else{
            if(i == n-1){
                if(wl > wr)cout << wl << " " << "(winner)" << " - " << wr << nl;
                else cout << wl << " - " << wr << " " << "(winner)" << nl; 
            }
            else{
                if(ck) cout << wl << " " << "(" << l << "*)" << " - " << wr << " " << "(" << r << ")" << nl;
                else cout << wl << " " << "(" << l << ")" << " - " << wr << " " << "(" << r << "*)" << nl;
                
            }

        }
        if(l >= 10 || r >= 10 || (abs(l-r) >= 2 && max(l,r) >= 5)){
            if(l > r) wl++;
            else wr++;
            l = 0, r = 0;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}