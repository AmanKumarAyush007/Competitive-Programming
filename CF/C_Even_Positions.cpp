#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    s[0] = '(';

    stack<pair<char,int>> st;

    int ans = 0;

    for(int i = 0; i < n; i++){
        if(st.empty()) {
            if(s[i] == '_') s[i] = '(';
            st.push({s[i],i});
        }
        else {
            if(st.top().ff == '(' && s[i] == ')'){
                ans += i - st.top().ss;
                st.pop();
            }
            else if((st.top().ff == '(' && s[i] == '_' )){
                ans += i - st.top().ss;
                s[i] = ')';
                st.pop();
            }
            else {
                if(s[i] == '_') s[i] = '(';
                st.push({s[i],i});
            }
        }
    }

    cout <<ans<< nl;
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