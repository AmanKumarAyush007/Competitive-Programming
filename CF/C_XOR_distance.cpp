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


void solve(){
    int n,m, k;
    cin >> n >> m >> k;

    if(n == m) cout << 0 ;
    else{
        if(n < m) swap(n,m);

        int ind = -1;
        int x = 0, cnt = 0;

        for(int i = 63; i >= 0; i--){
            if(((1LL << i) & n) > ((1LL << i) & m)) {
                cnt++;
                if(ind == -1) ind = i;
                else{
                    if((x|(1LL << i) )<= k) {
                        x |= (1LL << i);
                    }
                }
                
            }
        }
        cout << ((cnt == 1) ? n-m : abs((n^x )-(m^x )));
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