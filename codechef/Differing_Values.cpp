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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt0 = count(all(s),'0');
    int cnt1 = n - cnt0;

    if(k == 1){
        if(abs(cnt0-cnt1) <= 1) cout << "Yes\n";
        else cout << "No\n";
        return;
    }


    set<int> mrk;


    for(int i = 1; (i <= n); i++){
        int j = i;
        if(!mrk.count(j)){
            int cnt = 1;

            mrk.insert(j);
            while((j + k <= n) && (!mrk.count(j+k))){
                cnt++;
                j += k;
                mrk.insert(j);
            }

            if(cnt&1) {
                int le = (cnt)/2;
                int mo = cnt - le;

                if((cnt0 >= le && cnt1 >= mo) || (cnt0 >= mo && cnt1 >= le)){
                    if(cnt0 >= cnt1){
                        cnt0 -= mo;
                        cnt1 -= le;
                    }
                    else{
                        cnt1 -= mo;
                        cnt0 -= le;
                    }
                }
                else{
                    cout << "No\n";
                    return;
                }
            }
            else{
                int eq = cnt/2;
                if((cnt0 >= eq && cnt1 >= eq)){
                    cnt0 -= eq;
                    cnt1 -= eq;
                }
                else{
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes";

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