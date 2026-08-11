class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]==nums[i-1]+1){
                maxi+=nums[i];
            }
            else{
                break;
            }
        }

        unordered_set<int>mpp;
        for(auto &it:nums){
            mpp.insert(it);
        }

        for(int i=maxi;i<=2501;i++){
            if(mpp.find(i)==mpp.end()){
                return i;
            }
        }

        return -1;
    }
};