#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h;
    cin >> h;
    int c = 0;
    for (ll i = 0; i < 1000000009; i++)
    {
        c += pow(2, i);
        if (c > h)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}