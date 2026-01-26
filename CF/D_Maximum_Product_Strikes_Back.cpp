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

    int ansl = n, ansr = 0;

    auto pro = [&](int st, int en){
        int res = 0;
        int neg = 0;

        for(int i = st; i <= en; i++){
            if(abs(v[i]) == 2) res++;
            if(v[i] < 0) neg++;
        }

        ansl = st;
        ansr = n - (en + 1);


        if(neg % 2){
            int i = st;
            int curr = res;
            int curr1 = res;
            while(i <= en){
                if(abs(v[i]) == 2) curr--;
                if(v[i] < 0) break;
                i++;
            }
            

            int j = en;
            while(j >= st){
                if(abs(v[j]) == 2) curr1--;
                if(v[j] < 0) break;
                j--;
            }



            if(curr >= curr1){
                ansl += i - st + 1;
            }
            else ansr += en - j + 1;

            res = max(curr1,curr);
        }

        return res;
    };

    int ans = 0;

    int i = 0, j = 0;
    int st = 0, en = 0;

    while(i < n){
        while(j < n && v[j] != 0){
            j++;
        }

        if(i == j){
            i++, j++;
            continue;
        }

        int curr = pro(i, j - 1);

        if(curr > ans){
            st = i, en = j - 1;
            ans = curr;
        }

        if(v[j] == 0) j++;
        i = j;
    }

    if(ans > 0) ans = pro(st, en);

    cout << ansl << " " << ansr << nl;
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