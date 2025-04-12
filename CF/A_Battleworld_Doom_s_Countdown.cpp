#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x
#define sm(v)      accumulate(all(v),0LL)


void solve(){
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    inp(v);
    string corr;
    cin >> corr;
    
    int L = corr.size();
    int cnt_short = 0;
    int sme = 0;
    
    for (auto &s : v) {
        if (s.size() < L) {
            cnt_short++;
        } else if (s.size() == L){
            sme++;
        }
    }
    
    int best_inc = cnt_short;
    int worst_inc = cnt_short + (sme - 1);
    
    int best = best_inc + 1 + (best_inc / k) * 7;
    int worst = worst_inc + 1 + (worst_inc / k) * 7;
    
    cout << best << " " << worst << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}