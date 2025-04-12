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
    string s;
    cin >> s;
    set<char> m;
    for (int i = 0; i < n; i++)
    {
        m.insert(s[i]);
    }
    vector<char> uni(all(m));
    int x = uni.size();
    if (x == 1)
    {
        cout << s << endl;
    }
    else
    {
        map<char, char> mp;
        for (int i = 0; i < x; i++)
        {
            mp[uni[i]] = uni[x - 1 - i];
            mp[mp[uni[i]]] = uni[i];
        }
        for (int i = 0; i < n; i++)
        {
            s[i] = mp[s[i]];
        }

        cout << s << endl;
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