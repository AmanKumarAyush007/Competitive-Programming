#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif
#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              (int)1e18
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());



void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    inp(v);

    map<int,int> mp, st, en;

    for(auto &i : v) mp[i]++;

    for(int i = 0; i < n; i++){
        if(!st.count(v[i])) st[v[i]] = i;
        en[v[i]] = i;
    }

    vector<int> swp;

    for(auto &[a,b] : mp){
        int i = st[a];
        int j = en[a];
        if(j-i+1 != b) swp.pb(a);
    }

    auto check = [&](){
        st.clear();
        en.clear();

        for(int i = 0; i < n; i++){
            if(!st.count(v[i])) st[v[i]] = i;
            en[v[i]] = i;
        }


        for(auto &[a,b] : mp){
            int i = st[a];
            int j = en[a];
            if(j-i+1 != b){
                return 0;
            }
        }

        return 1;
    };

    auto tsp = [&](int l, int r, int k){
        int a, b = -1;
        for(int i = l; i <= r; i++){
            if(v[i] != k) {
                a = i;
                break;
            }
        }
        for(int i = 0; i < l; i++){
            if(v[i] == k){
                b = i;
                break;
            }
        }

        if(b == -1){
            for(int i = r+1; i < n; i++){
                if(v[i] == k){
                    b = i;
                    break;
                }
            }
        }

        return make_pair(a,b);
    };

    
    if(swp.size() > 2) cout << "NO";
    else if(swp.size() == 0) cout << "YES";
    else {
        int x = swp[0];
        
        vector<int> bin(n);

        for(int i = 0; i < n; i++){
            bin[i] = (v[i] == x);
        }
        
        prefixsum(bin);

        auto check2 = [&](int p, int len){
            return (bin[p] - bin[p - len]) == (len-1);
        };

        int win = mp[x];

        int end = -1;

        for(int i = win-1; i < n; i++){
            int fre = bin[i];
            if(i-win >= 0) fre -= bin[i-win];
            if(fre == win-1){
                end = i;
                break;
            }
        }

        // debug(x,win,end);
        

        if(end == -1) cout << "NO";
        else{
            int rx = -1;
            for(int i = end - win + 1; i <= end; i++){
                if(v[i] != x){
                    rx = i;
                    break;
                }
            }

            int ry = -1;

            for(int i = 0; i < end - win + 1; i++){
                if(v[i] == x){
                    ry = i;
                    break;
                }
            }

            if(ry == -1){
                for(int i = end+1; i < n; i++){
                    if(v[i] == x){
                        ry = i;
                        break;
                    }
                }
            }

            swap(v[rx], v[ry]);

            // debug(v);

            st.clear();
            en.clear();

            for(int i = 0; i < n; i++){
                if(!st.count(v[i])) st[v[i]] = i;
                en[v[i]] = i;
            }

            // debug(v);
            // debug(st, en);
            // debug(swp);
            // debug(mp[1], mp[4]);

            bool ty = 0;

            for(auto &[a,b] : mp){
                int i = st[a];
                int j = en[a];
                if(j-i+1 != b){
                    swap(v[rx], v[ry]);
                    // bool temp = check();
                    
                    if(win == 2 || (swp.size() == 2 && mp[swp[1]] == 2)){
                        ty = 1;
                        break;
                    }
                    else{
                        // debug(v);
                        // debug(check2(end+1, mp[x]));

                        for(int i = end+1; i < n; i++){
                            if(check2(i, mp[x])){
                                tie(rx,ry) = tsp(i - mp[x] + 1, i, x);
                                // debug(rx,ry);
                                swap(v[rx], v[ry]);
                                // debug(v);
                                if(check()){
                                    cout << "YES\n";
                                    return;
                                }
                                swap(v[rx], v[ry]);
                            }
                        }

                        cout << "NO\n";
                        return;
                    }
                }
            }

            if(ty){
                // debug(v);

                if(win != 2) x = swp[1];
                int ind;

                for(int i = 0; i < n; i++){
                    if(v[i] == x){
                        ind = i;
                        break;
                    }
                }
                

                if(ind+1 < n){
                    tie(rx,ry) = tsp(ind, ind+1, x);
                    swap(v[rx], v[ry]);
                    if(check()){
                        cout << "YES\n";
                        return;
                    }
                    swap(v[rx], v[ry]);
                }
                if(ind-1 >= 0){
                    tie(rx,ry) = tsp(ind-1, ind, x);
                    swap(v[rx], v[ry]);
                    if(check()){
                        cout << "YES\n";
                        return;
                    }
                    swap(v[rx], v[ry]);
                }
                
                for(int i = 0; i < n; i++){
                    if(v[i] == x && i != ind){
                        ind = i;
                        break;
                    }
                }
                
                if(ind+1 < n){
                    tie(rx,ry) = tsp(ind, ind+1, x);
                    swap(v[rx], v[ry]);
                    if(check()){
                        cout << "YES\n";
                        return;
                    }
                    swap(v[rx], v[ry]);
                }
                if(ind-1 >= 0){
                    tie(rx,ry) = tsp(ind-1, ind, x);
                    swap(v[rx], v[ry]);
                    if(check()){
                        cout << "YES\n";
                        return;
                    }
                    swap(v[rx], v[ry]);
                }

                cout << "NO\n";
                return;
            }


            cout << "YES";
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