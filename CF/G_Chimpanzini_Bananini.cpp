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

void solve(){
    int n;
    cin >> n;

    deque<int> dq, dqr;
    int rizz= 0,rizzy = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        if(s == 3) {
            int k;
            cin >> k;

            dq.push_back(k);
            dqr.push_front(k);

            rizzy += sum + k;
            rizz += (dq.size() * k);

            sum += k;

        }
        else if(s == 1){
            rizz -= dq.back() * dq.size();
            rizz += sum;
            
            rizzy -= sum;
            rizzy += dqr.front() * dqr.size();

            int x = dq.back();
            dq.pop_back();
            dq.push_front(x);

            x = dqr.front();
            dqr.pop_front();
            dqr.push_back(x);

        }
        else{
            swap(dq,dqr);
            swap(rizz,rizzy);
        }

        cout << rizz << nl;
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