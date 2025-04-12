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
    ll n;
    cin >> n;
    set<ll> s;
    
    if (__builtin_popcountll(n) == 1)  //finds the no. of turned-on bits in "n" in O(1)
    {
        s.insert(n);
    }
    else
    {
        ll ch;
        s.insert(n);
        for (int i = 0; i < 62; i++)
        {
            ch = n & (1ll << i);
            if (ch != 0)
            {
                ll ele = n ^ (1ll << i);
                s.insert(ele);
            }
        }
    }

    cout << s.size() << nl;
    for (auto &i : s)
        cout << i << " ";

    cout << nl;
}

int main()
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