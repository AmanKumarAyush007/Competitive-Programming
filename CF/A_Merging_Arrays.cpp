#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for(auto &i : a)cin >>i;
    for(auto &i : b)cin >>i;

    vector<int> v;
    int i = 0;
    int j = 0;

    while(i!=n && j!= m){
        if(a[i]<=b[j]){
            v.pb(a[i]);
            i++;
        }
        else{
            v.pb(b[j]);
            j++;
        }
    }
    if(i==n){
        while(j!=m) {
            v.pb(b[j]);
            j++;
        }
    }
    else if (j==m){
        while(i!=n) {
            v.pb(a[i]);
            i++;
        }
    }

    for(auto &i : v) cout << i << " ";
    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}