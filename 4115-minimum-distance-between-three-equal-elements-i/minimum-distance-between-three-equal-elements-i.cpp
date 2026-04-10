class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                for(int k=0;k<nums.size();k++){
                    if(i==j || j==k || i==k) continue;
                    if((nums[i]==nums[j]) && (nums[j]==nums[k])){
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};