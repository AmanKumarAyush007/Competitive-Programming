#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (b == 1)
        b++, ans++;
    while (a != 0)
    {
        cout << a << " ";
        a /= b, ans++;
        if (a >= b and (a/(b+1) != a/b))
            b++, ans++;
    }
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}