class Solution {
public:
    int search(vector<int>& nums, int target) {
        // invariant is element>=target

        int n=nums.size();
        int lo=-1;
        int hi=n;

        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target) hi=mid;
            else lo=mid;
        }

        if(hi==n || nums[hi]!=target){
            return -1;
        }

        return hi;
    }
};