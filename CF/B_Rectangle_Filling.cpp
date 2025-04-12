#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

void solve()
{
    int n, m;
    cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    if(n==1 || m== 1) {
        if(n==1 && c[0][0] == c[0][m-1]) cout << "YES";
        else if(m==1 && c[0][0] == c[n-1][0]) cout << "YES";
        else cout << "NO";
    }
    else if (c[0][0] == c[n - 1][m - 1] || c[0][m - 1] == c[n - 1][0])  cout << "YES";
    else
    {
        // case1 c[0][0] != c[n-1][m-1]
        // if c[0][0] is fixed
        bool ck1 = false;
        bool ck2 = false;

        for (int i = 0; i < n; i++)
        {
            if (c[i][m - 1] == c[0][0])
            {
                ck1 = true;
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (c[n - 1][i] == c[0][0])
            {
                ck2 = true;
                break;
            }
        }

        if (ck1 && ck2)
            cout << "YES";
        else
        {
            // if c[n-1][m-1] is fixed
            ck1 = false;
            ck2 = false;

            for (int i = 0; i < n; i++)
            {
                if (c[i][0] == c[n - 1][m - 1])
                {
                    ck1 = true;
                    break;
                }
            }
            for (int i = 0; i < m; i++)
            {
                if (c[0][i] == c[n - 1][m - 1])
                {
                    ck2 = true;
                    break;
                }
            }

            if (ck1 && ck2)
                cout << "YES";

            else
            {

                // if c[n-1][0] is fixed
                ck1 = false;
                ck2 = false;

                for (int i = 0; i < n; i++)
                {
                    if (c[i][m-1] == c[n-1][0])
                    {
                        ck1 = true;
                        break;
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    if (c[0][i] == c[n-1][0])
                    {
                        ck2 = true;
                        break;
                    }
                }

                if (ck1 && ck2)
                    cout << "YES";

                else{
                    // if c[0][m-1] is fixed
                    ck1 = false;
                    ck2 = false;

                    for (int i = 0; i < n; i++)
                    {
                        if (c[i][0] == c[0][m-1])
                        {
                            ck1 = true;
                            break;
                        }
                    }
                    for (int i = 0; i < m; i++)
                    {
                        if (c[n-1][i] == c[0][m-1])
                        {
                            ck2 = true;
                            break;
                        }
                    }

                    if (ck1 && ck2)
                        cout << "YES";
                    else cout << "NO";
                }
            }
        }
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