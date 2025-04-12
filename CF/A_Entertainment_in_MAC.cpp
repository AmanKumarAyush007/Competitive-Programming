#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int check = 0;
    for(int i = 0; i < n/2; i++){
        if(s[i]<s[n-1-i]){
            string o = s;
            reverse(s.begin(), s.end());
            s.append(o);
            cout<<s<<endl;
            check = 1;
            break;
        }
        else continue;
    }
    if(check == 0) cout<<s<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}