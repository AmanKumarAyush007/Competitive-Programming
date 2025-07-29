#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    deque<int> dq(all(v));
    string s;

    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            // min

            if(dq.front() > dq.back()) {
                dq.pop_back();
                s += 'R';
            }
            else{
                dq.pop_front();
                s += 'L';
            }
        }
        else{
            if(dq.front() < dq.back()) {
                dq.pop_back();
                s += 'R';
            }
            else{
                dq.pop_front();
                s += 'L';
            }
        }
    }
    cout << s << nl;
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