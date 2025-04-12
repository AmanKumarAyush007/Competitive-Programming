#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        v.pb(ele);
    }
    
    int g = gcd(a,b);
    int mx = INT_MIN;
    int mn = INT_MAX;
    
    for(auto &i : v){
        i = i%g;
    }

    sort(all(v));

    for(auto &i : v){
        int ele = i + g;
        v.pb(ele);
    }

    for(int i = 0; i <= n; i++){
        mn = min(mn,(v[i+n-1]-v[i]));
    }

    
    cout <<  mn;

    cout << nl;
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