#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define fr first
#define sc second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define pb push_back
#define ppb pop_back
#define inp(v) for(auto& x : v) cin >> x;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(v) (v).begin(),(v).end()
#define nl         '\n'

 
template<typename T, typename U>
T& amax(T& x, U y) {if(y > x) x = y; return x;}
template<typename T, typename U>
T& amin(T& x, U y) {if(y < x) x = y; return x;}


int test(int n, string s)
{
    int ans = n;
    string t = string("0") + s;
    rep(i,0,n)
    {
        ans += t[i] != t[i + 1];
    }
 
 
    int x = 0, y = 0, z = 0;
    while(x < n && s[x] != '1') x++;
    y = x;
    while(y < n && s[y] != '0') y++;
    z = y;
    while(z < n && s[z] == '0') z++;
 
    if(x < n)
    {
        // 1 found
        if(y < n)
        {
            // 0 found after 1
            if(z < n)
            {
                // 111..1100..001.. found
                ans -= 2;
            }
            else
            {
                // 1111....0000000...
                ans -= 1;
            }
        }
        else
        {
            // 1111111...
        }
    }
    else
    {
        // 00000000
    }
 
    // cout << ans << "\n";
    return ans;
}


int solve(int n, string s){
    

    set<char> st;
    for(auto &i : s)st.insert(i);

    if(st.size() == 1) {
        return n + (s[0] == '1');
    }

    int val = 0;
    if(s[0] == '1') val = 2;
    else val = 1;

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) val++;
        else val += 2;
    }

    vector<int> o,z;

    for(int i = 0; i < n; i++){
        if(s[i] == '0') z.pb(i);
        else o.pb(i); 
    }

    z.pb(-1);

    sort(all(o));
    sort(all(z));


    for(int i = 0; i < o.size(); i++){
        if(z.size() < 2) break;

        if((z[z.size() - 1] != n-1 && o[i] > z[0] && o[i] < z[z.size() - 1]) || (z.size() >= 3 && o[i] > z[0] && o[i] < z[z.size() - 2])){    
            return val - 2;
        }
    }


    for(int i = 0; i < z.size(); i++){
        if(o.size() < 2) break;

        if((o[o.size() - 1] != n-1 && z[i] > o[0] && z[i] < o[o.size() - 1]) || (o.size() >= 3 && z[i] > o[0] && z[i] < o[o.size() - 2])){
            return val - 2;
        }
    }

    if((s[0] == '1' && o[o.size()-1] == n-1) || (s[0] == '0' && z[z.size()-1] == n-1) || (s[0] == '1' && z.size() >= 1)) val--;

    return val;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(NULL));

    int t = 1000;
    // cin >> t;
    while(t--){
        int n = (rand() % 10) + 1;
        string s;
        for(int i = 0; i < n; i++){
            int x = rand() % 2;
            s += (x + '0');
        }
        // cout << s << nl;
        if(solve(n,s) != test(n,s)){
            cout << n << " " << s << nl;
            cout << test(n,s) << " " << solve(n,s);
            break;
        }
    }
    return 0;
}