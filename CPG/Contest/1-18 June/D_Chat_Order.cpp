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
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    map<string,int> mp;
    for(int i = 0; i < n; i++){
        mp[v[i]] = i;
    }
    set<pair<int,string>> s;
    for(auto &i : v){
        s.insert(make_pair(mp[i],i));
    } 
    vector<pair<int,string>> vmp(all(s));

    
    sort(all(vmp),greater<pair<int,string>>());
   
    for(auto [a,b] : vmp){
        cout<<b<<nl;
    }

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