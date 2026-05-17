class Solution {
public:
    int bs(vector<pair<int,int>>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid].first >= target) {
                ans = arr[mid].second;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start;
        for (int i = 0; i < n; i++) {
            start.push_back({intervals[i][0], i});
        }
        sort(start.begin(),start.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            ans.push_back(bs(start, target));
        }

        return ans;
    }
};