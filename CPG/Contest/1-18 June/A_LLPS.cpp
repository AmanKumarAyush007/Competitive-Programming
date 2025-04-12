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
    cin>>s;
    char ch = 'a';
    for(int i = 0; i < s.size(); i++){
        if(s[i] > ch) ch = s[i];
    }
    int sz = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ch) sz++;
    }
    string str(sz,ch);
    cout<<str;
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