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
    int f[n],b[n];
    set<char> st;
    for(int i = 0; i < n; i++){
        st.insert(s[i]);
        f[i] = st.size();
    }
    st.clear();
    for(int i = n-1; i >= 0; i--){
        st.insert(s[i]);
        b[i] = st.size();
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int temp = min(n,(f[i]+b[i+1]));
        ans = max(ans,temp);
    }
    cout << max(ans,(f[n-2]+b[n-1])) << nl;
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