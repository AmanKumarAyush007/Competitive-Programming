#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

bool check(char o, char c){
    if(o == '<' && c == '>') return false;
    if(o == '(' && c == ')') return false;
    if(o == '{' && c == '}') return false;
    if(o == '[' && c == ']') return false;
    
    return true;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(s[i]);
        else{
            char o,c;
            if(st.top() == '<' || st.top() == '{' || st.top() == '(' || st.top() == '['){
                o = st.top();
            }
            else o = 'n';
            if(s[i] == '>' || s[i] == '}' || s[i] == ')' || s[i] == ']'){
                c = s[i];
            }
            else c = 'n';

            if(o == 'n' or c == 'n') st.push(s[i]);
            else {
                if(check(o,c)) {
                    ans++;
                }
                st.pop();
            }
        }
    }
    if(st.size() != 0) cout <<"Impossible";
    else cout <<  ans;
    cout << nl;
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