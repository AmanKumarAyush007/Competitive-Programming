#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s ;
    cin >> s;
    int sz = s.size();
    int n;
    cin >> n;
    // bool ck = true;

    if(s.size() < 4) {
        while (n--)
        {
            int x;
            char y;
            cin >> x;
            cin >> y;
            cout << "NO" << nl;
        }
        return;
    }

    set<int> v;

    for(int i = 0; i < s.size()-3; i++){
        if(s[i] == s[i+1] && s[i] == '1' && s[i+2] == '0' && s[i+2]== s[i+3]) v.insert(i);
    }
    // cout << v.size();


    while(n--){
        int x;
        char y;
        cin >> x;
        cin >> y;
        int ind = x-1;
        s[ind] = y;
        int st = max(0LL,ind-3);
        int end = min(sz-4,ind+3);
        // cout << s << " ->" << st << " , " << end << nl;

        for(int i = st; i <= end; i++){
            if(s[i] == s[i+1] && s[i] == '1' && s[i+2] == '0' && s[i+2]== s[i+3]) v.insert(i);
            else{
                auto it = v.find(i);
                if(it != v.end()) v.erase(it);
            }
        }

        if(v.size()) {
            cout << "YES" <<nl;
        }
        else cout << "NO" << nl;
    }
    
    // cout << nl;
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