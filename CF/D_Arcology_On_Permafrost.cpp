#include<bits/stdc++.h>
using namespace std;

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


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    // n/(max(x,k)) >= (m+1) -> such that frequncy of all the element is greater than equal to m+1 so that after m subarry deletion atleast one of the occurence would be present
    //  => x = n/m+1 this is the max value of the answer
    // there are two possibilities
        //1-> n/k >= (m+1) then k is the answer but we can take greater values of k as well therefore replace x in place of k then equation would be n/(m+1) >= x  then x should be less than equal to n/m+1 and we need the max value of x . Hence x = n/(m+1)
        //2 -> n/k < (m+1) then ans must be k , larger val of k also n/x < (m+1)


    int mn = n/(m+1);

    if(n < k*(m+1)) mn = k;

    for(int i = 0; i < n; i++){
        cout << i % mn << " ";
    }

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