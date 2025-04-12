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
    int n, f, k;
    cin >> n >> f >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int tar = a[f - 1];
    sort(a, a + n,greater<int>());
    // for(int i = 0; i < n; i++){
    //     cout<<a[i]<<" ";
    // }
    int check = 0;
    int check1 = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == tar)
        {
            check = 1;
            break;
        }
    }
    for (int i = k; i < n; i++)
    {
        if (a[i] == tar)
        {
            check1 = 1;
            break;
        }
    }
    if(check == 1 && check1 == 1) cout<<"MAYBE"<<nl;
    else if(check == 1 && check1 == 0) cout<<"YES"<<nl;
    else if(check == 0 && check1 == 1) cout<<"NO"<<nl;
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