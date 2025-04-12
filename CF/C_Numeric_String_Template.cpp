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
    set<int> st;

    vector<int> v(n);
    for(auto &i : v) {
        cin >> i;
        st.insert(i);
    }
    bool check  = true;

    if(st.size() > 26 ) check = false;

    map<int,vector<int>> mp;

    for (int i = 0; i < n; ++i) {
        mp[v[i]].push_back(i); // Store the index in the vector corresponding to the number
    }

    



    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(st.size() != s.size()){
             check = false;
             break;
        }
        else
        {
            for (auto &pair : mp)
            {
                for (int index : pair.second)
                {
                    char k = s[index];
                }
                cout << endl;
            }
        }
    }

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