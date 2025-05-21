#include <bits/stdc++.h>
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

void solve()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];

    map<int,vector<pair<int,int>>> mp;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]].pb({i,j});
        }
    }


    int sum = 0;

    for(auto &[a,b] : mp){
        vector<pair<int, int>> vp = b;

        vector<int> x,y,suff_x,suff_y;

        for(auto &[a,b] : vp){
            x.pb(a);
            y.pb(b);
        }

        sort(all(x));
        sort(all(y));

        suff_x = x;
        suff_y = y;

        

        for(int i = x.size() - 2; i >= 0; i--){
            suff_x[i] += suff_x[i+1];
        }

        for(int i = y.size() - 2; i >= 0; i--){
            suff_y[i] += suff_y[i+1];
        }

        for(int i = 0; i < x.size() - 1; i++){
            sum += suff_x[i+1] - (x[i]*(x.size() - 1 - i)); 
        }

        for(int i = 0; i < y.size() - 1; i++){
            sum += suff_y[i+1] - (y[i]*(y.size() - 1 - i)); 
        }

    }


    cout << sum;
    cout << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}