#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first       
#define ss second
#define pb push_back

ll check(vector<char> &a, vector<char> &b){
    ll count = 0;
    for(ll i = 0; i<a.size(); i++){
        char tar = a[i];
        auto it = find(b.begin(),b.end(),tar);
        if(it==b.end()) count++;   //if not found
    }
    return count;
}

ll fun(ll n){
    return n*(n+1)/2;
}

int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char> v;
    set<char> st;
    for(ll i=0; i<k; i++){
        char ele;
        cin>>ele;
        v.push_back(ele);
    }
    for(ll i = 0; i < n; i++){
        st.insert(s[i]);
    }
    vector<char> uni(st.begin(),st.end());
    // cout<< check(uni,v);

    if(check(uni,v)==0){
        cout<<fun(n);
    }
    else{
        ll count = 0;
        ll ans = 0;
        for(ll j = 0; j < s.size(); j++){
            char tar = s[j];
            auto it = find(v.begin(),v.end(),tar);
            if(it != v.end()) {count++;}
            else {
                ans += fun(count);
                count = 0;
            }
        // cout<<count<<" ";
    }
    ans += fun(count);
    cout<<ans;
    }
    return 0;
}