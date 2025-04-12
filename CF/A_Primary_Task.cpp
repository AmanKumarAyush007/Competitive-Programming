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
    vector<int> dig;
    while(n!=0) {
        int ele = n%10;
        n/=10;
        dig.pb(ele);
    }
    reverse(all(dig));
    int check = 1;
    if(dig.size() < 3) check = 0;
    else{
        if (dig[0] != 1)
            check = 0;
        
        if (dig[1] != 0)
            check = 0;

        if (dig.size() == 3 and dig[2] < 2)
            check = 0;

        if (dig.size() > 3 and dig[2] == 0)
            check = 0;
    }
    
    
    
    if(check) cout << "YES" ;
    else cout << "NO" ;
    cout << nl;
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