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
#define nl               endl
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


int sz;

int query(vector<int> &v){
    cout << "? " << v.size() << " ";
    for(auto &i : v) cout << i << " ";
    cout << endl;


    int res;
    cin >> res;

    return res;
}


int bs1(){
    int lo = 1, hi = sz;
    int ans = 1;
    
    while(lo <= hi){
        int mid = (lo+hi)/2;
        
        vector<int> temp(mid);
        iota(all(temp), 1);

        int val = query(temp);
        bool check = (mid - val) % 2;

        if(check){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    return ans;
}


int bs2(int lst){
    int lo = 1, hi = lst-1;

    int ans = 1;
    
    while(lo <= hi){
        int mid = (lo+hi)/2;
        
        vector<int> temp;
        for(int i = 1; i <= mid; i++){
            temp.pb(i);
        }
        temp.pb(lst);


        int val = query(temp);
        

        if((mid+1 - val) & 1){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    return ans;
}


int bs3(int z, int y){

    int lo = 1, hi = y - 1;
    int ans = hi;

    
    while(lo <= hi){

        int mid = (lo+hi)/2;
        
        vector<int> temp;
        for(int i = 1; i <= mid; i++){
            temp.pb(i);
        }
        temp.pb(z);
        temp.pb(y);


        int val = query(temp);
        bool check = (temp.size() - val) % 2;

        if(check){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    sz = 2*n+1;

    int z = bs1();

    int y = bs2(z);

    int x = bs3(z,y);

    cout << "! " << x << " " << y << " " << z;
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