#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,x;
    cin >> n >> x;
    map<string,string> mp;
    while (x--)
    {
        string s,s1;
        cin >> s >> s1;
        if(s.size() > s1.size()) mp[s] = s1,mp[s1] = s1;
        else mp[s] = s,mp[s1] = s;
    }
    vector<string> v(n);
    for(auto &i : v) cin >> i;
    for(auto &i : v) cout << mp[i] << " ";

    cout << nl;
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