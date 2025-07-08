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
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v)

    map<int,int> mp;
    for(auto &i : v) mp[i]++;

    for(auto &[a,b] : mp){
        if(b >= 4){
            cout << "Yes\n";
            return; 
        }
        if(b >= 2){
            int i = a+1;
            while(mp.find(i) != mp.end()){
                if(mp[i] >= 2){
                    cout << "Yes\n";
                    return;
                }
                i++;
            }
        }
    }

    cout << "No" << nl;
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