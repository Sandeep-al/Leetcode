class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        k=k-1;
        int mini=INT_MAX;
        int i=0;
        while(k<n){
            mini=min(nums[k]-nums[i],mini);
            i++;
            k++;
        }

        return mini;
    }
};