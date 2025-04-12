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
    unordered_set<char> st;
    for(auto &i : s) st.insert(tolower(i));
    if(st.size() == 26) cout << "YES" << nl;
    else cout << "NO" << nl;
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