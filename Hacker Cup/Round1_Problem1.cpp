#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    int n;
    cin >> n;

    double lo = 0;
    double hi = 1e9;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        double minSP = (double)(i)/b;
        double maxSP = (double)(i)/a; 

        lo = max(lo,minSP);
        hi = min(hi,maxSP);

    }   

    if(hi < lo) cout << -1 << nl;
    else cout << setprecision(9) << lo <<nl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}