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

vector<int> digcnt;
vector<int> digsm;

void compute(){
    digcnt.pb(0);
    for(int i = 1; i < 20; i++){
        int cnt = 9*i*pow(10,i-1);
        digcnt.pb(digcnt.back()+cnt);
        if(digcnt.back() > 1e15) break;
    }

    digsm.pb(0);
    for(int i = 1; i < digcnt.size(); i++){
        int curr = 45*pow(10,i-1);
        digsm.pb((digsm.back()*10) + curr);
    }
}

int rec(int x){
    if(x <= 9) return (x*(x+1)/2);

    int dg = log10(x);

    int fst = x/(pow(10,dg));

    int ex = x%((int)pow(10,dg));

    return (fst*(digsm[dg])) + (((fst*(fst-1))/2)*(pow(10,dg))) + (fst*(ex+1)) + rec(ex);
}

void solve(){
    int n;
    cin >> n;

    auto check = [&](int x){
        int cnt = log10(x);
        int tot = digcnt[cnt];
        int ex = x - pow(10,cnt) + 1;
        tot += (cnt+1)*ex;

        return tot;
    };


    int hi = 1e15, lo = 0;
    int num = 0;
    while(hi >= lo){
        int mid = (lo + hi)/2;
        if(check(mid) >= n){
            num = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    } 

    int req = n - check(num-1);

    int ans = rec(num-1);

    string s = to_string(num);

    for(auto &i : s){
        if(req == 0) break;
        ans += (i-'0');
        req--;
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    compute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}