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
    int a[n];
    for (int &i : a)
        cin >> i;
    vector<int> v;
    v.pb(2);
    int i = 0;
    while (v[i] < 1000000009)
    {
        int ele = v[i] + (2 * (i + 2)) + i + 1;
        v.pb(ele);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 1)
            cout << 0 << nl;
        else
        {
            auto it = lower_bound(all(v), a[i]);
            int indx = distance(v.begin(), it);
            if (it != v.end())
            {
                int k = *it;
                if (k == a[i])
                    cout << 1 << nl;
                else
                {
                    int ans = 0;
                    while (a[i] > 1)
                    {
                        if (k == a[i]){
                            ans++;
                            break;
                        }
                        ans++;
                        a[i] -= v[indx - 1];
                        auto it = lower_bound(all(v), a[i]);
                        indx = distance(v.begin(), it);
                        k = *it;
                    }
                    cout<<ans<<nl;
                }
            }
        }
    }
}

int main()
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