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

    int t;
    cin >> t;
    int x = t;
    int sum = 0;
    vector<string> v;
    while (t--)
    {
        string s;
        cin >> s;
        v.pb(s);
        int r;
        cin >> r;
        sum += r;
    }
    sum = sum % x;
    sort(v.begin(), v.end());
    cout << v[sum];
    return 0;
}