#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

bool check(vector<int> & v,int k, double x){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        count += v[i]/x;
    }
    if(count>=k) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int &i : v) cin>>i;

    int lp = 100;
    double l = 0, r = 1e7 + 1, mid;
    while(lp--)
    {
        mid =  l+(r-l)/2;
        if(check(v,k,mid)){
            l = mid;
        }
        else r = mid;
    }
    cout<<setprecision(7);
    cout<<r<<nl;
    
    
    
    return 0;
}