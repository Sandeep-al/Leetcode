class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();
        vector<int> prefix(1005, 0);

        for (auto& it : trips) {
            prefix[it[1]] += it[0];
            prefix[it[2]] -= it[0];
        }
        for(int i=1;i<1005;i++){
            prefix[i]+=prefix[i-1];
        }
        for (int i = 0; i < 1005; i++) {
            if (prefix[i] > capacity) {
                return 0;
            }
        }

        return 1;
    }
};