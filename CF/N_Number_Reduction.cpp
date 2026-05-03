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
#define lg(x)            (63 - __\builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    string s;
    cin >> s;
    
    int k;
    cin >> k;

    int req = k;

    int n = s.size();

    stack<char> st;

    for(auto &i : s){
        if(st.size()){

            if(i == '0'){
                while(st.size() > 1 && k > 0){
                    st.pop();           
                    k--;
                }
            } 
            else{
                while(st.size() && st.top() > i && k > 0){
                    st.pop();
                    k--;
                }
            }
            
            st.push(i);
        }   
        else st.push(i);
    }


    string sol;

    while(st.size()){
        sol = st.top() + sol;
        st.pop();
    }

    while(k--) sol.pop_back();

    cout << sol << nl;
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