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
    if (n >= 4)
    {
        vector<int> v;
        int ele = n;
        int ele1 = 1;
        for(int i = 0; i < n; i++){
            
            if(i%2 == 0) v.pb(ele),ele--;
            else v.pb(ele1++);
        }

        for(int &i : v) cout << i << " ";

    }
    else{
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
    }
    cout << nl;
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