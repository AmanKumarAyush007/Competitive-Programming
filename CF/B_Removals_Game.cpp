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
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    bool check = true;
    for(int i = 0; i < n; i++){
        if(a[i]!=b[i]) check = false;
    }

    reverse(all(b));
    bool check1 = true;
    for(int i = 0; i < n; i++){
        if(a[i]!=b[i]) check1 = false;
    }

    if(check or check1) cout << "Bob" << nl;
    else cout << "Alice" << nl;
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