class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto &it:nums){
            mpp[it]++;
        }

        for(auto &it:nums){
            if(mpp[it]==1 && it%2==0){
                return it;
            }
        }

        return -1;
    }
};