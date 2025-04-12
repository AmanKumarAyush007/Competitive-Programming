#include<bits/stdc++.h>
using namespace std;

// #define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s,t;
    cin >> s >> t;
    vector<bool> check(s.size(),false);
    unordered_map<char,int> mp;
    if(s == t) cout << "YES";
    else if(t.size() == s.size()) cout << "NO";
    else if(t.size() > s.size()) cout << "NO";
    else{
        for(auto &i : t) mp[i]++;

        reverse(all(s));

        string st1 = s;



        bool flag = true;

        for(auto &[a,b] : mp){
            while(b--){
                size_t it = s.find(a);
                if(it == string::npos){
                    cout << "NO" << nl;
                    flag = false;
                    return;
                }
                else {
                    check[it] = true;
                    s[it] = '!';
                }
            }
        }


        if(flag){
            string st;
            for(int i = 0; i < check.size(); i++){
                if(check[i] == true) st += st1[i];
            }
            reverse(all(t));
            if(st == t) cout << "YES";
            else cout << "NO";
        }
    }

    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}