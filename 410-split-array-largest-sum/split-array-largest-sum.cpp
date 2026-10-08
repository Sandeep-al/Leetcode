class Solution {
public:
    int tell_splits(vector<int>&nums,int max_sum){
        int curr_sum=0;
        int total=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_sum){
                return INT_MAX;
            }

            if(nums[i]+curr_sum>max_sum){
                total++;
                curr_sum=nums[i];
            }
            else{
                curr_sum+=nums[i];
            }
        }

        return total;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo=-1;
        int hi=INT_MAX-1;

        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;

            if(tell_splits(nums,mid)<=k){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }

        return hi;
    }
};