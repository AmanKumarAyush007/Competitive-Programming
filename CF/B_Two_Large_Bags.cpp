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
    map<int,int> mp;
    while(n--){
        int ele;
        cin >> ele;
        mp[ele]++;
    }
    for(auto &[a,b] : mp){
        cout << a << " " << b << nl;
        if(b > 2) {
            mp[a+1] += b - 2;
        }
        if(b == 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes" << nl;
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