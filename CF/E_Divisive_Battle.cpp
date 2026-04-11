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

const int N = 1e6+5;

vector<vector<int>> factor(N);
vector<int> spf(N);

void precompute(){
    for (int i = 1; i < N; i++) spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {  
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        int x = i;
        while (x > 1) {
            int p = spf[x];
            factor[i].push_back(p);

            while (x % p == 0) x /= p;

        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    if(is_sorted(all(v))) cout << "Bob";
    else{
        set<int> st;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(v[i] == 1) {
                st.insert(1);
                temp.pb(1);
            }
            else {
                st.insert(factor[v[i]].size());
                temp.pb(factor[v[i]][0]);
            }
        }

        if((st.size() == 1) && (*st.begin() == 1) && (is_sorted(all(temp)))) cout << "Bob";
        else cout << "Alice";
    }
    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}