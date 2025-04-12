#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

int binarySearchR(int *a, int tar, int n){    //upper_bound
    int h = n - 1;
    int l = 0;
    int mid = (h + l) / 2;
    int ans = n;
    while (h >= l)
    {
        mid = (h + l) / 2;
        if (a[mid] > tar)
        {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    return ans ;
}

int binarySearchL(int *a, int tar, int n)
{
    int h = n - 1;
    int l = 0;
    int mid = (h + l) / 2;
    int ans = n;
    while (h >= l)
    {
        mid = (h + l) / 2;
        if (a[mid] >= tar)
        {
            h = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    return ans;
    
    // return (arr[mid - 1] == target) ? mid - 1 : mid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<nl;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int l, r;
        cin >> l >> r;
        int indxR = binarySearchR(a, r, n);
        int indxL = binarySearchL(a, l, n);
        // cout<<indxL<<" "<<indxR<<nl;

        cout << max(0,(indxR - indxL)) << " ";
    }

    
    return 0;
}