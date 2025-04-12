#include<bits/stdc++.h>
using namespace std;

#define ll         long long
#define ff         first
#define ss         second
#define pb         push_back
#define nl         '\n'
#define all(a)     (a).begin(),(a).end()

int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre;
        int presum = 0;
        for(int i = 0; i < n; i++){
            int presum = 0;
            presum += nums[i];
            auto temp = max_element(pre.begin(),pre.end());
            if(temp == pre.end()){
                pre.pb(presum);
            }
            else{
                if(presum > *temp) pre.pb(presum);
            }
            
            for(int j = i+1; j < n; j++){
                presum += nums[j];
                int temp1 = *max_element(pre.begin(),pre.end());
                if(presum > temp1) pre.pb(presum);
            }
        }
       
        int ans = *max_element(pre.begin(),pre.end());
        return ans;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums(5);
    for(int i = 0; i<5; i++){
        cin>>nums[i];
    }
    cout<<maxSubArray(nums);
    return 0;
}