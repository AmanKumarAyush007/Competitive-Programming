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

int need(int i, vector<int>&v, int req){
    int j = i;
    
    while(req > 0 && j < v.size()){
        req -= v[j];
        j++;
    }

    if(req <= 0) return j;
    return -1;
}


void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), c(n);
    inp(a)
    inp(b)
    inp(c)

    int tot = sm(a);

    int req = (tot + 2) / 3;

    vector<int> v(6,-1);

    // 1 -> 2 -> 3

    int i = 0;
    int j = need(i,a,req);
    int ii = i;
    int jj = j;
    v[0] = i+1;
    v[1] = j;
    if(j != -1){
        i = jj;
        j = need(i,b,req);
        v[2] = i+1;
        v[3] = j;
        if(j != -1){
            i = j;
            j = need(i,c,req);

            v[4] = i+1;
            v[5] = j;
            if(j != -1){

                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }

    if(jj != -1){
        i = jj;
        j = need(i,c,req);
        v[4] = i+1;
        v[5] = j;
        if(j != -1){
            i = j;
            j = need(i,b,req);
            v[2] = i+1;
            v[3] = j;
            if(j != -1){
                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }


    // -----------------------------------------------------------------------------------


    
    i = 0;
    j = need(i,b,req);
    ii = i;
    jj = j;
    v[2] = i+1;
    v[3] = j;
    if(j != -1){
        i = jj;
        j = need(i,a,req);

        v[0] = i+1;
        v[1] = j;
        if(j != -1){

            i = j;
            j = need(i,c,req);

            v[4] = i+1;
            v[5] = j;
            if(j != -1){
                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }

    if(jj != -1){
        i = jj;
        j = need(i,c,req);
        v[4] = i+1;
        v[5] = j;
        if(j != -1){
            i = j;
            j = need(i,a,req);
            v[0] = i+1;
            v[1] = j;
            if(j != -1){
                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }

    //-------------------------------------------------------------------//


    
    i = 0;
    j = need(i,c,req);
    ii = i;
    jj = j;
    v[4] = i+1;
    v[5] = j;
    if(j != -1){
        i = jj;
        j = need(i,b,req);
        v[2] = i+1;
        v[3] = j;
        if(j != -1){
            i = j;
            j = need(i,a,req);
            v[0] = i+1;
            v[1] = j;
            if(j != -1){
                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }

    if(jj != -1){
        i = jj;
        j = need(i,a,req);
        v[0] = i+1;
        v[1] = j;
        if(j != -1){
            i = j;
            j = need(i,b,req);
            v[2] = i+1;
            v[3] = j;
            if(j != -1){
                int ind = 0;
                int mx = hell;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] >= mx){
                        ind = i;
                        mx = v[i];
                    }
                }
                if(mx != n) v[ind] = n;
                for(auto &i : v) cout << i << " ";
                cout << nl;
                return;
            }
        }

    }

    cout << -1 << nl;
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