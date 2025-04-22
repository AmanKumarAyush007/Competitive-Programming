#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define inf        LLONG_MAX
#define hell       LLONG_MIN
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()
#define sm(v)      accumulate(all(v),0LL)
#define inp(v)     for(auto& x : v) cin >> x;
#define setbit(x)  __builtin_popcountll(x)

map<int,int> mp;
map<int,int> used;
int val;

void interact(int i){
    cout << i << nl;
    used[i] = 1;
    return;
}

void ok(int turn,vector<int> &v){
    if(turn == 2){
        cin >> val;
        used[val] = 1;
        return;
    }
    if(val > 0 && mp[val] > 0 && !used[val]){
        interact(mp[val]);
        used[val] = 1;
        return;
    }

    int maxi = 0, maxP = 0;
    for(int i = 1; i < v.size(); i++){
        if(used[i]) continue;
        if(v[i] > v[maxi]) maxi = i;
        if(mp[i] && v[i] > v[maxP]) maxP = i;
    } 
    
    if(maxP > 0) interact(maxP);
    else interact(maxi);
    return;

}


void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(2*n + 1);
    for(int i = 1; i < 2*n + 1; i++){
        cin >> v[i];
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        mp[a] = b;
        mp[b] = a;
    }

    int chance;
    cin >> chance;

    for(int i = 1; i <= 2*n; i++){
        ok(chance,v);
        chance = 3 - chance;
    }    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}