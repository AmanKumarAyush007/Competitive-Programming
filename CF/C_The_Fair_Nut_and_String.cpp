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

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    if(count(all(s),'a') == 0) cout << 0;
    else{
        // for(int i = 0; i < s.size(); i++){                           ---------this loops runs in O(N*N);
        //     if(s[i] != 'a' && s[i] != 'b') s.erase(i,1);   
        // }

        // s.erase(remove_if(s.begin(), s.end(), [](char c){            ---------this loops runs in O(N);
        //     return c != 'a' && c != 'b';
        // }), s.end());


        // --------- this loops runs in O(N); ----------------------
        string temp = s;                                                
        s = "";
        for(auto &i : temp) if(i == 'a' || i == 'b') s+=i;



        int ans = 1;
        n = s.size();
        
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && s[j] == 'a'){
                j++;
            }

            if(s[i] == 'a') {
                j--;
                int cnt = j - i + 1;
                ans = ((ans % 1000000007) * ((cnt+1) % 1000000007)) % 1000000007;
                i = j;
            }
        }

        cout << ans - 1;   
    }

    cout << nl;
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