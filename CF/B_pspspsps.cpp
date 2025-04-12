#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string st = s;
    st.erase(remove(all(st),'.'),st.end());
    if(st.size() < 2) cout << "YES";
    else if(st.find("ps") != string::npos) cout << "NO";
    else {
        bool ck = true;
        if(s[0] != 's' || s[n-1] != 'p') ck = false;
        



    }
    cout << nl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}