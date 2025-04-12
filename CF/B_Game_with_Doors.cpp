#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int a,b,c,d;
    cin >> a >> b >> c>>d;
    vector<int> v(102,0);
    for(int i = a; i <= b; i++){
        v[i]++;
    }
    for(int i = c; i <= d; i++){
        v[i]++;
    }
    
    bool check = true;
    for(int i = 1; i <= 100; i++){
        if(v[i] == 2){
            check = false;
            break;
        }  
    }

    if(check) cout << 1;
    else{
        int ans = 0;
        for (int i = 0; i < 101; i++)
        {
            if (v[i] == 2 && v[i] == v[i + 1])
                ans++;
            else if (v[i] == 1 && v[i + 1] == 2)
                ans++;
            else if (v[i] == 2 && v[i + 1] == 1)
                ans++;
        }
        cout << ans;
    }


    
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}