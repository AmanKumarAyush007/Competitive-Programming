#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    int a[n];
    inp(a);
    for(int i = 0; i < n; i++){
        if(i&1) a[i] *= -1;
    }
    vector<int> v(n);
    v[0] = a[0];
    for(int i = 1; i < n; i++){
        v[i] = v[i-1] + a[i] ;
    }
    set<int> st;

    for(auto &i : v){
        if(i == 0) {
            cout << "YES" << nl;
            return;
        }
        if(st.find(i) != st.end()){
            cout << "YES" << nl;
            return;
        }
        else{
            st.insert(i);
        }
    }
    cout << "NO" << nl;
    st.clear();

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