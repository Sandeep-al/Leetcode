class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1 = 0;
        int count2 = 0;

        int can1 = 0;
        int can2 = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == can1) {
                count1++;
            } else if (nums[i] == can2) {
                count2++;
            } else if (count1 == 0) {
                can1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                can2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1=0;
        count2=0;
        vector<int>ans;
        for(auto &it:nums){
            if(it==can1) count1++;
        }
        for(auto &it:nums){
            if(it==can2) count2++;
        }

        if(count1>(n/3)){
            ans.push_back(can1);
        }

        if(count2>(n/3) && can1!=can2){
            ans.push_back(can2);
        }

        return ans;
    }
};