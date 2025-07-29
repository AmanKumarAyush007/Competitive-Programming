#include<bits/stdc++.h>
using namespace std;


#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)
#define lg(x)      (63 - __builtin_clzll(x)) //log base 2


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    inp(v)

    vector<int> seen(n, 0);
    auto check = [&](int mid){
    	if(mid == 0) return true;
    		
    	for(int i = 0; i < mid; i++){
    		seen[i] = 0;
    	}

        int subarrays = 0, curr = 1, cnt = 0;

        for(int i = 0; i < n; i++){
        	if(v[i] >= mid || seen[v[i]] == curr) continue;
            cnt++;
            seen[v[i]]++;
            if(cnt == mid){
            	cnt = 0;
            	curr++;
            	subarrays++;
            }
        }
        
        return subarrays >= k;
    };

    
    int lo = 0, hi = n;
    int ans = hi;

    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;

        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
            
        }
        else hi = mid - 1;
    }

    
    cout << ans  << nl;
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