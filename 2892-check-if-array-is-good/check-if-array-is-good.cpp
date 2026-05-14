class Solution {
public:
    bool isGood(vector<int>& nums) {
        int x=nums.size();
        sort(nums.begin(),nums.end());
        int n=x-1;
        int z=1;
        for(int i=0;i<x-1;i++){
            if(nums[i]!=z) return false;
            z++;

        }

        if(nums[x-1]!=x-1) return false;

        return true;
    }
};