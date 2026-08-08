class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {

            int curr_end = intervals[i][1];
            int curr_start = intervals[i][0];

            if (curr_start <= curr[1]) {
                curr[1] = max(curr_end,curr[1]);
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};