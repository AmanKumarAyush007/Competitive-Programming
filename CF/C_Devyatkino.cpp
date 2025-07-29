#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ff first
#define ss second
#define pb push_back
#define inf LLONG_MAX
#define hell LLONG_MIN
#define nl '\n'
#define all(a) (a).begin(), (a).end()
#define sm(v) accumulate(all(v), 0LL)
#define inp(v)        for (auto &x : v) cin >> x;
#define setbit(x) __builtin_popcountll(x)
#define lg(x) (63 - __builtin_clzll(x)) // log base 2

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

bool check(int n)
{
    while (n > 0)
    {
        int dig = n % 10;
        n /= 10;
        if (dig == 7)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    if (check(n))
        cout << 0;
    else
    {
        int ans = 9;
        for (int k = 1; k <= 9; k++)
        {
            int num = n - k;
            int mn = 7;
            while (num)
            {
                int d = num % 10;
                int x = 0;
                if(d <= 7) x = 7 - d;
                else x = 7 + (10-d);
                mn = min(mn, x);
                num /= 10;
            }
            if (mn <= k)
            {
                ans = min(ans, k);
                break;
            }
        }
        cout << ans;
    }

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