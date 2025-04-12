#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int sum(int n){ return (n*(n+1))/2;}

int check(int mid , int k, int n){
    int ans = ( sum(mid) - sum(k-1) )  - ( sum(n+k-1) - sum(mid) );
    return abs(ans);
}

void solve(){
    int n,k;
    cin >> n >> k;

    int lo = k;
    int hi = k+n-1;

    int ans = 0;
    int mid = (lo+hi)/2;

    while(lo <= hi){
        mid = (lo+hi)/2;

        if((check(mid,k,n) < check((mid+1), k, n)) && (check(mid,k, n) > check(mid-1, k, n)) ) hi = mid-1;
        else if((check(mid,k,n) > check(mid+1,k, n)) && (check(mid,k, n) < check(mid-1,k, n)) ) lo = mid+1;
        else if((check(mid,k,n) == check(mid+1,k, n)) || (check(mid,k, n) == check(mid-1,k, n))){
            ans = check(mid,k,n);
            break;
        }
        else if ((check(mid,k,n) < check(mid+1,k,n)) && (check(mid,k,n) < check(mid-1,k,n)) ) {
            ans = check(mid,k,n);
            break;
        }
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