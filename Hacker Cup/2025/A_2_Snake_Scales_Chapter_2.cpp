#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
     for(int i=0;i<n;i++){
      cin>>a[i];
     }
     int ans;
 
     if(n==1){
         ans=a[0];
         cout << ans << nl;
         return;
     }
 
 
     int mini=0;
 
     for(int i=1;i<n;i++){
         int lm=0;
         int tr=a[i];
         for(int j=i-1;j>=0;j--){
             lm=max(lm,abs(a[j]-a[j+1]));
             tr=min(tr,max(lm,a[j]));
         }
         lm=0;
 
         for(int j=i+1;j<n;j++){
             lm=max(lm,abs(a[j]-a[j-1]));
             tr=min(tr,max(lm,a[j]));
         }
         mini=max(mini,tr);
     }
 
    ans=mini;

    cout << ans << nl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("snake_scales_chapter_2_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}


 

