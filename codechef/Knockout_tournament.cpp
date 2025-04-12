#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    vector<int> a(16);
    for(auto &i : a) cin >> i;
    vector<int> b(all(a)); 
    sort(all(b));
    map<int,int> mp;
    for(int i = 0; i < 16; i++){
        mp[b[i]] = log2(i+1);
    }
    for(auto &i : a) cout << mp[i] << " ";
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