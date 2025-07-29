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
    string s;
    cin >> s;
    vector<int> v(n);
    inp(v)

    int mx = -1e9, curr = -1e9;

    for(int i = 0; i < n; i++){
        if(s[i] != '0'){
            curr = max(v[i], curr + v[i]);
        }
        else{
            curr = -1e9;
        }
        mx = max(curr,mx);
    }
    
    if(mx > k) cout << "No";
    else if(mx == k){
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            if(s[i] == '0') v[i] = -1e18;
        }
        for(auto &i : v) cout << i << " ";
    }
    else {
        if(count(all(s),'0') == 0) cout << "No";
        else{
            int t = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '0'){
                    t = i;
                    break;
                }
            }

            int premx = 0, suffmx = 0;
            int curr = 0;
            int i = t-1;
            while(i >= 0 && s[i] == '1'){
                curr += v[i];
                premx = max(premx, curr);
                i--;
            }
            curr = 0;
            i = t+1;
            while(i < n && s[i] == '1'){
                curr += v[i];
                suffmx = max(suffmx, curr);
                i++;
            }
            v[t] = k - premx - suffmx;
            for(int i = 0; i < n; i++){
                if(i != t && s[i] == '0') v[i] = -1e18;
            }
            cout << "Yes\n";
            for(auto &i : v) cout << i << " ";
        }

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