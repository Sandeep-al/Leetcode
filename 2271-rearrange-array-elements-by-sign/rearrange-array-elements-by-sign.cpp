class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        
        for(auto &it:nums){
            if(it>0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        int n=pos.size();
        vector<int>final_ans;
        for(int i=0;i<n;i++){
            final_ans.push_back(pos[i]);
            final_ans.push_back(neg[i]);
        }

        return final_ans;
    }
};