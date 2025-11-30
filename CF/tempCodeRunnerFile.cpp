#include <bits/stdc++.h>
using namespace std;

int curr = 0;
int n,m;
int sx,sy,ex,ey;

void dfs(int x, int y, int dx, int dy, vector<vector<bool>> &vis){
    cerr << x << y;
    
    vis[x][y] = 1;
    
    int diffx = (x == 1 ? n - x : x - 1);
    int diffy = (y == 1 ? n-y : y - 1);
    
    int nx = x + dx*(min(diffx,diffy));
    int ny = y + dy*(min(diffx,diffy));
    
    if(vis[nx][ny]) {
        curr = -1;
        return;
    }
    
    
    int p = x, q = y;
    
    while(p != nx && q != ny){
        if(p == ex && q == ey) return;
        p += dx;
        q += dy;
    }
    
    
    
    if(x == n && y == m) dfs(nx,ny,-dx,-dy,vis);
    else if(x == n && y == 1) dfs(nx,ny,-dx,-dy,vis);
    else if(x == 1 && y == m) dfs(nx,ny,-dx,-dy,vis);
    else if(x == 1 && y == 1) dfs(nx,ny,-dx,-dy,vis);
    else{
        if(diffx <= diffy) dfs(nx,ny,-dx,dy,vis);
        else dfs(nx,ny,dx,-dy,vis);
    }
    
    if(curr != -1) curr++;
    
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    cin >> n >> m;
	    cin >> sx >> sy >> ex >> ey;
	    
	    string s;
	    cin >> s;
	    
	    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
        
        if(s == "DR") dfs(sx,sy,-1,1,vis);
        else if(s == "DL") dfs(sx,sy,-1,-1,vis);
        else if(s == "UR") dfs(sx,sy,1,1,vis);
        else dfs(sx,sy,1,-1,vis);
	   
	   
	   cout << curr;
	    
	}

}



