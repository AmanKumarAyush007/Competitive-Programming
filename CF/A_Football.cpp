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
    // *** PROBLEM 96A ***              
    // string s;
    // cin >> s;
    // int count = 1,max_cnt = 0;
    // for(int i = 0; i < s.size(); i++){
    //     if(s[i] == s[i+1]) count++;
    //     else count = 1;
    //     max_cnt = max(max_cnt,count);
    // }
    // if(max_cnt >= 7) cout << "YES" << nl;
    // else cout << "NO" << nl;

    // *** PROBLEM 43A ***
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string ele;
        cin >> ele;
        mp[ele]++;
    }

    vector<pair<int, string>> st;

    for (auto &[a, b] : mp) st.pb({b, a});
        
    sort(all(st));
    
    cout << st[st.size() - 1].ss << nl;

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