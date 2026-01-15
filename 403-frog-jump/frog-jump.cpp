class Solution {
public:
    unordered_map<int, int> mpp;
    bool jump(vector<int>& stones, int idx, int lastjump,vector<vector<int>>&dp ) {

        if (idx == stones.size() - 1) {
            return true;
        }
        if(dp[idx][lastjump]!=-1){
            return dp[idx][lastjump];
        }
        int jump1 = 0;
        int steps = lastjump - 1;
        int target_val = stones[idx] + steps;
        if (steps > 0 && mpp.find(target_val) != mpp.end()) {
            jump1 = jump(stones, mpp[target_val], steps,dp);
        }

        int jump2 = 0;
        steps = lastjump;
        target_val = stones[idx] + steps;
        if (steps > 0 && mpp.find(target_val) != mpp.end()) {
            jump2 = jump(stones, mpp[target_val], steps,dp);
        }

        int jump3 = 0;
        steps = lastjump + 1;
        target_val = stones[idx] + steps;
        if (steps > 0 && mpp.find(target_val) != mpp.end()) {
            jump3 = jump(stones, mpp[target_val], steps,dp);
        }

        return dp[idx][lastjump]=jump1 || jump2 || jump3;
    }
    bool canCross(vector<int>& stones) {

        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for (int i = 0; i < stones.size(); i++) {
            mpp[stones[i]] = i;
        }

        if(mpp.find(stones[0]+1)!=mpp.end()){
            return jump(stones,1,1,dp);
        }

        return false;
    }
};