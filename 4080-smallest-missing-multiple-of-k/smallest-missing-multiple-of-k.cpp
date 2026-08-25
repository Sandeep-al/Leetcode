class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int i=k;
        int ans=-1;
        while(true){
            if(mpp.find(i)==mpp.end()){
                ans=i;
                break;
            }

            i+=k;
        }

        return ans;
    }
};