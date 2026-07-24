class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(102, 0);

        for (auto& it : logs) {
            int l = it[0] - 1950;
            int r = it[1] - 1950-1;

            diff[l]++;
            diff[r + 1]--;
        }

        for (int i = 1; i < 102; i++) {
            diff[i] += diff[i - 1];
        }

        int maxi = 0;
        for (auto& it : diff) {
            maxi = max(maxi, it);
        }

        for (int i = 0; i < 102; i++) {
            if (diff[i] == maxi) {
                return i + 1950;
            }
        }

        return -1;
    }
};