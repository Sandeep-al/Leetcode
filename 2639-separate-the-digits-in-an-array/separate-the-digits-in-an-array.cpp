class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &it:nums){
            int num=it;
            vector<int>temp;
            while(num!=0){
                temp.push_back(num%10);
                num=num/10;
            }
            int x=temp.size()-1;
            while(x>=0){
                ans.push_back(temp[x]);
                x--;
            }
        }

        return ans;
    }
};