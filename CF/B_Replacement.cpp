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
    string s,t;
    cin >> s >> t;
    int z = count(all(s),'0');
    int o = count(all(s),'1');
    for(int i = 0; i < n-1; i++){
        if(z == 0 || o == 0) {
            cout << "NO\n";
            return;
        }
        if(t[i] == '0') o--;
        else z--;
    }

    cout << "YES" << nl;
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