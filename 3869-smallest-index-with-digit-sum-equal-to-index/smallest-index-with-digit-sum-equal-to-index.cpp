class Solution {
public:
    int digisum(int x){
        int sum=0;
        while(x>0){
            sum+=(x%10);
            x=x/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digisum(nums[i])==i){
                return i;
            }
        }

        return -1;
    }
};