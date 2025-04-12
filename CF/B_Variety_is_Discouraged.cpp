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
    vector<int> v(n);
    inp(v);    
    map<int,int> mp;
    for(auto &i : v) mp[i]++;

    int l = -1, r = -1;

    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && mp[v[j]] == 1){
            j++;
        }

        if((i != j)) j--;

        if(mp[v[i]] == 1 && (j-i >= r - l)){
            l = i;
            r = j;
        }  

        if(i != j) {
            i = j;
        }
    }   

    if(l == -1 && r == -1) cout << 0;
    else cout << l+1 << " " << r+1;
                
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