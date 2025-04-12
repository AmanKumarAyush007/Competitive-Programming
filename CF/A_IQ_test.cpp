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
    int odd = 0, even = 0;
    for (int &i : a)
    {
        cin >> i;
        if (i % 2 == 0)
            even++;
        else
            odd++;
    }
    if (odd > even)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0){
                cout << i+1;
                break;
            }

        }
    }
    else{
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0){
                cout << i+1;
                break;
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