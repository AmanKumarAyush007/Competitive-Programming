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
    int a[n];
    inp(a)
    stack<int> s,t;
    s.push(-1);
    t.push(-1);

    for(int i = n-1; i >= 0; i--){
        if((s.top() <= a[i]) && (t.top() <= a[i])){
            if(s.top() > t.top()) s.push(a[i]);
            else if(s.top() < t.top()) t.push(a[i]);
            else {
                (s.size() >= t.size()) ? s.push(a[i]) : t.push(a[i]);
            }
        }
        else if(s.top() <= a[i]) s.push(a[i]);
        else if(t.top() <= a[i]) t.push(a[i]);
        else{
            if(s.top() > t.top()) s.push(a[i]);
            else if(s.top() < t.top()) t.push(a[i]);
            else {
                (s.size() >= t.size()) ? s.push(a[i]) : t.push(a[i]);
            }
        }
    }

    vector<int> p,q;
    while(s.top() != -1){
        int x = s.top();
        s.pop();
        p.pb(x);
    }
    while(t.top() != -1){

        int x = t.top();
        t.pop();
        q.pb(x);
    }

    int ans = 0;

    if(p.size() >= 2){
        for(int i = 0; i < (p.size())-1; i++){
            if(p[i] < p[i+1]) ans++;
        }

    }
    if(q.size() >= 2){
        for(int i = 0; i < (q.size())-1; i++){
            if(q[i] < q[i+1]) ans++;
        }

    }

    cout << ans << nl;
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