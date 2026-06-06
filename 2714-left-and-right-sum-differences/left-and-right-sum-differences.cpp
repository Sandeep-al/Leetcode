class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n);
        vector<int>rightsum(n);

        int left=0;
        for(int i=0;i<n;i++){
            leftsum[i]=left;
            left+=nums[i];
        }

        int right=0;
        for(int i=n-1;i>=0;i--){
            rightsum[i]=right;
            right+=nums[i];
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }

        return ans;
    }
};