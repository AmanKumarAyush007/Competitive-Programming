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

    int ans = -1;
    int lo = 0;
    int hi = n;

    auto check = [&](int x){
        {    
            string t;
            for(int i = 0; i < x; i++){
                if(i&1) t += '0';
                else t += '1';
            }

            {    
                int del = 0;
                int turn = 0;
                bool can = 1;
                int j = 0;

                for(int i = 0; i < n; i++){
                    if(j == x) break;
                    if(s[i] == t[j]) j++;
                    else if(turn == (s[i] - '0')){
                        del++;
                        turn ^= 1;
                        j++;
                    }
                    else {
                        can = 0;
                        break;
                    }
                }

                if(can && del <= x) {
                    cout << 155 << nl;
                    return true;
                }
            }
            // {    
            //     int del = 0;
            //     int turn = 1;
            //     bool can = 1;
            //     int j = 0;

            //     for(int i = 0; i < n; i++){
            //         if(j == x) break;
            //         if(s[i] == t[j]) j++;
            //         else if(turn == (s[i] - '0')){
            //             del++;
            //             turn ^= 1;
            //             j++;
            //         }
            //         else {
            //             can = 0;
            //             break;
            //         }
            //     }

            //     if(can && del <= x) {
            //         cout << 2 << nl;
            //         return true;
            //     }
            // }
        }



        // {    
        //     string t;
        //     for(int i = 0; i < x; i++){
        //         if(i&1) t += '1';
        //         else t += '0';
        //     }

        //     {    
        //         int del = 0;
        //         int turn = 0;
        //         bool can = 1;
        //         int j = 0;

        //         for(int i = 0; i < n; i++){
        //             if(j == x) break;
        //             if(s[i] == t[j]) j++;
        //             else if(turn == (s[i] - '0')){
        //                 del++;
        //                 turn ^= 1;
        //                 j++;
        //             }
        //             else {
        //                 can = 0;
        //                 break;
        //             }
        //         }

        //         if(can && del <= x) {
        //             cout << 3 << nl;
        //             return true;
        //         }
        //     }
        //     {    
        //         int del = 0;
        //         int turn = 1;
        //         bool can = 1;
        //         int j = 0;

        //         for(int i = 0; i < n; i++){
        //             if(j == x) break;
        //             if(s[i] == t[j]) j++;
        //             else if(turn == (s[i] - '0')){
        //                 del++;
        //                 turn ^= 1;
        //                 j++;
        //             }
        //             else {
        //                 can = 0;
        //                 break;
        //             }
        //         }

        //         if(can && del <= x) {
        //             cout << 4 << nl;
        //             return true;
        //         }
        //     }
        // }

        return false;
    };

    for(int i = 0; i <= n; i++){
        debug(check(i));
    }
    return;


    while(lo <= hi){
        int mid = (lo+hi)/2;

        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

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