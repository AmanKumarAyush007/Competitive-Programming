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



void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    for(auto &i : v) i = i%2;

    debug(v);

    int od = 0 , ev = 0;

    for(auto &i : v) {
        if(i&1) od++;
        else ev++;
    }

    if(abs(od - ev) > 1) cout << -1;
    else{
        int ans = inf, curr = 0;
        auto fo = v;
        auto fe = v;

        if(v[0]&1){
            int i = 0, j = 0;
            while(i < n){
                if(i+1 < n){
                    if((fo[i]&1) == (fo[i+1]&1)){
                        while(j < n && ((fo[i]&1) == (fo[j]&1))){
                            j++;
                        }

                        if(j == n) break;
                        
                        swap(fo[i+1],fo[j]);
                        curr += j - i - 1;
                    }
                }
                debug(i,j);
                i++;
                if(j < i) j = i;
                
                debug(i,j);
            }

            bool ck = true;

            for(int i = 0; i < n-1; i++){
                if(fo[i]%2 == fo[i+1]%2) {
                    ck = 0;
                    break;
                }
            }

            debug(fo);

            if(ck) ans = min(curr,ans);

            debug(ans);

            i = 0, j = 0, curr = 0;
            int ind = 0;

            for(int x = 0; x < n; x++){
                if(v[x]%2 == 0){
                    ind = x;
                    break;
                }
            }
            debug(fe);
            swap(fe[0],fe[ind]);

            debug(ind);
            debug(fe);


            curr += ind;

            while(i < n){
                if(i+1 < n){
                    if((fe[i]&1) == (fe[i+1]&1)){
                        while(j < n && (fe[i]&1) == (fe[j]&1)){
                            j++;
                        }

                        if(j == n) break;
                        
                        swap(fe[i+1],fe[j]);
                        curr += j - i - 1;
                    }
                }
                debug(i,j);

                i++;
                if(j < i) j = i;
        
            }

            debug(curr);

            ck = true;

            for(int i = 0; i < n-1; i++){
                if(fe[i]%2 == fe[i+1]%2) {
                    ck = 0;
                    break;
                }
            }

            debug(fe);
            debug(ck);

            if(ck) ans = min(curr,ans);

            debug(ans);
        }
        else{
            int i = 0, j = 0;
            while(i < n){
                if(i+1 < n){
                    if((fe[i]&1) == (fe[i+1]&1)){
                        while(j < n && ((fe[i]&1) == (fe[j]&1))){
                            j++;
                        }

                        if(j == n) break;
                        
                        swap(fe[i+1],fe[j]);
                        curr += j - i - 1;
                    }
                }
                debug(i,j);
                i++;
                if(j < i) j = i;
                
                debug(i,j);
                
            }

            bool ck = true;

            for(int i = 0; i < n-1; i++){
                if(fe[i]%2 == fe[i+1]%2) {
                    ck = 0;
                    break;
                }
            }

            debug(fe);

            if(ck) ans = min(curr,ans);

            debug(ans);

            i = 0, j = 0, curr = 0;
            int ind = 0;

            for(int x = 0; x < n; x++){
                if(v[x]%2){
                    ind = x;
                    break;
                }
            }
            debug(fo);
            swap(fo[0],fo[ind]);

            debug(ind);
            debug(fe);


            curr += ind;



            while(i < n){
                if(i+1 < n){
                    if((fo[i]&1) == (fo[i+1]&1)){
                        while(j < n &&(fo[i]&1) == (fo[j]&1)){
                            j++;
                        }

                        if(j == n) break;
                        
                        swap(fo[i+1],fo[j]);
                        curr += j - i - 1;
                    }
                }
                debug(i,j);

                i++;
                if(j < i) j = i;
        
            }

            debug(curr);

            ck = true;

            for(int i = 0; i < n-1; i++){
                if(fo[i]%2 == fo[i+1]%2) {
                    ck = 0;
                    break;
                }
            }

            debug(fe);
            debug(ck);

            if(ck) ans = min(curr,ans);

            debug(ans);
        }



        cout << ans;
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