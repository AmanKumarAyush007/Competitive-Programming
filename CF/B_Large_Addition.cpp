#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int check = 1;
    if (s[0] != '1')
        check = 0;
    if (s[n - 1] == '9')
        check = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '0')
        {
            check = 0;
            break;
        }
    }
    cout << (check == 1 ? "YES" : "NO") << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}