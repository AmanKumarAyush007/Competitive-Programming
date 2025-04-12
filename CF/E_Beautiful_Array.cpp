#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()
#define inp(v)  for (auto &x : v) cin >> x
    

void solve()
{
    int n, m;           
    cin >> n >> m;
    cout << 3 << nl <<  m << " " << m << " " << 3 * n -2*m;     //sum of all ele is 3*n hence mean is n and more than half of the elements are m the median must be m
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