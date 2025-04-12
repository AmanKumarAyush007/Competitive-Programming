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
    vector<int> v(n);
    set<int> s;
    map<int,int> mp;
    for(int &i : v) {
        cin >> i;
        s.insert(i);
        mp[i]++;
    }
    int count = 0;
    int count3 = 0;

    // bool check = false;
    vector<int> uni(s.begin(),s.end());
    for(int &i : uni){
        if(mp[i]>=2) count++;

    }
    if(s.size() == 1) cout<<-1<<nl;
    else if(s.size() == n) cout<<-1<<nl;
    else if (v.size() <= 3) cout<<-1<<nl;
    else if(count < 2) cout<<-1<<nl;
    else {
        
        vector<int> ui;   //vector of number whose count are greater than or equal to 2
        vector<int> ind;
        vector<int> ind1;
        for(int &i : uni){
            if(mp[i]>=2) ui.pb(i); 
        }

        for(int i = 0; i < n; i++){
            if(v[i] == ui[0]) ind.pb(i);
        }

        for(int i = 0; i < n; i++){
            if(v[i] == ui[1]) ind1.pb(i);
        }
        for(int &i : v) i = 1;

        v[ind[0]] = 2;
        v[ind1[0]] = 3;

        for(int &i : v) cout<<i << " ";
        cout<<nl;

    }
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