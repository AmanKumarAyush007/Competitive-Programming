#include<bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'
#define inp(v) for(auto& x : v) cin >> x;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    inp(v);

    stack<int> st;          // will store indices
    int ans = 0;

    for(int i = 0; i < n; i++) {

        // maintain monotonic decreasing stack (values >= current stay)
        while(!st.empty() && v[st.top()] < v[i])
            st.pop();

        int L;
        if(st.empty()) 
            L = -1;
        else 
            L = st.top();

        // contribution of this index
        ans += (i - L) * (n - i);

        st.push(i);
    }

    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}