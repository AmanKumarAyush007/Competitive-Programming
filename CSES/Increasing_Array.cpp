#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int premx = a[0];
    for (int i = 1; i < n; i++)
    {
        premx = max(a[i],premx);
        ans += max(0LL, premx - a[i]);
        // cout << max(0, a[i - 1] - a[i]) << nl;
    }
    cout << ans;

    cout << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}