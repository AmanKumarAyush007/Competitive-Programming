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
    int n,k;
    cin >> n >> k;
    int a[n], b[n];
    inp(a)
    inp(b)

    set<int> st;
    for(auto &i : b) st.insert(i);

    int mn = *min_element(a,a+n);
    int mx = *max_element(a,a+n);

    // for(auto &i : st) cout << i << " ";
    // cout << st.size() << nl;
    
    if(st.size() == 1 && *st.begin() == -1){
        int up = mn + k;
        int lo = mx;
        // cout << "000";

        cout << up - lo + 1;
    }
    else {
        set<int> st;

        for(int i = 0; i < n; i++){
            if(b[i] != -1) st.insert(a[i]+b[i]);
        }
        if(st.size() > 1) cout << 0;
        else{
            int j = *st.begin();
            mn = inf;
            mx = hell;
            for(int i = 0; i < n; i++){
                if(b[i] == -1) {
                    mx = max(a[i],mx);
                    mn = min(a[i],mn);
                }
            }
            int lo = j - mx;
            int hi = j - mn;
            if(hi <= k && lo >= 0) cout << 1;
            else cout << 0;
        }
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