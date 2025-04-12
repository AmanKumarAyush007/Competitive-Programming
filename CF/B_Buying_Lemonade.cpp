#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


void solve(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(auto &i : a) cin >> i;
    
    sort(a,a+n);

    int need = 0;
    int extra = 0;
    int mn = 0;


    for(int i = 0; i < n; i++){

        if(need >= k)  break;
        
        if(a[i] - mn > 0){
            need += (a[i]-mn)*(n-i);
        }
        mn = max(mn,a[i]);
        extra = i;
    }

    int ans = min(k,need) + extra ;

    cout << ans << nl;
}

void viaBinSearch(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(auto &i : a) cin >> i;
    
    sort(a,a+n);

    int mn = 0;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = (a[i]-mn)*(n-i);
        mn = max(mn,a[i]);
    }
    for(int i = 1; i < n; i++){
        v[i] += v[i-1];
    }

    // for(auto &i : v) cout << i << " ";

    auto it = lower_bound(all(v),k);
    int ind = it - v.begin();
    cout << ind+k << nl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        viaBinSearch();
    }
    return 0;
}