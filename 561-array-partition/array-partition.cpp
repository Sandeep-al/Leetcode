class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        long long sum=0;
        sort(begin(nums), end(nums));
        for(int i=0; i<nums.size(); i++){
            if(i%2==0) sum+=nums[i];
        }
        return sum;
    }
};