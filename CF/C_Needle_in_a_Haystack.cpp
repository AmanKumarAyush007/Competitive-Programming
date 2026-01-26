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
    string s;
    cin >> s;
    string t;
    cin >> t;
    map<char, int, greater<char>> mps,mpt;
    for(auto &i : s) mps[i]++;
    for(auto &i : t) mpt[i]++;

    for(auto &[x,y] : mps){
        if(mpt[x] < y){
            cout << "Impossible\n";
            return;
        }
        mpt[x] -= mps[x];
        if(mpt[x] == 0) mpt.erase(x);
    }

    map<char, int> fstind,toadd;

    for(int i = 0; i < s.size(); i++){
        if(!fstind.count(s[i])) fstind[s[i]] = i;
    }

    
    int sz = s.size();
    
    
    for(auto &[x,y] : mpt) {
        auto it = fstind.upper_bound(x);
        if(it == fstind.end()){
            toadd[x] = sz;
            if(!fstind.count(x)) fstind[x] = sz;
            else  fstind[x] = min(sz,fstind[x]);
        }
        else{
            auto temp = it;
            auto [p,q] = *it;
            while(temp != fstind.end()){
                auto [pp,qq] = *temp;
                if(qq < q) {
                    q = qq;
                    it = temp;
                }
                temp = next(temp);
            }

            auto [c,in] = *it;
            for(auto &[a,b] : toadd){
                if(b >= in) toadd[a] += y;
            }
            toadd[x] = in;
            for(auto &[a,b] : fstind){
                if(b >= in) fstind[a] += y;
            }
            if(!fstind.count(x)) fstind[x] = in;
            else  fstind[x] = min(in,fstind[x]);
        }
        sz += y;
        
    }

    string ans;

    map<int,char> chacha;

    for(auto &[x,y] : toadd) chacha[y] = x;
    int j = 0;


    for(int i = 0; i < t.size();){
        if(chacha.count(i)){
            int req = mpt[chacha[i]];
            char bac = chacha[i];
            chacha.erase(i);
            while(req--){
                i++;
                ans += bac;
            }
        }
        else{
            ans += s[j];
            j++;
            i++;
        }
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