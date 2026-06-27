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

int n;
string a;
vector<int> D;
bool visL[20][2][2];
int dpL[20][2][2];
bool visG[20][2];
int dpG[20][2];
int p10[20];

int recL(int pos, bool lz, bool tight){
    if(pos == a.size()) return (lz ? -1 : 0);

    if(visL[pos][lz][tight]) return dpL[pos][lz][tight];

    int res = -1;

    int lim = (tight ? a[pos]-'0' : 9);

    if(lz) res = max(res, recL(pos+1, 1, 0));

    for(auto x : D){
        if(x > lim) break;

        if(lz && x == 0 && pos < a.size()-1) continue;

        int nxt = recL(pos+1, 0,tight && (x == lim));

        if(nxt != -1) res = max(res, x * p10[a.size() - (pos+1)] + nxt);
    }

    visL[pos][lz][tight] = 1;
    return dpL[pos][lz][tight] = res;
}

int recG(int p, int t){
    if(p == a.size()) return 0;

    if(visG[p][t]) return dpG[p][t];

    int res = inf;

    int lim = t ? a[p] - '0' : 0;

    for(auto x : D){
        if(x < lim) continue;

        int nxt = recG(p+1, t && (x == lim));

        if(nxt != inf) res = min(res, x * p10[a.size() - (p+1)] + nxt);
    }

    visG[p][t] = 1;
    return dpG[p][t] = res;
}

void solve(){
    cin >> a >> n;
    D.resize(n);
    
    inp(D);

    memset(visG, 0, sizeof(visG));
    memset(visL, 0, sizeof(visL));

    int bl = recL(0,1,1);
    int bg = recG(0, 1);


    if(bg == inf){
        int fd = -1;
        for(auto x : D) if(x > 0) {
            fd = x;
            break;
        }

        if(fd != -1) bg = fd;

        for(int i = 0; i < (int)a.size(); i++){
            if(bg > inf/10) break;
            bg = bg*10 + D[0];
        }    
    }


    int ans = inf;

    int A = stoll(a);

    if(bl != -1) ans = min(ans, A - bl);
    if(bg != inf) ans = min(ans, bg - A);

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p10[0] = 1;
    for(int i = 1; i < 19; i++){
        p10[i] = 10 * p10[i-1];
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}