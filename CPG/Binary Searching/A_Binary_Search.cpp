#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

int binarySearch(int *a, int tar, int n)
{
    int h = n - 1;
    int l = 0;
    while (h >= l)
    {
        int mid = (h + l) / 2;
        if (a[mid] == tar)
            return 1;
        else if (a[mid] > tar)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    int a[n];
    int b[x];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < x; i++)
    {
        cin >> b[i];
        int ans = binarySearch(a, b[i], n);
        if (ans == 0)
            cout << "NO" << nl;
        else
            cout << "YES" << nl;
    }

    return 0;
}