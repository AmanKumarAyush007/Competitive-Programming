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
    string s;
    cin >> s;
    set<int> st;

    for(int i = 0; i < n; i++){
        if(s[i] == '0') st.insert(i+1);
    }

    int ans = 0;

    // for(auto &i : st) cout << i << " ";

    int i = 1;
    
    while(!st.empty()){
        int j = 1;
        while(st.find(i*j) != st.end()){
            ans += i;
            st.erase(i*j);
            j++;
        }
        i++;
    }
    
    cout << ans << nl;
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