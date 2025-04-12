#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back



int main(){
    int n;
    cin>>n;
    ll t[n];
    ll sum = 0;
    for(int i = 0; i<n; i++){
        cin>>t[i];
        sum+=t[i];
    }
    cout<<sum;
    return 0;
}