#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

ll maxSum(vector<ll> &pre,ll indx, vector<ll> &suff){
    int n = pre.size();
    ll ans = abs(pre[indx]);
    if (indx != n - 1) ans += suff[indx + 1];
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n), pre(n), suff(n), indx;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if(i == 0) pre[i] = v[i];
        else pre[i] = pre[i-1] + v[i]; 
        if (v[i] < 0) indx.pb(i);
    }
    suff[n-1] = v[n-1];
    for(ll i = n-2; i >= 0; i--){
        suff[i] = v[i] + suff[i+1];
    }
    if(indx.size() == 0) cout << pre[n-1] << nl;
    else
    {
        ll sol = 0;
        for (ll i = 0; i < indx.size(); i++)
        {
            sol = max(sol, maxSum(pre, indx[i], suff));
        }
        cout << sol << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}