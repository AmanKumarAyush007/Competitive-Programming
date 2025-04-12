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
    vector<int> a(n);
    inp(a);

    vector<int> b = a;
    sort(all(b));

    int pre[n];
    pre[0] = b[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + b[i];
    }

    set<int> gr;

    for(int i = 0; i < n-1; i++){
        if(pre[i] < b[i+1]) gr.insert(i);
    }
    // gr.insert(n);

    map<int,int> mp;
    mp[b[n-1]] = n-1;
    
    for(int i = 0; i < n-1; i++){
        auto it = gr.lower_bound(i);
        if(it == gr.end()) {
            mp[b[i]] = n-1;
        }
        else mp[b[i]] = *it;
    }

    for(int i = 0; i < n; i++){
        cout << mp[a[i]] << " ";
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