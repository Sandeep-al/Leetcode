class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>diff(102, 0);

        for (auto& it : nums) {
            diff[it[0]]++;
            diff[it[1] + 1]--;
        }

        for (int i = 1; i < 101; i++) {
            diff[i] += diff[i - 1];
        }

        int sum = 0;
        for (int i = 0; i < 101; i++) {
            if (diff[i] > 0)
                sum++;
        }
        return sum;
    }
};