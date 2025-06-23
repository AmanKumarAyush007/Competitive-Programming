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
#define allr(a)    (a).rbegin(),(a).rend()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)


void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    inp(a)

    vector<int> gaps;

    int diff = a[n-1] - a[0] + 1;
    
    for(int i = 0; i < n-1; i++){
        gaps.pb(a[i+1] - a[i] - 1);
    }

    sort(allr(gaps));

    for(int i = 0; i < k-1; i++){  // if I have to break the sequence into 3 parts then gaps must be 2 i.e k-1
        diff -= gaps[i];
    }
    
    cout << diff << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}