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
    vector<int> v(n);
    inp(v);

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(v[i]%2 == 0) cnt++;
    }

    if(cnt >= 2){
        int rem = 2;
        for(auto &i : v){
            if(rem == 0) break;
            if(i%2 == 0){
                cout << i << " ";
                rem--;
            }
        }
        cout << nl;
    }
    else{
        if(cnt == 1){
            int ind = 0;
            int y = -1;
            for(int i = 0; i < n; i++){
                if(v[i] % 2 == 0){
                    ind = i;
                    y = v[i];
                }
            }

            for(int i = 0; i < ind; i++){
                if((y % v[i]) % 2 == 0){
                    cout << v[i] << " " << y << nl;
                    return;
                }
            }
        }

        for(int i = 0; i < n-1; i++){
            if(v[i] % 2 == 0) continue;
            int next = i+1;
            if(next < n && v[next] % 2 == 0) next++;

            if(next < n){
                if(v[next] < v[i]*2){
                    cout << v[i] << " " << v[next] << nl;
                    return; 
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((v[j] % v[i]) % 2 == 0 ){
                    cout << v[i] << " " << v[j] << nl;
                    return;
                }
            }
        }

        cout << -1 << nl;
    }

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