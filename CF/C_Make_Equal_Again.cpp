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
    set<int> s;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        s.insert(a[i]);
    }

    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0])
            count++;
        else
            break;
    }
    int back = 0;
    for(int i = n-1; i >= 0; i--){
            if(a[n-1] == a[i]) back++;
            else break;
    }
    if(s.size() == 1) cout<<0<<nl;
    else if (a[n - 1] != a[0]) cout << n - max(count,back) << nl;
    else{
        cout << n - (count+back) << nl;
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