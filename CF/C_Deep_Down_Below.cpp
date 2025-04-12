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

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.ff == b.ff) {return a.ss > b.ss;}
    return a.ff < b.ff;
}

bool check(vector<pair<int,int>>& vp, int mid){
    int n = vp.size();
    if(n == 1) return mid > vp[0].ff;


    for(int i = 0; i < n; i++){
        if(vp[i].ff >= mid) {
            return false;
        }
        mid += vp[i].ss;
    }

    return true;
}


void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;

    while(n--){
        int x;
        cin >> x;
        int mx = hell;
        for(int i = 0; i < x; i++){
            int ele;
            cin >> ele;
            mx = max(mx,ele - i);
        }
        vp.pb({mx,x});

    }

    sort(all(vp),cmp);

    int hi = 1e11;
    int lo = 0;
    int ans = 0;

    while(hi >= lo){
        int mid = (hi+lo)/2;
        if(check(vp,mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }


    cout << ans;



    // for(auto &[a,b] : vp) cout << a << " " << b << nl; 
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