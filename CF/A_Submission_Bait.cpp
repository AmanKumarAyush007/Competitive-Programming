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
    cin  >>  n;
    int a[n];
    int mx = 0;
    set<int> s;
    map<int,int> mp;
    for(auto &i : a){
        cin >> i;
        s.insert(i);
        mp[i]++;
    }
    vector<int> v(all(s));
    for(int i = 0; i < v.size(); i++){
        if(mp[v[i]]%2 == 0) v[i] = 1;
        else v[i] = -1;
    }
    bool check = false;
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i] == -1) {
            check = true;
            break;
        }
    }
    if(check) cout << "YES" << nl;
    else cout << "NO" << nl;
    

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