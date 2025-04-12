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
    string s;
    cin >> s;
    map<char,int> mp;
    for(auto &i : s) mp[i]++;
    
    vector<pair<int,char>> vp;

    for(auto &[a,b] : mp) vp.pb({b,a});

    sort(all(vp),greater<pair<int,char>>());

    // for(auto &[a,b] : vp){
    //     cout << a << " " << b << nl;
    // }

    // string ans; 

    int x = vp.size();
    
    if(x == 1) cout << s;
    else{
        for(int i = 0; i < x; i++){
            if(vp[i].ff >= 1){
                cout << vp[i].ss;
                vp[i].ff -= 1; 
                if(vp[i].ff <= 0 && i == x-1) x--;
            }
            else x--;

            if(i >= x-1) i = -1;
        }
        for(int i = 0; i < vp.size(); i++){
            while(vp[i].ff--){
                cout << vp[i].ss;
            }
        }
    }


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