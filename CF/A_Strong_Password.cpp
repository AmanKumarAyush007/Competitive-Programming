#include<bits/stdc++.h>
using namespace std;

#define int        long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve()
{
 
    string s;
    cin >> s;
    int n = s.size();
    char x;
    for (int i = n - 1; i >= 1; i--)
    {
 
        if (s[i] == s[i - 1])
        {
 
            for (int j = 0; j < 26; j++)
            {
 
                // cout<<char(i+'a')<<endl;
 
                if (char(j + 'a') != s[i] && char(j + 'a') != s[i - 1])
                {
                    x = char(j + 'a');
                    break;
                }
            }
 
            string ans = s.substr(0, i);
            ans.pb(x);
            ans += s.substr(i);
            cout << ans << endl;
            return;
        }
    }
 
   if(s[n-1]!='z'){
    char xx=s[n-1];
    xx++;
    s.pb(xx);
    cout<<s<<endl;
    return ;
   }
   else{
  
    s.pb('a');
    cout<<s<<endl;
    return ;
   }
 
    
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