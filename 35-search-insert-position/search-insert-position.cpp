class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=-1;
        int hi=n;

        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target) hi=mid;
            else lo=mid;
        }

        

        return hi;
    }
};