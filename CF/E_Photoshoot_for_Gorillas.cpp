#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

ll range(int i,int j,int k,int n,int m){
    int x_min = max(0LL,(j-k+1));
    int x_max = min(j,m-k);
    int x_range = x_max - x_min + 1;


    int y_min = max(0LL,(i-k+1));
    int y_max = min(i,n-k);
    int y_range = y_max - y_min + 1;

    return (x_range * y_range);    
}

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    int w; cin >> w;

    int a[w];

    for(auto &i : a) cin >> i;

    sort(a,a+w,greater<int>());


    vector<int> v;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v.pb(range(i,j,k,n,m)) ;
        }
    }


    sort(all(v),greater<int>());

    int ans = 0;

    for(int i = 0; i < w; i++){
        ans += v[i]*a[i];
    }


    cout << ans;

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