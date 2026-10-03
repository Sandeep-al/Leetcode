class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>mini+k){
                //this element is seperate
                count++;
                mini=nums[i];
            }
        }

        return count+1;
    }
};