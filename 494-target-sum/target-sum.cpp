class Solution {
public:
    int t;
    int move(vector<int>&nums,int sum,int idx){

        
        

        if(idx<0 ){
            return sum==t;
        }

        int positive=move(nums,sum+nums[idx],idx-1);
        int negative=move(nums,sum-nums[idx],idx-1);

        return positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

            t=target;
            int n=nums.size();
            return move(nums,0,n-1);
    }
};