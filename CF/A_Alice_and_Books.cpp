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
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() == 1)
    {
        int ele = *s.begin();
        cout << 2 * ele << nl;
    }
    else if (n == 2)
        cout << a[0] + a[1] << nl;
    else
    {
        auto maxx = max_element(all(a));
        int indx = distance(a.begin(), maxx);
        // cout<<indx;
        if (indx == n - 1)
        {
            int max1 = 0;
            for (int i = 0; i < n - 1; i++)
            {
                max1 = max(max1, a[i]);
            }
            cout << max1 + (*maxx) << nl;
        }
        else
        {
            // int max2 = 0;
            // for (int i = indx; i < n - 1; i++)
            // {
            //     max2 = max(max2, a[i]);
            // }
            cout << a[n-1] + (*maxx) << nl;
        }
    }
    
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