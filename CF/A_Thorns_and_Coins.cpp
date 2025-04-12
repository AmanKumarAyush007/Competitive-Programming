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
    char a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int indx = n;
    for(int i = 0; i < n; i++){
        if(a[i] == '*' && a[i+1] == '*'){
            indx = i;
            break;
        }
    }
    int ans = 0;
    for(int i = 0; i < indx; i++){
        if(a[i] == '@') ans++;
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