#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'

void solve(){
    string s,t;
    cin >> s >> t;
    int p = 0;
    map<int,char> mp;
    for(int i = 0; i < s.size(); i++){
        if(t[p] == s[i] || ( p<t.size() and s[i] == '?')){
            if(s[i] == '?'){
                 mp[i] = t[p];
            }
            p++;
        }
    }

    if(p == t.size()){
        cout << "YES" << nl;
        for(auto &[a,b] : mp){
            s[a] = b;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?') s[i] = 'a';
        }

        cout << s << nl;
    }
    else cout << "NO" << nl;

    
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