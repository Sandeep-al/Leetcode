class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    vector<int> arr1;
    vector<int> arr2;
    int solve(int i, int j) {

        if (i == m || j == n) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // match case
        int take = INT_MIN;
        if (arr1[i] == arr2[j]) {
            take = 1 + solve(i + 1, j + 1);
        }

        int nottake = max(solve(i + 1, j), solve(i, j + 1));

        return dp[i][j] = max(take, nottake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        arr1 = nums1;
        arr2 = nums2;
        dp.assign(m + 1, vector<int>(n, -1));

        return solve(0,0);
    }
};