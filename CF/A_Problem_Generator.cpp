#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n,m;
    cin>>n>>m;
    char a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    map<char,int> mp;
    mp['A'] = 0;
    mp['B'] = 0;
    mp['C'] = 0;
    mp['D'] = 0;
    mp['E'] = 0;
    mp['F'] = 0;
    mp['G'] = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 'A') mp['A']++;
        else if(a[i] == 'A') mp['A']++;
        else if(a[i] == 'B') mp['B']++;
        else if(a[i] == 'C') mp['C']++;
        else if(a[i] == 'D') mp['D']++;
        else if(a[i] == 'E') mp['E']++;
        else if(a[i] == 'F') mp['F']++;
        else if(a[i] == 'G') mp['G']++;
    }
    int ans = 0;
    if(mp['A']<m){
        ans += m - mp['A'];
    }
    if(mp['B']<m){
        ans += m - mp['B'];
    } 
    if(mp['C']<m){
        ans += m - mp['C'];
    }
    if(mp['D']<m){
        ans += m - mp['D'];
    } 
    if(mp['E']<m){
        ans += m - mp['E'];
    }
    if(mp['F']<m){
        ans += m - mp['F'];
    }
    if(mp['G']<m){
        ans += m - mp['G'];
    }
    cout<<ans<<nl;
        
    
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