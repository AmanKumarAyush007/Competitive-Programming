#include<bits/stdc++.h>
using namespace std;


bool check(int n, int x, int y, int mid){
    if(n <= mid/x + mid/y) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y;
    cin >> n >> x >> y;
    int time = min(x,y); //to print one more copy;
    n--;
    int l = 0, h = 1000000009,mid;
    int et;
    while(h>=l){
        mid = (l+h)/2;
        if(check(n,x,y,mid)){
            h = mid-1;
            et = mid;
            // cout<<et<<" ";
        }
        else l = mid + 1; 

    }
    cout<<et+time<<endl;
    
    return 0;
}