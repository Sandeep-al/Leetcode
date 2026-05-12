class Solution {
public:
    vector < vector<int>> tasks;
    bool can_we_complete(int start) {

        for (int i = 0; i < tasks.size(); i++) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if (start >= minimum) {
                start -= actual;
            } else {
                return false;
            }
        }

        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) { return a[1]-a[0] > b[1]-b[0]; });
        this->tasks = tasks;
        int mini = 1;
        int maxi = 0;
        for (auto& it : tasks) {
            maxi += it[1];
        }
        int final_ans = maxi;

        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;

            if (can_we_complete(mid)) {
                maxi = mid - 1;
                final_ans = mid;
            } else {
                mini = mid + 1;
            }
        }

        return final_ans;
    }
};