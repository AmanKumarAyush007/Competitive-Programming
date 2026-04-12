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

const int mxN = 1e5 + 5;

vector<set<int>> divisors(mxN);

void precompute(){
    for(int i = 1; i*i < mxN; i++){
        for(int j = i; j < mxN; j += i){
            // assert(j < mxN);

            divisors[j].insert(i);

            if(i != j/i) divisors[j].insert(j/i);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    inp(v);

    set<int> st;

    int ans = 0;

    for(auto &i : v){

        if(divisors[m].count(i)){
            if(!st.empty()){
                vector<int> temp;
                for(auto &j : st){
                    if(j > m/i) {
                        temp.pb(i);
                        continue;
                    }

                    int val = j * i;
                    if(m % val != 0) continue;

                    temp.pb(val);
                }

                for(auto &j : temp) st.insert(j);
            }

            st.insert(i);

            if(st.count(m)){
                ans++;
                st.clear();
                st.insert(i);
            }
        }
    }

    if(ans == 0 || st.size()) ans++;

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}