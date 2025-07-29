#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ff first
#define ss second
#define pb push_back
#define inf LLONG_MAX
#define hell LLONG_MIN
#define nl '\n'
#define all(a) (a).begin(), (a).end()
#define sm(v) accumulate(all(v), 0LL)
#define inp(v)        \
    for (auto &x : v) \
        cin >> x;
#define setbit(x) __builtin_popcountll(x)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

map<int, vector<int>> fac;

void countFactors(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            fac[j].push_back(i);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> po = fac[n];

    debug(po);


    for (auto &x : po)
    {
        map<string,int> mp;
        int len = x;
        string k;
        for (int i = 0; i < len; i++)
        {
            k += s[i];
        }
        // debug(k);
        set <string> st;
        st.insert(k);
        mp[k]++;

        string p;


        for(int i = len; i < n; i += len){
            for(int j = i; j < i+len; j++){
                p += s[j];
            }
            debug(p);
            st.insert(p);
            mp[p]++;
            p = "";
        }


        if(st.size() == 1) {
            cout << len << nl;
            return;
        }
        if(st.size() == 2){
            string sp = *st.begin();
            string sl = *st.rbegin();
            int cnt = 0;
            for(int i = 0; i < sp.size(); i++){
                if(cnt > 1) break;
                if(sp[i] != sl[i]) cnt++;
            }
            if(cnt <= 1 && (mp[sp] == 1 || mp[sl] == 1)){
                cout << len << nl;
                return;
            }
        }
    }

    cout << n << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    countFactors(200005);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}