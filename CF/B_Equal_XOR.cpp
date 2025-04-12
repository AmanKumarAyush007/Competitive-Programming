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
    int n ,k;
    cin >> n >> k;
    int a[2*n];
    for(auto &i : a) cin >> i;
    map<int,int> mpl, mpr;
    for(int i = 0; i < n; i++){
        mpl[a[i]]++;
    }
    for(int i = n; i < 2*n; i++){
        mpr[a[i]]++;
    }
    bool uni = true , same = true;
    for(auto &[a,b] : mpl){
        if(b == 2){
            uni = false;
            break;
        }
    }
    for(auto &[a,b] : mpl){
        if(b == 1){
            same = false;
            break;
        }
    }
    vector<int> l,r;
    if(uni){
        for(int i = 0; i < 2*k; i++){
            l.pb(a[i]);
            r.pb(a[i]);
        }
    }
    else if(same){
        for(auto &[a,b] : mpl){
            if(l.size() >= 2*k) break;
            if(b == 2){
                l.pb(a);
                l.pb(a);
            }
        }
        for(auto &[a,b] : mpr){
            if(r.size() >= 2*k) break;
            if(b == 2){
                r.pb(a);
                r.pb(a);
            }
        }
    }
    else{
        int i = 0;
        while(i < n && (l.size() < 2*k)){
            if(mpl[a[i]] == 2) {
                l.pb(a[i]);
                l.pb(a[i]);
                mpl[a[i]] = 0;
            }
            i++;
        }
        i = n;
        while(i < 2*n && (r.size() < 2*k)){
            if(mpr[a[i]] == 2) {
                r.pb(a[i]);
                r.pb(a[i]);
                mpr[a[i]] = 0;
            }
            i++;
        }

        for(auto &[a,b] : mpl){
            if(l.size() >= 2*k) break;
            if(b == 1){
                l.pb(a);
                r.pb(a);
            }
        }
        
    }
    for(auto &i : l) cout << i << " ";
    cout << nl;
    for(auto &i : r) cout << i << " ";
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