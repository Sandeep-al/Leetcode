class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>diff(52,0);
        for(auto &it:ranges){
            diff[it[0]]++;
            diff[it[1]+1]--;
        }

        for(int i=1;i<52;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=left;i<=right;i++){
            if(diff[i]==0) return false;
        }
        return true;
    }
};