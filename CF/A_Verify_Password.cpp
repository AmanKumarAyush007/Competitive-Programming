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
    int check = 0;
    int con = 0;
    for (int i = 0; i < n; i++)
    {
        if ((!(s[i] >= 97 and s[i] <= 122)) and (!((s[i] >= 48 and s[i] <= 57))) )
            con = 1;
    }
    if (con == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] >= 97 and s[i] <= 122) && (s[i + 1] >= 48 and s[i + 1] <= 57))
            {
                cout << "NO" << nl;
                check = 1;
                break;
            }
            else if ((s[i] >= 97 and s[i] <= 122) && (s[i + 1] >= 97 and s[i + 1] <= 122))
            {
                if (s[i] > s[i + 1])
                {
                    cout << "NO" << nl;
                    check = 1;
                    break;
                }
            }
            else if ((s[i] >= 48 and s[i] <= 57) && (s[i + 1] >= 48 and s[i + 1] <= 57))
            {
                if (s[i] > s[i + 1])
                {
                    cout << "NO" << nl;
                    check = 1;
                    break;
                }
            }
        }
        if (check == 0)
            cout << "YES" << nl;
    }
    else cout << "NO" << nl;
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