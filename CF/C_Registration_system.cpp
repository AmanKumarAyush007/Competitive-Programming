#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    map<string, int> mp;
    vector<string> v(t);

    for(auto &i : v) cin >> i;
    for(int i = 0; i < t; i++){
        if(mp[v[i]] == 0) cout << "OK" << nl;
        else{
            cout << v[i] << mp[v[i]] << nl;
        }
        mp[v[i]]++;
    }

    return 0;
}