#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;
    int  n = s.size();
    if(n == 2) cout << s << nl;
    else{
        vector<char> v,v1;
        for(int i = 0; i < n-1; i++){
            v.pb(s[i]);
        }
        sort(all(v));
        char ch1 = v[0];
        int indx = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == ch1) {
                indx = i;
                break;
            }
        }
        for(int i = indx+1; i < n; i++){
            v1.pb(s[i]);
        }
        sort(all(v1));

        cout <<ch1<<v1[0]<< nl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}