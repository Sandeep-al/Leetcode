class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

        unordered_map<int,int>mpp;

        //s[r+1]-s[l]==k
        //s[r+1]=k+s[l];
        //so insert k+ current //and later if current equals something one subarray found
        mpp[k] = 1;
        int count=0;
        for(int i=1;i<=n;i++){
            if(mpp.find(prefix[i])!=mpp.end()){
                count+=mpp[prefix[i]];
            }

            mpp[prefix[i]+k]++;
        }

        return count;
    }
};