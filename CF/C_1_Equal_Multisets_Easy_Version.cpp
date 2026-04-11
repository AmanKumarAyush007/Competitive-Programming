#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<int> freqA(n+1,0), freqB(n+1,0);

    int bad = 0;

    auto addA = [&](int x){
        freqA[x]++;
        if(freqA[x] == freqB[x]) bad--;
        if(freqA[x] == freqB[x] + 1) bad++;
    };

    auto removeA = [&](int x){
        freqA[x]--;
        if(freqA[x] == freqB[x]) bad--;
        if(freqA[x] + 1 == freqB[x]) bad++;
    };

    auto addB = [&](int x){
        if(x == -1) return;
        freqB[x]++;
        if(freqA[x] == freqB[x]) bad--;
        if(freqA[x] + 1 == freqB[x]) bad++;
    };

    auto removeB = [&](int x){
        if(x == -1) return;
        freqB[x]--;
        if(freqA[x] == freqB[x]) bad--;
        if(freqA[x] == freqB[x] + 1) bad++;
    };

    // first window
    for(int i = 0; i < k; i++){
        addA(a[i]);
        addB(b[i]);
    }

    if(bad > 0){
        cout << "NO\n";
        return;
    }

    for(int i = k; i < n; i++){
        removeA(a[i-k]);
        addA(a[i]);

        removeB(b[i-k]);
        addB(b[i]);

        if(bad > 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}