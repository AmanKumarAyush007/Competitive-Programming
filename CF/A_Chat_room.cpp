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
    string h = "hello";
    int j = 0;
    for(auto &i : s){
        if(i == h[j]) j++;
    }
    if(j == 5) cout << "YES" << nl;
    else  cout << "NO" << nl;
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