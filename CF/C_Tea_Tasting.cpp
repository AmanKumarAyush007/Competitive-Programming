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

bool check(int st,int en, vector<int>& v, int mx){
    int till = v[en];
    int extra = (st > 0 ? v[st-1] : 0);
    int net = till - extra;
    return net <= mx;
}


void solve(){
    int n;
    cin >> n;
    vector<int> b(n),a(n), ans(n);
    inp(a)
    inp(b)
    vector<int> pre = b;
    for(int i = 1; i < n; i++){
        pre[i] += pre[i-1];
    }

    vector<int> diff(n);

    for(int i = 0; i < n; i++){
        int j = i;

        int hi = n-1;
        int lo = i;

        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(check(i,mid,pre,a[i])){
                j = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        if((a[i] > (pre[j] - (i > 0 ? pre[i-1] : 0))) && (j+1 < n)){
            ans[j+1] += a[i] - (pre[j] - (i > 0 ? pre[i-1] : 0));
        }

        if(i != j){
            diff[i]++;
            if(j + 1 < n)diff[j+1]--;
        }
        else{
            ans[i] += min(b[i],a[i]);
        }
    }
    for(int i = 1; i < n; i++){
        diff[i] += diff[i-1];
    }


    for(int i = 0; i < n; i++){
        ans[i] += diff[i]*b[i];
    }


    for(auto &i : ans) cout << i << " " ;
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