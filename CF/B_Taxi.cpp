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
    int ans = 0;
    map<int,int> mp;
    for(auto &i : a){
        cin >> i;
        if(i == 4) ans++;
        else mp[i]++;
    }
    ans += mp[3] +(mp[2]*2 + max(0,(mp[1]-mp[3])) + 3)/4;
    
    cout << ans <<nl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}