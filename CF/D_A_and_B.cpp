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
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    vector<int> a,b;

    for(int i = 0; i < n; i++){
        if(s[i] == 'a') a.pb(i);
        else b.pb(i);
    }

    if(a.size() == 0 || b.size() == 0){
        cout << 0 << nl;
        return;
    }


    auto calc = [&](){

        int val = 0;

        if(a.size() % 2){
            int ind = a.size()/2;
            int curr = a[ind] + 1;

            for(int i = ind+1; i < a.size(); i++){
                val += abs(a[i] - curr);
                curr++;
            }

            curr = a[ind] - 1;

            for(int i = ind-1; i >= 0; i--){
                val += abs(a[i] - curr);
                curr--;
            }

        }
        else{
            int ind = a.size()/2;
            int curr = a[ind];


            for(int i = ind; i < a.size(); i++){
                val += abs(a[i] - curr);
                curr++;
            }

            curr = a[ind-1];

            for(int i = ind-1; i >= 0; i--){
                val += abs(a[i] - curr);
                curr--;
            }

            int diff = a[ind] - a[ind-1] - 1;

            val += ind*diff;
        }

        return val;
    };


    int ans = calc();
    swap(a,b);
    ans = min(ans, calc());

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