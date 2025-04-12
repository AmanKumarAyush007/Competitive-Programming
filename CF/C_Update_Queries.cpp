#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin >> n >> m;
    
    string s;
    cin >> s;

    set<int> st;
    int a[m];
    for(int &i : a) {
        cin >> i;
        st.insert(i);
    }

    vector<int> uni(all(st));

    string c;
    cin >> c;

    sort(all(c));

    for(int i = 0; i < uni.size(); i++){
        s[uni[i]-1] = c[i];
    }

    cout<<s<<nl;

    
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