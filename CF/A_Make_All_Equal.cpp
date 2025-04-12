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

    int mx = INT_MIN;

    for(auto &i : a){
        cin >> i;
        mp[i]++;
    }

    for(auto &[a,b] : mp){
        mx = max(mx,b);
    }
    
    cout << n-mx;

    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}