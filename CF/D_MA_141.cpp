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

using pi = pair<int,int>;

void solve(){

    vector<pi> side(4);
    auto dis = [&](pi &a, pi &b){
        return ((a.ff-b.ff) * (a.ff-b.ff)) + ((a.ss-b.ss) * (a.ss-b.ss));
    };

    auto slope = [&](pi &a, pi &b, pi &c, pi &d){
        return (((c.ss-a.ss) * (b.ss - d.ss)) == ((c.ff-a.ff) * (b.ff - d.ff))* -1);
    };


    for(int i = 0; i < 4; i++){
        cin >> side[i].ff >> side[i].ss;
    }

    set<int> st;

    for(int i = 0; i < 4; i++){
        int j = (i+1) % 4;
        st.insert(dis(side[i],side[j]));
    }


    if(st.size() == 1 && *st.begin() != 0 && slope(side[0],side[1],side[2],side[3]) && (dis(side[0],side[2]) == dis(side[1],side[3])) && (dis(side[0],side[2]) == (2 * (*st.begin())))) cout << "SIM";
    else cout << "NAO";

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}