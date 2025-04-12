#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x

const int INF = 1e18;


int mul(int mid, int j) {
    int ans = 1;
    
    while(j--) {
        if (ans > INF / mid) {
            return INF + 1;
        }
        ans *= mid;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    bool ck = false;
    for (int i = 2; i <= 60; i++)
    {
        int lo = 2;
        int hi = 1e9;
        
        while(lo <= hi){
            int mid = (lo+hi)/2;
            // cout << mid << "!! ";
            int sum = 0;
            for(int j = 0; j <= i; j++){
                sum += mul(mid,j);          // inbuilt pow funtion gives TLE 
                if(sum > n) break;
            }
            // cout << sum << "\n";
            if(sum == n){
                cout << "YES" << nl;
                return;
            }
            else if(sum < n) lo = mid + 1;
            else hi = mid - 1;
        }
    }

    cout << "NO\n";
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