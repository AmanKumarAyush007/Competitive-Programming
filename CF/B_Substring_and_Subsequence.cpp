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
    string s;
    cin >> s;
    int n = s.size();
    string s1;
    cin >> s1;
    int m = s1.size();
    int ans = n + m;
    for (int i = 0; i < m; i++)
    {
        int j = i;
        for (auto c : s)
        {
            if (j < m and c == s1[j])
                ++j;
        }
        ans = min(ans, n + m - (j - i));
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