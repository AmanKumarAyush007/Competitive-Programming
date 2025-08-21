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

// int tot(vector<int> & v){
//     int ans = 0;
//     for(int i = 0; i < 4; i++){
//         int mn = v[i];
//         for(int j = i; j < 4; j++){
//             mn = min(v[j],mn);
//             ans += mn;
//         }

//     }
//     return ans;
// }

void solve(int n){
    
    vector<int> v(n);
    iota(all(v),1);
    debug(v);

    auto tot = [&](){
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mn = v[i];
            for(int j = i; j < n; j++){
                mn = min(v[j],mn);
                ans += mn;
            }

        }
        return ans;
    };

    int net = 0;

    for(int i = 1; i <= n; i++){
        net += i * (n-i + 1);
    }

    int cnt = 1;

    do {
        
        if(tot() == net){
            cout << cnt << "    ";
            cnt++;
            for (auto i : v)  std::cout << i << " ";

            cout << " " << tot();
            std::cout << std::endl;
        }
            
    } while (std::next_permutation(v.begin(), v.end()));
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 7;
    while(t--){
        solve(t);
    }
    return 0;
}