#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
 
void solve()
{
    int n,m; cin >> n >> m;
    
    map<int,int> mp;

    int a[n];
    for(auto &i : a) cin >> i;

    for(int i = 0; i < n; i++){
        if(i==n-1) {
            mp[i]++;
            break;
        } 

        int val = i + (n-1-i) + (i*(n-1-i));

        mp[val]++;
        if(a[i+1]-a[i] > 1){
            int midRem = (i+1) * (n-1-i);
            mp[midRem] += a[i+1]-a[i] - 1;
        }
    }

    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
        if(mp.find(b) == mp.end()) cout << 0 << " ";
        else cout << mp[b] << " ";
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