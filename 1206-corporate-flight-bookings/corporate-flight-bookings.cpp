class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);
        for(auto &it:bookings){
            diff[it[0]-1]+=it[2];
            diff[it[1]]-=it[2];
        }
        for(int i=1;i<n+1;i++){
            diff[i]+=diff[i-1];
        }

        diff.pop_back();
        
        return diff;
    }
};