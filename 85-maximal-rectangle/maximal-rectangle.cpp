class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right_smaller(n, n);
        vector<int> left_smaller(n, -1);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (!st.empty() && curr < heights[st.top()]) {
                right_smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (!st.empty() && curr < heights[st.top()]) {
                left_smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int curr = right_smaller[i] - left_smaller[i] - 1;
            maxi = max(maxi, curr * heights[i]);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> curr(n, 0);
        int maxi = 0;
        for (int i = m - 1; i >= 0; i--) {

            for (int j = 0; j < n; j++) {
                int prev = curr[i];
                if (matrix[i][j] == '0') {
                    curr[j] = 0;
                } else {
                    curr[j] += 1;
                }
            }

            maxi = max(maxi, largestRectangleArea(curr));
        }

        return maxi;
    }
};