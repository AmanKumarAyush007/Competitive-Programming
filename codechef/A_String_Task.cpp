#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    vector<char> v;
    for(auto &i : s){
        if(i >= 65 and i<(65+26)) i = i + (97-65);
        if(i != 'a' and i != 'e' and i != 'i' and i != 'o' and i != 'u' and i != 'y') {
            char c = '.';
            v.pb(c);
            v.pb(i);
        }
    }
    for(char &i : v) cout << i;
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