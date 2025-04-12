#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i = 0; i < n-1; i++){
        int g = __gcd(a[i],a[i+1]);
        cout<<g<<" ";
        v.pb(g);
    }
    cout<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

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