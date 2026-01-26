#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h" 
#else
#define debug(x...)
#endif

const int N = 2e5 + 9;
vector<vector<int>> g(N);
int n, u, v, k, l = 0;
vector<int>subtreeSize(N) , depth(N);

void dfs(int node, int par = 0) {
    depth[node] = l;
    l++;
    int subtree = 1;
    for(auto child : g[node]) {
        if(child == par) continue; 
        dfs(child, node);
        subtree += subtreeSize[child];
    }
    l--;
    subtreeSize[node] = subtree;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    vector<int>arr;
    for(int i=1; i<=n; i++) arr.push_back((subtreeSize[i]-1) - depth[i]);
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
    for(int i=1; i<=n; i++) cout << subtreeSize[i] << " ";
    cout << endl;
    for(int i=1; i<=n; i++) cout << depth[i] << " ";
    cout << endl;
    
    
    sort(arr.rbegin(), arr.rend());
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
    long long ans = accumulate(arr.begin(), arr.begin() + (n-k), 0LL);
    cout << ans ;
}