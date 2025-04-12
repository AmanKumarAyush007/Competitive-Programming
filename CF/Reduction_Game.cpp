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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &i : a)
        cin >> i;
    sort(a, a + n);


    int st = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            st = i;
            break;
            ;
        }
    }
    for (int i = st; i < n - 1; i++)
    {
        while (k < min(a[i], a[i + 1]))
        {
            a[i]--;
            a[i + 1]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
    }
    cout << ans << nl;
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