class Solution {
public:
    int tell(vector<int>&nums, int idx){
        //is this index > peaks index
        int n=nums.size();
        long long next= (idx==n-1)?LLONG_MIN:nums[idx+1];
        long long prev= (idx==0)?LLONG_MIN:nums[idx-1];

        if(nums[idx]>=next && prev>=nums[idx]){
            return 1;
        }

        return 0;
        
    }
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        int lo=-1;
        int hi=n;

        while(hi-lo>1){
            int mid=(hi-lo)/2+lo;

            if(tell(nums,mid)){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }

        return lo;
    }
};