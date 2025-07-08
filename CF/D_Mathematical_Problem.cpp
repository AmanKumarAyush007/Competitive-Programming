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
    string s;
    cin >> s;

    if((s.find('0') != string::npos && n >= 3) ){
        if(n > 3) cout << 0;
        else {
            if(s[0] == '0'|| s[2] ==  '0') cout << 0;
            else{
                int ans = inf;
                for(int i = 0; i < n-1; i++){
                    string curr = "";
                    curr += s[i];
                    curr += s[i+1];

                    int num = stoi(curr);
                    // cout << i << " " << num << nl;

                    for(int j = 0; j < n; j++){
                        if(j != i){
                            if(s[j] != '1'){
                                string d = "";
                                d+=s[j];
                                int x = stoi(d);
                                
                                if(num != 1) num += x;
                                else num *= x;
                            }
                        }
                        else j++;
                    }
                    ans = min(ans,num);
                    // cout << i << " " << ans << nl;
                    
                }
                cout << ans;
                
            }
        }
    } 
    else {
        unordered_set<char> st(all(s));

        if(st.size() == 1 && s[0] == '1') cout << 11;
        else{
            int ans = inf;
            for(int i = 0; i < n-1; i++){
                string curr = "";
                curr += s[i];
                curr += s[i+1];

                int num = stoi(curr);

                for(int j = 0; j < n; j++){
                    if(j != i){
                        if(s[j] != '1'){
                            string d = "";
                            d+=s[j];
                            int x = stoi(d);
                            num += x;
                        }
                    }
                    else j++;
                }
                ans = min(ans,num);
                
            }
            cout << ans;
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