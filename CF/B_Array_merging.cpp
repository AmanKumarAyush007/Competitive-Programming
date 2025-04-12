#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define map        unordered_map
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int n;
    cin >> n;
    int a[n],b[n];

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;


    map<int,int> mx2,mx1,mp1,mp2;

    
    for(auto &i : a) mp1[i] = 1,mx1[i] = 1;
    for(auto &i : b) mp2[i] = 1,mx2[i] = 1;


    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]) mp1[a[i]]++;
        else mp1[a[i]] = 1;
        mx1[a[i]] = max(mx1[a[i]],mp1[a[i]]);

        if(b[i] == b[i+1]) mp2[b[i]]++;
        else mp2[b[i]] = 1;
        mx2[b[i]] = max(mx2[b[i]],mp2[b[i]]);
    }


    int ans = 1;
    
    for(auto &[a,b] : mx1) {
        int tmp = 0;
        if(mx2.find(a) != mx2.end())  tmp = b + mx2[a];
        else tmp = b;
        ans = max(tmp,ans);
    }
    for(auto &[a,b] : mx2) {
        ans = max(ans,b);
    }

    cout << ans << nl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}