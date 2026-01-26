class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> final_ans;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == mini) {
                final_ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return final_ans;
    }
};