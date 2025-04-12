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
    vector<int> p(n+1);
    vector<bool> visit(n+1,false);
    vector<int> result(n+1,0);


    p[0] = -1;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    string s; cin >> s;

    for(int i = 1; i <= n; i++){

        vector<int> cycle;

        int curr = i;
        while(!visit[curr]){
            visit[curr] = true;
            cycle.pb(curr);
            curr = p[curr];
        }

        int blck = 0;
        for(auto indx : cycle){
            if(s[indx-1] == '0') blck++;
        }

        for(auto &i : cycle) result[i] = blck;

    }

    for(int i = 1; i <= n; i++){
        cout << result[i] << " ";
    }
    

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