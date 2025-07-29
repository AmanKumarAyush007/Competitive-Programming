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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inp(a)
    inp(b)

    map<int,pair<int,int>> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] = {0,i};
    }
    for(int i = 0; i < n; i++){
        mp[b[i]] = {1,i};
    }

    // set<pair<int,int>> st;
    vector<pair<int,int>> vp;
    // debug(mp);

    for(int i = 1; i <= 2*n; i += 2){
        if(mp[i].ff == 0){
            while(mp[i].ss != (((i-1)/2))){
                swap(a[mp[i].ss],a[(mp[i].ss)-1]);
                swap(mp[a[mp[i].ss]].ss,mp[a[(mp[i].ss)-1]].ss);
                vp.pb({1,mp[i].ss+1});
            }
            // st.insert({0,i-1});
        }
        else{
            int y = mp[i].ss;

            // debug(y,i-1);
            if(y > (((i-1)/2))){
                
                while(y != ((i-1)/2)){
                    swap(b[mp[i].ss],b[(mp[i].ss)-1]);
                    swap(mp[b[mp[i].ss]].ss,mp[b[(mp[i].ss)-1]].ss);
                    vp.pb({2,mp[i].ss+1});
                    y = mp[i].ss;
                }

                // cout << "#1\n";
                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);

                if(mp[i].ff != 0){
                    int ind = mp[i].ss;

                    swap(mp[b[ind]].ff,mp[a[ind]].ff);
                    swap(a[ind],b[ind]);
                    vp.pb({3,ind+1});
                }
                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);
                // cout << nl;
            }
            else if(y < (((i-1)/2))){
                

                // debug(y,i-1);
                while(y != ((i-1)/2)){
                    swap(b[mp[i].ss],b[(mp[i].ss)+1]);
                    swap(mp[b[mp[i].ss]].ss,mp[b[(mp[i].ss)+1]].ss);
                    vp.pb({2,mp[i].ss});
                    y = mp[i].ss;
                }

                // cout << "#2\n";


                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);


                if(mp[i].ff != 0){
                    int ind = mp[i].ss;

                    swap(mp[b[ind]].ff,mp[a[ind]].ff);
                    swap(a[ind],b[ind]);
                    vp.pb({3,ind+1});
                }
                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);
                // cout << nl;
            }
            else{
                // cout << "#3\n";
                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);

                if(mp[i].ff != 0){
                    int ind = mp[i].ss;
                    swap(mp[b[ind]].ff,mp[a[ind]].ff);
                    swap(a[ind],b[ind]);
                    vp.pb({3,ind+1});
                }

                // debug(a);
                // debug(b);
                // debug(mp);
                // debug(vp);
                // cout << nl;
                
            }
        }
    }


    // debug(a);
    // debug(b);
    // debug(mp);
    // debug(vp);
    // return;


    for(int i = 2; i <= 2*n; i += 2){
        int ind = mp[i].ss;
        // debug(ind);  
        while(ind != ((i-1)/2)){
            swap(mp[b[ind]].ss,mp[b[(ind)-1]].ss);
            swap(b[ind],b[(ind)-1]);
            vp.pb({2,ind});
            ind = mp[i].ss;  
            // debug(i-(n+1));
            // debug(ind);    
            // debug(a);
            // debug(b);
            // debug(mp);
            // debug(vp);  
            // return;
        }
    }

    debug(a);
    debug(b);
    // debug(mp);

    // debug(vp);
    // debug(a);
    // debug(b);
    cout << vp.size() << nl;
    for(auto &[a,b] : vp) cout << a << " " << b << nl;
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