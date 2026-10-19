class Solution {
public:
    string triangleType(vector<int>& nums) {

        bool istriangle=true;

        if(nums[0]+nums[1]<=nums[2]){
            istriangle=false;
        }
        else if(nums[1]+nums[2]<=nums[0]){
            istriangle=false;
        }
        else if(nums[0]+nums[2]<=nums[1]){
            istriangle=false;
        }

        if(!istriangle){
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[0] == nums[2] ||
                   nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};