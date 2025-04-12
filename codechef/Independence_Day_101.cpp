#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

void solve(){
    int a[3];
    int  sum = 0;
	for(auto &i : a){
        cin >> i;
        sum += i;
    }
	sort(a,a+3);
	int diff = sum - a[2];
	if(a[2] <= diff+1) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}