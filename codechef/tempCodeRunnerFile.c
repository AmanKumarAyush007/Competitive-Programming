#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define endl       '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int x;
    cin>>x;
    string s;
    cin>>s;
    for(int i = 0; i < x; i++){
        if(s[i]==s[i+1]) x--;
    }
    cout<<x<<endl;
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