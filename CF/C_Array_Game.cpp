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


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)
    sort(all(v));
    set<int> st(all(v));


    if(k >= 3) cout << 0;
    else if(k == 1){
        for(int i = 0; i < n-1; i++){
            st.insert(v[i+1] - v[i]);
        }
        cout << *st.begin();
    }
    else{
        int mn = *min_element(all(v));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int x = v[i] - v[j];
                mn = min(x,mn);
                auto it = lower_bound(all(v),x);
                if(it == v.end()) mn = min(x - v[n-1],mn);
                else {
                    int ind = it - v.begin();
                    if(ind == 0) mn = min(mn,v[0]-x);
                    else mn = min(mn,min(x-v[ind-1],v[ind]-x));
                }
            }
        }
        cout << mn;
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