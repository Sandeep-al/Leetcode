class Solution {
public:
    int n;
    vector<int>nums;
    int score(int idx1,int idx2,int parity){
        if(idx1>idx2){
            return 0;
        }
        int maxi=0;
        if(parity==0){
            maxi=max(maxi,nums[idx1]+score(idx1+1,idx2,1));
            maxi=max(maxi,nums[idx2]+score(idx1,idx2-1,1));
        }
        else{
            int left=score(idx1+1,idx2,0);
            int right=score(idx1,idx2-1,0);

            maxi=min(left,right);
        }

        return maxi;

    }
    bool predictTheWinner(vector<int>& nums) {
        
        n=nums.size();
        this->nums=nums;
        double total=0;
        for(auto &it:nums){
            total+=it;
        }
        total=total/2;
        return score(0,n-1,0)>=total;
    }
};