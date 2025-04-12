#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> s1;
    vector<int> s2;

    for(int i = min(a,b); i<=max(a,b); i++){
        s1.pb(i);
    }
    for(int i = 1; i<=12; i++){
        auto it = find(s1.begin(),s1.end(),i);
        if(it==s1.end()) s2.pb(i);
    }
   
    auto x = find(s1.begin(),s1.end(),c);
    auto y = find(s1.begin(),s1.end(),d);

    if(((x==s1.end()) && (y==s1.end())) || ((x!=s1.end()) && (y!=s1.end()))) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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