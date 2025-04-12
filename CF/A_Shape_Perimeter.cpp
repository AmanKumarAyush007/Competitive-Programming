#include <bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define inp(v)     for(auto& x : v) cin >> x

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        vp.pb({x, y});
    }
    for (int i = 1; i < vp.size(); i++)
    {
        vp[i].ff = vp[i].ff + vp[i - 1].ff;
        vp[i].ss = vp[i].ss + vp[i - 1].ss;
    }
    // cout << nl;

    for(auto &[a,b] : vp){
        a += m;
        b += m;
        // cout << a << " "<< b << nl;
    }
    // for(auto &[a,b] : vp){
    //     // a += m;
    //     // b += m;
    //     cout << a << " "<< b << nl;
    // }

    int x = m, y = m;


    for(int i = 1; i < vp.size(); i++){
        x += vp[i].ff -  vp[i-1].ff;
        y += vp[i].ss - vp[i-1].ss;
        
    }

    cout << 2*x + 2*y ;


    cout << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}