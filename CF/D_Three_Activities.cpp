#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int maxSum(vector<pair<int,int>> &A, vector<pair<int,int>> &B, vector<pair<int,int>> &C){
    int n = A.size();
    int ans1 = A[n-1].ff;
    int ind1 = A[n-1].ss,ind2 = B[n-1].ss;

    if(B[n-1].ss != A[n-1].ss){
        ans1 += B[n-1].ff;
        // cout<<-1<<nl<<nl;
    }else{
        ans1 += B[n-2].ff;
        ind2 = B[n-2].ss;
    } 
    if(C[n-1].ss != ind1 and C[n-1].ss != ind2) {
        ans1 += C[n-1].ff;
        // cout<<-1<<nl<<nl;
        
    }
    else if (C[n-2].ss != ind1 and C[n-2].ss != ind2){
        ans1 += C[n-2].ff;
        // cout<<-2<<nl<<nl;

    } 
    else {
        ans1 += C[n-3].ff;
        // cout<<-3<<nl<<nl;

    }
    return ans1;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);

    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int &i : c) cin >> i;

    vector<pair<int,int>> A(n),B(n),C(n);
    for(int i = 0; i < n; i++){
        A[i] = {a[i],i};
        B[i] = {b[i],i};
        C[i] = {c[i],i};
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));    
    // for(auto [a,b] : A){
    //     cout << a << " " << b << nl;
    // }
    
    int ans = maxSum(A,B,C);
    ans = max(ans,maxSum(A,C,B));
    ans = max(ans,maxSum(B,C,A));
    ans = max(ans,maxSum(B,A,C));
    ans = max(ans,maxSum(C,B,A));
    ans = max(ans,maxSum(C,A,B));

    
    cout<<ans<<nl;

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