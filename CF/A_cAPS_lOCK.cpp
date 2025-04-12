#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string str;
    cin >> str;
    str[0] = toupper(str[0]);
    for(int i = 1; i < str.size(); i++){
        str[i] = tolower(str[i]);
    }
    cout << str << nl;
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