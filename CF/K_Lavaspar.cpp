#include<bits/stdc++.h>
using namespace std;

#define int              int64_t
#define ff               first
#define ss               second
#define pb               push_back
#define inf              LLONG_MAX
#define hell             LLONG_MIN
#define nl               '\n'
#define all(a)           (a).begin(),(a).end()
#define rall(a)          (a).rbegin(),(a).rend()
#define sm(v)            accumulate(all(v),0LL)
#define inp(v)           for(auto& x : v) cin >> x;
#define setbit(x)        __builtin_popcountll(x)
#define lg(x)            (63 - __builtin_clzll(x)) //log base 2
#define prefixsum(a)     partial_sum(all(a), (a).begin());
#define suffixsum(a)     partial_sum(rall(a), (a).rbegin());


#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
  #define debug(x...)
#endif


bool chk(const multiset<char>& s, const multiset<char>& wset) {
    return s == wset;
}

void find(const vector<vector<int>>& ans, const vector<vector<char>>& a, const string& w) {
    int n = a.size(), m = a[0].size();
    int l = w.length();

    vector<vector<int>> tans(n, vector<int>(m, 0));
    multiset<char> wset(w.begin(), w.end());

    vector<vector<bool>> mp(n, vector<bool>(m, 0));
    vector<vector<bool>> mpu(n, vector<bool>(m, 0));
    vector<vector<bool>> mpd(n, vector<bool>(m, 0));
    vector<vector<bool>> mpd2(n, vector<bool>(m, 0));


    for (int i = 0; i < n; i++) {
        multiset<char> sl;
        for (int j = 0; j < m; j++) {
            sl.insert(a[i][j]);
            if (j >= l) sl.erase(sl.find(a[i][j - l]));
            if (j + 1 >= l && chk(sl, wset)) {
                for (int k = j; k > j - l; k--) {
                    if (!mp[i][k]) {
                        mp[i][k] = 1;
                        tans[i][k] = 1;
                    } else break;
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        multiset<char> su;
        for (int i = 0; i < n; i++) {
            su.insert(a[i][j]);
            if (i >= l) su.erase(su.find(a[i - l][j]));
            if (i + 1 >= l && chk(su, wset)) {
                for (int k = i; k > i - l; k--) {
                    if (!mpu[k][j]) {
                        mpu[k][j] = 1;
                        tans[k][j] = 1;
                    } else break;
                }
            }
        }
    }

    for (int row = 0; row < n; row++) {
        multiset<char> sd;
        int i = row, j = 0;
        while (i < n && j < m) {
            sd.insert(a[i][j]);
            if ((int)sd.size() > l) sd.erase(sd.find(a[i - l][j - l]));
            if ((int)sd.size() == l && chk(sd, wset)) {
                int p = i, q = j;
                for (int k = 0; k < l; k++) {
                    if (!mpd[p][q]) {
                        mpd[p][q] = 1;
                        tans[p][q] = 1;
                    } else break;
                    p--, q--;
                }
            }
            i++, j++;
        }
    }
    for (int col = 1; col < m; col++) {
        multiset<char> sd;
        int i = 0, j = col;
        while (i < n && j < m) {
            sd.insert(a[i][j]);
            if ((int)sd.size() > l) sd.erase(sd.find(a[i - l][j - l]));
            if ((int)sd.size() == l && chk(sd, wset)) {
                int p = i, q = j;
                for (int k = 0; k < l; k++) {
                    if (!mpd[p][q]) {
                        mpd[p][q] = 1;
                        tans[p][q] = 1;
                    } else break;
                    p--, q--;
                }
            }
            i++, j++;
        }
    }

    for (int row = 0; row < n; row++) {
        multiset<char> sd;
        int i = row, j = m - 1;
        while (i < n && j >= 0) {
            sd.insert(a[i][j]);
            if ((int)sd.size() > l) sd.erase(sd.find(a[i - l][j + l]));
            if ((int)sd.size() == l && chk(sd, wset)) {
                int p = i, q = j;
                for (int k = 0; k < l; k++) {
                    if (!mpd2[p][q]) {
                        mpd2[p][q] = 1;
                        tans[p][q] = 1;
                    } else break;
                    p--, q++;
                }
            }
            i++, j--;
        }
    }
    for (int col = m - 2; col >= 0; col--) {
        multiset<char> sd;
        int i = 0, j = col;
        while (i < n && j >= 0) {
            sd.insert(a[i][j]);
            if ((int)sd.size() > l) sd.erase(sd.find(a[i - l][j + l]));
            if ((int)sd.size() == l && chk(sd, wset)) {
                int p = i, q = j;
                for (int k = 0; k < l; k++) {
                    if (!mpd2[p][q]) {
                        mpd2[p][q] = 1;
                        tans[p][q] = 1;
                    } else break;
                    p--, q++;
                }
            }
            i++, j--;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[i][j] += tans[i][j];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> ans(n, vector<int>(m, 0));

    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        string s;
        cin >> s;
        find(ans, a, s);
    }

    int z = 0;
   for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { 
    if (ans[i][j] > 1)
     { z++; } 
}
  }
    cout << z << endl;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}