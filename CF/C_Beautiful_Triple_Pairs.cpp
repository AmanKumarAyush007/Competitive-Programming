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
    vector<int> v(n);
    inp(v)

    map<pair<int,int>, vector<int>> mp;
    int ans = 0;


    //case 1 -> x y z | x y k
    for(int i = 0; i < n-2; i++){
        mp[{v[i],v[i+1]}].pb(v[i+2]);
        
    }

    for(auto &[a,b] : mp){
        if(b.size() >= 2){

            sort(all(b));

            for(int i = 0; i < b.size(); i++){
                auto it = upper_bound(all(b),b[i]);
                if(it != b.end()){
                    int ex = it - b.begin();
                    ans += b.size() - ex;
                }
            }

        }

    }

    mp.clear();



    //case 2 -> x z y  | x k y 
    for(int i = 1; i < n-1; i++){
        mp[{v[i-1],v[i+1]}].pb(v[i]);
    }

    for(auto &[a,b] : mp){

        if(b.size() >= 2){

            sort(all(b));

            for(int i = 0; i < b.size(); i++){
                auto it = upper_bound(all(b),b[i]);
                if(it != b.end()){
                    int ex = it - b.begin();
                    ans += b.size() - ex;
                }
            }

        }
    }

    mp.clear();
    
    // //case 3 -> z x y   | k x y 

    for(int i = 1; i < n-1; i++){
        mp[{v[i],v[i+1]}].pb(v[i-1]);    
    }

    for(auto &[a,b] : mp){

        if(b.size() >= 2){

            sort(all(b));

            for(int i = 0; i < b.size(); i++){
                auto it = upper_bound(all(b),b[i]);
                if(it != b.end()){
                    int ex = it - b.begin();
                    ans += b.size() - ex;
                }
            }

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