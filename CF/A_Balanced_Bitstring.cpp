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
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(i + k < n){
            if(s[i+k] != s[i]){
                if(s[i+k] != '?' && s[i] != '?') {
                    cout << "NO\n";
                    return;
                }
                else{
                    if(s[i] != '?' && s[i+k] == '?') s[i+k] = s[i];
                }
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        if(i - k >= 0){
            if(s[i-k] != s[i]){
                if(s[i-k] != '?' && s[i] != '?') {
                    cout << "NO\n";
                    return;
                }
                else{
                    if(s[i] != '?' && s[i-k] == '?') s[i-k] = s[i];
                }
            }
        }
    }

    int cnt0 = 0, cnt1 = 0, cntq = 0;
    
    for(int i = 0; i < k; i++){
        if(s[i] == '1') cnt1++;
        else if(s[i] == '0') cnt0++;
        else cntq++;
    }

    if((cnt1 > k/2) ||(cnt0 > k/2)) cout << "NO\n";
    else{
        for(int i = k; i < n; i++){
            if(s[i] == '1') cnt1++;
            else if(s[i] == '0') cnt0++;
            else cntq++;
            if(s[i-k] == '1') cnt1--;
            else if(s[i-k] == '0') cnt0--;
            else cntq--;
            if((cnt1 > k/2) || (cnt0 > k/2))  {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
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