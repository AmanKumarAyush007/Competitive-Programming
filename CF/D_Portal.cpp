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


void done(vector<int> &a, int st, int en) {
    int pos = st;
    for (int i = st + 1; i <= en; i++) {
        if (a[i] < a[pos]) {
            pos = i;
        }
    }

    rotate(a.begin() + st, a.begin() + pos, a.begin() + en + 1);
}

vector<int> funx(vector<int> arr, int ind) {
    int x = arr[ind];
    arr.erase(arr.begin() + ind);

    int pos = 0;
    while (pos < arr.size() && arr[pos] < x)
        pos++;

    arr.insert(arr.begin() + pos, x);
    return arr;
}


void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    inp(a);

    int st = (l != 0 ? l : 0);
    int en = r-1;

    done(a, st,en);

    vector<int> temp;

    int k = 0;

    for(int i = 0; i < st; i++){
        temp.pb(a[i]);
    }

    k = temp.size();

    temp.pb(a[st]);
    for(int i = en+1; i < n; i++){
        temp.pb(a[i]);
    }

    while(k > 0 && temp[k] < temp[k-1]){
        swap(temp[k], temp[k-1]);
        k--;
    }

    vector<int> temp1 = funx(temp,k);

    vector<int> ans;
    int ind = 0;

    for(int i = 0; i < temp1.size(); i++){
        if(temp1[i] == a[st]){
            ind = i+1;
            break;
        }
        ans.pb(temp1[i]);
    }

    for(int i = st; i <= en; i++){
        ans.pb(a[i]);
    }

    for(int i = ind; i < temp1.size(); i++){
        ans.pb(temp1[i]);
    }

    for(auto &i : ans) cout << i << " ";

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