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
#define inf              LLONG_MAX
#define hell             LLONG_MIN
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
    int n,m;
    cin >> n >> m;
    vector<int> a(n+m+1), b(m+n+1);
    inp(a);
    inp(b);

    int N = n+m+1;
    int Ai = 0, Bi = 0;
    int st = 0, pt = 0;

    for(int i = 0; i < N; i++){
        if(Ai == n){
            st = i;
            break;
        }
        if(Bi == m){
            st = i;
            pt = 1;
            break;
        }

        if(a[i] > b[i]) Ai++;
        else Bi++;
    }

    if(pt){
        swap(a,b);
    }

    int sum = 0;
    int ind = -1;

    for(int i = 0; i < N; i++){
        if(i < st){
            sum += max(a[i],b[i]);
        }
        else{
            sum += b[i];
            if(ind == -1 && a[i] > b[i]){
                ind = i;
            }
        }
    }

    for(int i = 0; i < N; i++){
        int curr = sum;
        if(i < st){
            curr -= max(a[i],b[i]);
            if(a[i] > b[i]){
                if(ind != -1){
                    curr += a[ind];
                    curr -= b[ind];
                }
                else {
                    curr += a[N-1];
                    curr -= b[N-1];
                }
            }
        }
        else curr -= b[i];

        cout << curr << " ";
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