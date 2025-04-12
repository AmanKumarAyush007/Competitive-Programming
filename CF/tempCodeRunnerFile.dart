#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+2);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n+1; i++){
        cin >> b[i];
    }
    bool check=false;
    bool btw=false;
    int diff=INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i] == b[n] || b[i]==b[n]) check=true;
        if((b[n]>a[i] && b[n]<b[i])  || (b[n]<a[i] && b[n]>b[i])) btw=true;
         diff=min({diff, abs(b[n]-a[i]), abs(b[n]-b[i])});
    }
    long long move=1;
    if(check || !check && btw){
        for(int i=0;i<n;i++){
            move += abs(a[i]-b[i]);
        }
    }
    else{
        for(int i=0;i<n;i++){
            move += abs(a[i]-b[i]);
        }
        move += diff;
    }
    cout<<move << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
