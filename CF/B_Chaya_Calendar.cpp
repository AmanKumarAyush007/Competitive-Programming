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
    int a[n];
    inp(a);
    vector<int>v(n);
    v[0] = a[0];
    set<int> st;
    st.insert(a[0]);
    for(int i = 1; i < n; i++){
        int ele = v[i-1];
        ele = ((ele/a[i]) + 1)*a[i];
        int temp = a[i];
        if(st.find(ele) == st.end() && (ele > v[i-1])){
            st.insert(ele);
            v[i] = ele;
        }
        ele += temp;
    }
    cout << v[n-1] << nl;
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