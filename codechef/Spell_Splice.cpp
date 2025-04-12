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
    vector<pair<int,int>> pr;
    while(n--){
        int x,y;
        cin>>x>>y;
        pr.pb(make_pair(x,y));
    }
    int ans = INT_MIN;
    for(int i = 0; i < pr.size(); i++){
        for(int j = i+1; j < pr.size(); j++){
            int sum = (pr[i].ff) * (pr[j].ss) + (pr[i].ss) * (pr[j].ff);
            ans = max(sum,ans);
        }
    }
    cout<<ans<<endl;
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