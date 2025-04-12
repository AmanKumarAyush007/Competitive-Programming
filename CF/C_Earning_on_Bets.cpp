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
    cin>>n;
    int a[n];
    int Lcm = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        Lcm = lcm(Lcm,a[i]);
    }
    // cout<<Lcm<<nl;
    vector<int> v;
    int sum = 0;
    for(int i = 0; i < n; i++){
       int ele = Lcm/a[i];
       v.pb(ele);
       sum += ele;
    }
    if(sum < Lcm){
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<nl;
    }
    else cout<<-1<<nl;
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