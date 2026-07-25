class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001,0);
        for(auto &it:trips){
            int numpassenger=it[0];
            int from=it[1];
            int to=it[2];

            diff[from]+=numpassenger;
            diff[to]-=numpassenger;
        }

        for(int i=1;i<1001;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<1001;i++){
            if(diff[i]>capacity){
                return false;
            }
        }

        return true;

    }
};