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

    if(n % 2 == 1) cout << "NO";
    else if(n == 2){
        if(s == "EE" || s == "SS" || s == "WW" || s == "NN") cout << "RH";
        else cout << "NO";
    }
    else {
        map<char,vector<int>> mp;
        for(int i = 0; i < n; i++){
           mp[s[i]].pb(i);
        }

        string ans(n,'R');


        int e = mp['E'].size();
        int w = mp['W'].size();
        int s = mp['S'].size();
        int no = mp['N'].size();

        if(e == 1 && w == 1 && s == 1 && no == 1){
            int ind = mp['E'][e-1];
            ans[ind] = 'H';
            ind = mp['W'][w-1];
            ans[ind] = 'H';
            cout << ans << nl;
            return;
        }

        int x = abs(e- w);
        int y = abs(no - s);
        // cout << x << " " << y << nl;

        if(((x % 2) == (y % 2)) && (x%2 == 0) ){
            while(x){
                int ind = 0;
                if(e >= w){
                    ind = mp['E'][mp['E'].size()-1];
                    mp['E'].pop_back();                    
                }
                else{
                    ind = mp['W'][mp['W'].size()-1];
                    mp['W'].pop_back();
                }
                // cout << ind << nl;
                if((x&1)) ans[ind] = 'H';
                x--;
            }


            while(y){
                // cerr << "!!";
                int ind = 0;
                if(no >= s){
                    ind = mp['N'][mp['N'].size()-1];
                    mp['N'].pop_back();                    
                }
                else{
                    ind = mp['S'][mp['S'].size()-1];
                    mp['S'].pop_back();
                }
                if(y&1) ans[ind] = 'H';
                y--;
            }

            // for(auto &[a,b] : mp) cout << a << " " << b.size() << nl;

            int p = mp['E'].size();
            int q = mp['N'].size();


            while(q){
                if(q&1){
                    int ind = mp['N'][mp['N'].size()-1];
                    mp['N'].pop_back();  
                    ans[ind] = 'H';
                    ind = mp['S'][mp['S'].size()-1];
                    mp['S'].pop_back();  
                    ans[ind] = 'H';
                }
                q--;
            }

            while(p){
                if(p&1){
                    int ind = mp['E'][mp['E'].size()-1];
                    mp['E'].pop_back();  
                    ans[ind] = 'H';
                    ind = mp['W'][mp['W'].size()-1];
                    mp['W'].pop_back();  
                    ans[ind] = 'H';
                }
                p--;
            }

            cout << ans;
            
        }
        else cout << "NO";

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