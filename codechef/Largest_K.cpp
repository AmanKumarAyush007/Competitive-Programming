#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;

    for(auto &i : a){
        cin >> i;
        mp[i] = 0;
    }
    int dis[n];
    int diff = 0;
    for(int i = 0; i < n; i++){
        if(mp[a[i]] == 0){
            diff++;
            mp[a[i]]++;
        }
        dis[i] = diff; 
    }

    for(auto &i : dis) cout << i << " ";
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}