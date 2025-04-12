#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;

    int ans = *max_element(all(v)) - *min_element(all(v));

    vector<int> pre(n);
    pre[0] = v[0];

    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + v[i];
    }

    for(int i = 2; i <= n; i++){
        set<int> st;
        if(n%i == 0){
            for(int j = i-1; j < n; j += i){
                int ele = 0;
                if(j == i-1) ele = pre[j];
                else ele = pre[j] - pre[j-i];
                st.insert(ele);             
            }
            int mn = *st.begin();
            int mx = *prev(st.end());
            int curr = mx - mn;
            ans = max(curr,ans);
        }
    }
    cout<< ans << nl;
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