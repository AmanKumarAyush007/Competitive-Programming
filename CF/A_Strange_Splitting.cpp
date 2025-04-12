#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define all(a) (a).begin(), (a).end()

int check(string &s, int *a){
    int count = 0;
    int start;
    int end;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B'){
            count++;
            if(count == 1) start = i;
            else end = i;
        }
    }
    if(a[end] - a[start] == 0) return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    if (st.size() == 1)
        cout << "NO" << nl;
    else
    {
        string s;
        for (int i = 0; i < n; ++i)
        {
            s += 'B';
        }
        int chg;
        for (int i = 0; i < n; i++)
        {
            if(a[i]!= a[i+1]){
                chg = i;
                break;
            }
        }
        s[chg] = 'R';
        
        if(check(s,a)){
            swap(s[chg],s[chg+1]);
        }
        cout<<"YES"<<nl<<s<<nl;
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