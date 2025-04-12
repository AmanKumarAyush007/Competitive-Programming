#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n, m , q;
    cin >> n >> m >> q;
    vector<int> t,d;
    for(int i = 0; i < m; i++){
        int ele ;
        cin >> ele;
        t.pb(ele);
    }
    sort(all(t));
    for(int i = 0; i < q; i++){
        int ele ;
        cin >> ele;
        d.pb(ele);
    }
    // for(auto &i : t) cout << i << " ";
    // cout << nl;
    for(int i = 0; i < q; i++){
        auto it = lower_bound(all(t),d[i]);
        if(it == t.end()) cout <<  n - t[m-1]  ;
        // else cout << it - t.begin() << "!";
        else if((it-t.begin()) == 0) cout << t[0] - 1;
        else cout << (t[it-t.begin()] - t[(it-t.begin())-1])/2;
        cout << nl;
    }
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