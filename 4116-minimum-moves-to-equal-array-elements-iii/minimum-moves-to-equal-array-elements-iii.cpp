class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans{0};
        int maxi=*max_element(nums.begin(),nums.end());
        for(auto& it:nums){
            ans+=(maxi-it);
        }
        return ans;
    }
};