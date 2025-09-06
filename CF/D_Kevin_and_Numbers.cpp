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
    int n,m;
    cin >> n >> m;

    multiset<int> a;
    vector<int> b(m);

    int sum = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
        sum += x;
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        sum -= b[i];
    }

    if(sum != 0) cout << "No";
    else{

        priority_queue<int> qa(a.begin(), a.end());
        priority_queue<int> qb(b.begin(), b.end());

        while(!qa.empty() && !qb.empty()){
            int x = qa.top();
            int y = qb.top();

            if(x == y){
                qa.pop(); qb.pop();
            } 
            else if(x > y){
                cout << "No\n";
                return;
            } 
            else {
                qb.pop();
                if(y == 1){ 
                    cout << "No\n";
                    return;
                }
                qb.push(y/2);
                qb.push((y+1)/2);
            }
        }

        cout << (qa.empty() && qb.empty() ? "Yes" : "No");
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