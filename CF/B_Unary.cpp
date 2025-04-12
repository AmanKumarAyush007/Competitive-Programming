#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    string s;
    cin >> s;

    unordered_map<char, string> mp= {  {'>', "1000"}, {'<', "1001"}, {'+', "1010"}, {'-', "1011"},
        {'.', "1100"}, {',', "1101"}, {'[', "1110"}, {']', "1111"}  
    };


    string bin_str;

    for(auto &i : s) bin_str += mp[i];

    ll sum = 0;
    int n = bin_str.size();
    ll x = 1;

    reverse(all(bin_str));
    for(int i = 0; i < n; i++){
        sum += x*(bin_str[i]-'0');
        x = (x*2)%1000003;
        sum = sum%1000003;
    }
    cout << sum << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}