class Solution {
public:
    bool can(vector<int>& arr, int idx,vector<int>&dp){
        if(idx>arr.size()-1 || idx<0) return false;
        
        if(arr[idx]==0) return true;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        dp[idx]=0;
        bool left=can(arr,idx-arr[idx],dp);
        bool right=can(arr,idx+arr[idx],dp);

        return dp[idx]=left||right;
    }
    bool canReach(vector<int>& arr, int start) {

            vector<int>dp(arr.size()+1,-1);
            return can(arr,start,dp);
    
    
    
    
    
    
    
    }

};