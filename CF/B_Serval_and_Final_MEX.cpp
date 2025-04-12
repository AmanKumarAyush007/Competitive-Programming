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
#define inp(v)     for(auto& x : v) cin >> x
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);
    map<int,int> mp;

    int fst = -1, lst = -1;

    for(int i = 0; i < n; i++){
        mp[v[i]]++;
        if(v[i] == 0 && fst == -1) fst = i+1;
        if(v[i] == 0) lst = i+1;
    }


    if(mp[0] == 0){
        cout << 1 << nl << 1 << " " << n;
    }
    else if(mp[0] == 1){
        if(v[0] != 0){
            cout << 2 << nl;
            cout << 2 << " " << n << nl;
            cout << 1 << " " << 2;
        }
        else {
            cout << 2 << nl;
            cout << 1 << " " << n-1 << nl;
            cout << 1 << " " << 2;
        }
    }
    else {
        if(fst == 1 && lst == n){
            cout << 3 << nl;
            cout << 1 << " " << 2 << nl;
            cout << 2 << " " << n-1 << nl;
            cout << 1 << " " << 2;
        }
        else if(fst != 1){
            cout << 2 << nl;
            cout << 2 << " " << n << nl;
            cout << 1 << " " << 2;
        }
        else if(lst != n){
            cout << 2 << nl;
            cout << 1 << " " << n-1 << nl;
            cout << 1 << " " << 2;    
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