#include<bits/stdc++.h>
using namespace std;

#define int        int64_t
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()


string f( vector<vector<char>>& grid, int i) {
    int n = grid.size();
    int m = grid[0].size();
    if (i >= min(n, m) / 2) {
        return "";
    }
    
    string res;
    int startR = i;
    int startC = i;
    int endR = n - 1 - i;
    int endC = m - 1 - i;
    

    for (int j = startC; j <= endC; j++) {
        res += grid[startR][j];
    }
    
    for (int i = startR + 1; i <= endR; i++) {
        res += grid[i][endC];
    }
    

    if (startR != endR) {
        for (int j = endC - 1; j >= startC; j--) {
            res += grid[endR][j];
        }
    }
    

    if (startC != endC) {
        for (int i = endR - 1; i > startR; i--) {
            res += grid[i][startC];
        }
    }
    
    return res;
}


int g(string layer) {
    string pattern = "1543";
    if (layer.empty()) {
        return 0;
    }

    string doubled = layer + layer;    //wrap around ko tackle karne ke liye
    int count = 0;
    
    for (int i = 0; i < layer.length(); i++) {
        if (doubled.substr(i, pattern.length()) == pattern) {
            count++;
        }
    }
    
    return count;
}


int solve(int n, int m,  vector<vector<char>>& grid) {
    int ans = 0;
    int layersCnt = min(n, m) / 2;
    
    for (int i = 0; i < layersCnt; i++) {
        string layer = f(grid, i);
        ans += g(layer);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        
        cout << solve(n, m, grid) << nl;
    }
    
    return 0;
}