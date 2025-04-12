#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_ back
#define endl '\n'

void solve(){
    string s;
    cin>>s;
    set<char> uni;
    for(int i = 0 ; i< s.size(); i++){
        uni.insert(s[i]);
    }
    if(uni.size()==1) cout<<"NO"<<endl;
    else{
        vector<char> v(uni.begin(),uni.end());
        std::string::size_type index0 = s.find(v[0]);
        std::string::size_type index1 = s.find(v[1]);
        s[index0]=v[1];
        s[index1]=v[0];
        cout<<"YES"<<endl;
        cout<<s<<endl;
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