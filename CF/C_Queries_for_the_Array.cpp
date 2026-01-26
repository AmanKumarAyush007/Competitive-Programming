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
    
    stack<int> st;

    for(auto &i : s){
        if(st.size() < 2 && i == '0'){
            cout << "NO\n";
            return;
        }
        if(i == '+'){
            if(st.size() == 0) st.push(1);
            else if(st.top() == 0) st.push(0);
            else st.push(-1);
        }
        else if(i == '-'){
            if(st.size() == 0) continue;
            int to = st.top();
            st.pop();
            if(to == 1 && st.size() && st.top() == -1){
                st.pop();
                st.push(1);
            }
        }
        else {
            if(i == '0' && st.size() && st.top() == 1){
                cout << "NO\n";
                return;
            }
            else if(i =='1' && st.size() && st.top() == 0){
                cout << "NO\n";
                return;
            }

            if(st.size() && st.top() == -1){
                st.pop();
                st.push(i - '0');
            }
        }
    }

    cout << "YES\n";

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