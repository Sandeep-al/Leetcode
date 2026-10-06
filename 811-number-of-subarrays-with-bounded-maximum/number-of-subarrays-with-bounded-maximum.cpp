class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n=nums.size();
        int l=0;
        int count=0;
        for(int r=0;r<n;r++){

            if(nums[r]>k){
                l=r+1;
            }

            count+=r-l+1;
        }

        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums,right)-solve(nums,left-1);
    }
};